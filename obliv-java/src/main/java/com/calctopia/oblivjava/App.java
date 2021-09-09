/*
 * Copyright (c) 2021 Calctopia and/or its affiliates. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 only, as
 * published by the Free Software Foundation.  Oracle designates this
 * particular file as subject to the "Classpath" exception as provided
 * by Oracle in the LICENSE file that accompanied this code.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * You should have received a copy of the GNU General Public License version
 * 2 along with this work; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 */

package com.calctopia.oblivjava;

import com.github.javaparser.JavaParser;
import com.github.javaparser.ast.CompilationUnit;
import com.github.javaparser.ast.body.MethodDeclaration;
import com.github.javaparser.ast.visitor.VoidVisitorAdapter;
import com.github.javaparser.ast.expr.BinaryExpr;
import com.github.javaparser.ast.stmt.IfStmt;
import com.github.javaparser.ast.stmt.Statement;
import com.github.javaparser.ast.visitor.ModifierVisitor;
import com.github.javaparser.ast.visitor.Visitable;
import com.github.javaparser.utils.CodeGenerationUtils;
import com.github.javaparser.utils.SourceRoot;
import com.github.javaparser.ast.stmt.BlockStmt;
import com.github.javaparser.ast.body.ClassOrInterfaceDeclaration;
import com.github.javaparser.ast.Modifier;
import com.github.javaparser.symbolsolver.javaparsermodel.JavaParserFacade;
import com.github.javaparser.symbolsolver.resolution.typesolvers.ReflectionTypeSolver;
import com.github.javaparser.symbolsolver.model.resolution.TypeSolver;
import com.github.javaparser.resolution.types.ResolvedType;
import com.github.javaparser.resolution.types.ResolvedPrimitiveType;
import com.github.javaparser.ast.expr.AssignExpr;
import com.github.javaparser.ast.expr.NameExpr;
import com.github.javaparser.ast.expr.Name;
import com.github.javaparser.ast.stmt.ExpressionStmt;
import com.github.javaparser.ast.expr.Expression;
import com.github.javaparser.ast.Node;
import com.github.javaparser.ast.expr.FieldAccessExpr;
import com.github.javaparser.ast.expr.MethodCallExpr;
import com.github.javaparser.ast.expr.StringLiteralExpr;
import com.github.javaparser.ast.expr.SingleMemberAnnotationExpr;
import com.github.javaparser.ast.body.FieldDeclaration;
import com.github.javaparser.ast.expr.IntegerLiteralExpr;

import java.io.FileInputStream;
import java.io.File;
import java.util.ArrayList;
import java.util.List;
import java.util.regex.Pattern;

public class App {

    private static final String TEST_FILE_PATH = "src/main/java/com/calctopia/oblivjava/ClassIf.java";

    public static void main(String[] args) throws Exception {

	String file = TEST_FILE_PATH;

	if (args.length > 1 && args[0] != null) {
		if ((new File(args[0])).exists()) {
			file = args[0];
		}
	}

        CompilationUnit cu = JavaParser.parse(new FileInputStream(file));

	cu.accept(new IfVisitor(), cu);

        System.out.println(cu.toString());
    }

    public static class IfVisitor extends ModifierVisitor<CompilationUnit> {
	    private static int addVariables = 0;

	    private String getNextVar() {
		addVariables++;
		return "_varObliv_" + addVariables;
	    }

	    private static SingleMemberAnnotationExpr annoObliv0 = new SingleMemberAnnotationExpr(new Name("Obliv"), new IntegerLiteralExpr(0));

	    Class getClassOfNode(Node n) {
                   // get type of the variables of the condition
                   TypeSolver typeSolver = new ReflectionTypeSolver();
                   ResolvedPrimitiveType typeOfTheNode = JavaParserFacade.get(typeSolver).getType(n, true).asPrimitive();

                   Class typeClass = null;
                   switch(typeOfTheNode) {
                        case INT:
                                typeClass = int.class;
                                break;
                        case BYTE:
                                typeClass = byte.class;
                                break;
                        case SHORT:
                                typeClass = short.class;
                                break;
                        case CHAR:
                                typeClass = char.class;
                                break;
                        case LONG:
                                typeClass = long.class;
                                break;
                        case BOOLEAN:
                                typeClass = boolean.class;
                                break;
                        case FLOAT:
                                typeClass = float.class;
                                break;
                        case DOUBLE:
                                typeClass = double.class;
                                break;
                   }

		return typeClass;
	    }

	    private void TransformAssignExpr(AssignExpr assignExpr, ClassOrInterfaceDeclaration _cls, BlockStmt blockstmt, BinaryExpr binaryExpr, String strleft, String strright, String strcond) {
               Expression target = assignExpr.getTarget();
               BinaryExpr beValue = (BinaryExpr) assignExpr.getValue();

               String newVar = getNextVar();
               _cls.addField(getClassOfNode(target), newVar, Modifier.PUBLIC, Modifier.STATIC).addAnnotation(annoObliv0);

               if (beValue.getLeft().equals(binaryExpr.getRight()))
                beValue.getLeft().replace(new NameExpr(strright));
               else if (beValue.getLeft().equals(binaryExpr.getLeft()))
               	beValue.getLeft().replace(new NameExpr(strleft));

               if (beValue.getRight().equals(binaryExpr.getRight()))
                beValue.getRight().replace(new NameExpr(strright));
               else if (beValue.getRight().equals(binaryExpr.getLeft()))
                beValue.getRight().replace(new NameExpr(strleft));

                blockstmt.addStatement(new AssignExpr(new NameExpr(newVar), beValue, AssignExpr.Operator.ASSIGN));
                FieldAccessExpr dotClass = new FieldAccessExpr(_cls.getNameAsExpression(), "class");
                MethodCallExpr getField = new MethodCallExpr(dotClass, "getField");
                getField.addArgument(new StringLiteralExpr(target.toString()));
                MethodCallExpr condAssign = new MethodCallExpr(getField, "condAssign");
		condAssign.addArgument(dotClass);
		condAssign.addArgument(new MethodCallExpr(dotClass, "getField").addArgument(new StringLiteralExpr(strcond)));
		condAssign.addArgument(new MethodCallExpr(dotClass, "getField").addArgument(new StringLiteralExpr(newVar)));

		blockstmt.addStatement(condAssign);
	    }

            private void TransformAssignExpr(AssignExpr assignExpr, ClassOrInterfaceDeclaration _cls, BlockStmt blockstmt, NameExpr nameExpr, String strcopy, String strcond) {
               Expression target = assignExpr.getTarget();
               BinaryExpr beValue = (BinaryExpr) assignExpr.getValue();

               String newVar = getNextVar();
               _cls.addField(getClassOfNode(target), newVar, Modifier.PUBLIC, Modifier.STATIC).addAnnotation(annoObliv0);

               if (beValue.getLeft().equals(nameExpr))
                beValue.getLeft().replace(new NameExpr(strcopy));

               if (beValue.getRight().equals(nameExpr))
                beValue.getRight().replace(new NameExpr(strcopy));

                blockstmt.addStatement(new AssignExpr(new NameExpr(newVar), beValue, AssignExpr.Operator.ASSIGN));
                FieldAccessExpr dotClass = new FieldAccessExpr(_cls.getNameAsExpression(), "class");
                MethodCallExpr getField = new MethodCallExpr(dotClass, "getField");
                getField.addArgument(new StringLiteralExpr(target.toString()));
                MethodCallExpr condAssign = new MethodCallExpr(getField, "condAssign");
                condAssign.addArgument(dotClass);
                condAssign.addArgument(new MethodCallExpr(dotClass, "getField").addArgument(new StringLiteralExpr(strcond)));
                condAssign.addArgument(new MethodCallExpr(dotClass, "getField").addArgument(new StringLiteralExpr(newVar)));

                blockstmt.addStatement(condAssign);
            }

            @Override
            public Visitable visit(IfStmt n, CompilationUnit cu) {
		n.getCondition().ifNameExpr(nameExpr -> {
                   // get parent class that contains the IfStmt
                   ClassOrInterfaceDeclaration _cls = n.findParent(ClassOrInterfaceDeclaration.class).get();

                   //Check that the fields have the Obliv annotation
                   if (!_cls.getFieldByName(nameExpr.getName().toString()).get().isAnnotationPresent("Obliv")) 
                           return;

                   // Get the annotations
                   SingleMemberAnnotationExpr annotation;
                   if (_cls.getFieldByName(nameExpr.getName().toString()).get().getAnnotationByName("Obliv").get().getMetaModel().getTypeName().equals("SingleMemberAnnotationExpr")) {
                        annotation = (SingleMemberAnnotationExpr) _cls.getFieldByName(nameExpr.getName().toString()).get().getAnnotationByName("Obliv").get();
                   } else return;

                   Class typeClass = getClassOfNode(nameExpr);

                   String comp, _then, _else, leftRight_cond, leftRight_cond_then, leftRight_cond_else ="";
                   //String strTrue = "true";
		   String strTrue = "Obliv.trueCond";

                   //define variables
                   comp = getNextVar();
                   _cls.addField(typeClass, comp, Modifier.PUBLIC, Modifier.STATIC).addAnnotation(annotation);
                   _then = getNextVar();
                   _cls.addField(typeClass, _then, Modifier.PUBLIC, Modifier.STATIC).addAnnotation(annotation);
                   _else = getNextVar();
                   _cls.addField(typeClass, _else, Modifier.PUBLIC, Modifier.STATIC).addAnnotation(annotation);
                   leftRight_cond = getNextVar();
                   _cls.addField(boolean.class, leftRight_cond, Modifier.PUBLIC, Modifier.STATIC).addAnnotation(annoObliv0);
                   leftRight_cond_then = getNextVar();
                   _cls.addField(boolean.class, leftRight_cond_then, Modifier.PUBLIC, Modifier.STATIC).addAnnotation(annoObliv0);
                   if (n.hasElseBranch()) {
                        leftRight_cond_else = getNextVar();
                        _cls.addField(boolean.class, leftRight_cond_else, Modifier.PUBLIC, Modifier.STATIC).addAnnotation(annoObliv0);
                   }

                   // Create block statement to replace the if
                   BlockStmt block = new BlockStmt();
                   block.addStatement(new AssignExpr(new NameExpr(comp), new NameExpr(nameExpr.getName().toString()), AssignExpr.Operator.ASSIGN));
                   block.addStatement(new AssignExpr(new NameExpr(_then), new NameExpr(nameExpr.getName().toString()), AssignExpr.Operator.ASSIGN));
                   block.addStatement(new AssignExpr(new NameExpr(_else), new NameExpr(nameExpr.getName().toString()), AssignExpr.Operator.ASSIGN));
                   block.addStatement(new AssignExpr(new NameExpr(leftRight_cond), new NameExpr(comp), AssignExpr.Operator.ASSIGN));
                   block.addStatement(new AssignExpr(new NameExpr(leftRight_cond_then), new BinaryExpr(new NameExpr(leftRight_cond), new NameExpr(strTrue), BinaryExpr.Operator.BINARY_AND), AssignExpr.Operator.ASSIGN));
                   if (n.hasElseBranch()) {
                        block.addStatement(new AssignExpr(new NameExpr(leftRight_cond_else), new BinaryExpr(new NameExpr(leftRight_cond_then), new NameExpr(strTrue), BinaryExpr.Operator.NOT_EQUALS), AssignExpr.Operator.ASSIGN));
                   }

                   //Transform then statement
                   BlockStmt blockThen = new BlockStmt();
                   Statement thenStmt = n.getThenStmt();
                   if (thenStmt.isExpressionStmt()) {
                        ExpressionStmt es = thenStmt.toExpressionStmt().get();
                        AssignExpr assignExpr = (AssignExpr) es.getExpression();
                        TransformAssignExpr(assignExpr, _cls, blockThen, nameExpr, _then, leftRight_cond_then);
                   } else if (thenStmt.isBlockStmt()) {
                        BlockStmt bs = thenStmt.toBlockStmt().get();
                        for (int i = 0; i < bs.getStatements().size(); i++) {
                                if (bs.getStatements().get(i).isExpressionStmt()) {
                                        ExpressionStmt es = bs.getStatements().get(i).toExpressionStmt().get();
                                        AssignExpr assignExpr = (AssignExpr) es.getExpression();
                                        TransformAssignExpr(assignExpr, _cls, blockThen, nameExpr, _then, leftRight_cond_then);
                                } else
                                        blockThen.addStatement(bs.getStatements().get(i));
                        }
                   } else
                        blockThen.addStatement(thenStmt);

                   block.addStatement(blockThen);

                   //Transform else statement
                   if (n.hasElseBranch()) {
                        BlockStmt blockElse = new BlockStmt();
                        Statement elseStmt = n.getElseStmt().get();
                        if (elseStmt.isExpressionStmt()) {
                                ExpressionStmt es = elseStmt.toExpressionStmt().get();
                                AssignExpr assignExpr = (AssignExpr) es.getExpression();
                                TransformAssignExpr(assignExpr, _cls, blockElse, nameExpr, _else, leftRight_cond_else);
                        } else if (elseStmt.isBlockStmt()) {
                                BlockStmt bs = elseStmt.toBlockStmt().get();
                                for (int i = 0; i < bs.getStatements().size(); i++) {
                                        if (bs.getStatements().get(i).isExpressionStmt()) {
                                                ExpressionStmt es = bs.getStatements().get(i).toExpressionStmt().get();
                                                AssignExpr assignExpr = (AssignExpr) es.getExpression();
                                                TransformAssignExpr(assignExpr, _cls, blockElse, nameExpr, _else, leftRight_cond_else);
                                        } else
                                                blockElse.addStatement(bs.getStatements().get(i));
                                }
                        } else
                                blockElse.addStatement(elseStmt);

                        block.addStatement(blockElse);
                   }

                   // Rewrite if
                   n.replace(block);

		});
                n.getCondition().ifBinaryExpr(binaryExpr -> {

		   // get parent class that contains the IfStmt
		   ClassOrInterfaceDeclaration _cls = n.findParent(ClassOrInterfaceDeclaration.class).get();

		   //Check that the fields have the Obliv annotation
		   if (!(_cls.getFieldByName(binaryExpr.getLeft().toString()).get().isAnnotationPresent("Obliv") &&
		         _cls.getFieldByName(binaryExpr.getRight().toString()).get().isAnnotationPresent("Obliv")))
			   return;

		   // Get the annotations
		   SingleMemberAnnotationExpr annotationLeft, annotationRight = null;
		   if (_cls.getFieldByName(binaryExpr.getLeft().toString()).get().getAnnotationByName("Obliv").get().getMetaModel().getTypeName().equals("SingleMemberAnnotationExpr")) {
			annotationLeft = (SingleMemberAnnotationExpr) _cls.getFieldByName(binaryExpr.getLeft().toString()).get().getAnnotationByName("Obliv").get();
		   } else return;

                   if (_cls.getFieldByName(binaryExpr.getRight().toString()).get().getAnnotationByName("Obliv").get().getMetaModel().getTypeName().equals("SingleMemberAnnotationExpr")) {
                        annotationRight = (SingleMemberAnnotationExpr) _cls.getFieldByName(binaryExpr.getRight().toString()).get().getAnnotationByName("Obliv").get();
                   } else return;

		   Class typeClassLeft = getClassOfNode(binaryExpr.getLeft());
		   Class typeClassRight = getClassOfNode(binaryExpr.getRight());

		   String left_comp, right_comp, left_then, right_then, left_else, right_else, leftRight_cond, leftRight_cond_then, leftRight_cond_else ="";
		   String strTrue = "Obliv.trueCond";

	           //define variables
		   left_comp = getNextVar();
		   _cls.addField(typeClassLeft, left_comp, Modifier.PUBLIC, Modifier.STATIC).addAnnotation(annotationLeft);
		   right_comp = getNextVar();
                   _cls.addField(typeClassRight, right_comp, Modifier.PUBLIC, Modifier.STATIC).addAnnotation(annotationRight);
                   left_then = getNextVar();
                   _cls.addField(typeClassLeft, left_then, Modifier.PUBLIC, Modifier.STATIC).addAnnotation(annotationLeft);
                   right_then = getNextVar();
                   _cls.addField(typeClassRight, right_then, Modifier.PUBLIC, Modifier.STATIC).addAnnotation(annotationRight);
                   left_else = getNextVar();
                   _cls.addField(typeClassLeft, left_else, Modifier.PUBLIC, Modifier.STATIC).addAnnotation(annotationLeft);
                   right_else = getNextVar();
                   _cls.addField(typeClassRight, right_else, Modifier.PUBLIC, Modifier.STATIC).addAnnotation(annotationRight);
                   leftRight_cond = getNextVar();
                   _cls.addField(boolean.class, leftRight_cond, Modifier.PUBLIC, Modifier.STATIC).addAnnotation(annoObliv0);
                   leftRight_cond_then = getNextVar();
                   _cls.addField(boolean.class, leftRight_cond_then, Modifier.PUBLIC, Modifier.STATIC).addAnnotation(annoObliv0);
		   if (n.hasElseBranch()) {
                   	leftRight_cond_else = getNextVar();
                   	_cls.addField(boolean.class, leftRight_cond_else, Modifier.PUBLIC, Modifier.STATIC).addAnnotation(annoObliv0);
		   }

		   // Create block statement to replace the if
                   BlockStmt block = new BlockStmt();
		   block.addStatement(new AssignExpr(new NameExpr(left_comp), new NameExpr(binaryExpr.getLeft().toString()), AssignExpr.Operator.ASSIGN));
		   block.addStatement(new AssignExpr(new NameExpr(right_comp), new NameExpr(binaryExpr.getRight().toString()), AssignExpr.Operator.ASSIGN));
		   block.addStatement(new AssignExpr(new NameExpr(left_then), new NameExpr(binaryExpr.getLeft().toString()), AssignExpr.Operator.ASSIGN));
		   block.addStatement(new AssignExpr(new NameExpr(right_then), new NameExpr(binaryExpr.getRight().toString()), AssignExpr.Operator.ASSIGN));
		   block.addStatement(new AssignExpr(new NameExpr(left_else), new NameExpr(binaryExpr.getLeft().toString()), AssignExpr.Operator.ASSIGN));
		   block.addStatement(new AssignExpr(new NameExpr(right_else), new NameExpr(binaryExpr.getRight().toString()), AssignExpr.Operator.ASSIGN));
		   block.addStatement(new AssignExpr(new NameExpr(leftRight_cond), new BinaryExpr(new NameExpr(left_comp), new NameExpr(right_comp), binaryExpr.getOperator()), AssignExpr.Operator.ASSIGN));
		   block.addStatement(new AssignExpr(new NameExpr(leftRight_cond_then), new BinaryExpr(new NameExpr(leftRight_cond), new NameExpr(strTrue), BinaryExpr.Operator.BINARY_AND), AssignExpr.Operator.ASSIGN));
		   if (n.hasElseBranch()) {
                   	block.addStatement(new AssignExpr(new NameExpr(leftRight_cond_else), new BinaryExpr(new NameExpr(leftRight_cond_then), new NameExpr(strTrue), BinaryExpr.Operator.NOT_EQUALS), AssignExpr.Operator.ASSIGN));
		   }

		   //Transform then statement
		   BlockStmt blockThen = new BlockStmt();
		   Statement thenStmt = n.getThenStmt();
		   if (thenStmt.isExpressionStmt()) {
			ExpressionStmt es = thenStmt.toExpressionStmt().get();
			AssignExpr assignExpr = (AssignExpr) es.getExpression();
			TransformAssignExpr(assignExpr, _cls, blockThen, binaryExpr, left_then, right_then, leftRight_cond_then);
		   } else if (thenStmt.isBlockStmt()) {
			BlockStmt bs = thenStmt.toBlockStmt().get();
		        for (int i = 0; i < bs.getStatements().size(); i++) {
				if (bs.getStatements().get(i).isExpressionStmt()) {
        	                	ExpressionStmt es = bs.getStatements().get(i).toExpressionStmt().get();
                	        	AssignExpr assignExpr = (AssignExpr) es.getExpression();
                        		TransformAssignExpr(assignExpr, _cls, blockThen, binaryExpr, left_then, right_then, leftRight_cond_then);
				} else
					blockThen.addStatement(bs.getStatements().get(i));
			}
		   } else 
			blockThen.addStatement(thenStmt);

                   block.addStatement(blockThen);

		   //Transform else statement
		   if (n.hasElseBranch()) {
		   	BlockStmt blockElse = new BlockStmt();
			Statement elseStmt = n.getElseStmt().get();
			if (elseStmt.isExpressionStmt()) {
				ExpressionStmt es = elseStmt.toExpressionStmt().get();
				AssignExpr assignExpr = (AssignExpr) es.getExpression();
				TransformAssignExpr(assignExpr, _cls, blockElse, binaryExpr, left_else, right_else, leftRight_cond_else);
			} else if (elseStmt.isBlockStmt()) {
                        	BlockStmt bs = elseStmt.toBlockStmt().get();
                        	for (int i = 0; i < bs.getStatements().size(); i++) {
					if (bs.getStatements().get(i).isExpressionStmt()) {
                                		ExpressionStmt es = bs.getStatements().get(i).toExpressionStmt().get();
                                		AssignExpr assignExpr = (AssignExpr) es.getExpression();
                                		TransformAssignExpr(assignExpr, _cls, blockElse, binaryExpr, left_else, right_else, leftRight_cond_else);
					} else
						blockElse.addStatement(bs.getStatements().get(i));
                        	}
			} else
				blockElse.addStatement(elseStmt);

		   	block.addStatement(blockElse);
		   }

		   // Rewrite if
                   n.replace(block);
                });
                return super.visit(n, cu);
            }
    }
}
