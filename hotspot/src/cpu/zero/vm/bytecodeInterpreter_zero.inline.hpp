/*
 * Copyright (c) 2021 Calctopia and/or its affiliates. All rights reserved.
 * Copyright (c) 2002, 2010, Oracle and/or its affiliates. All rights reserved.
 * Copyright 2007, 2010 Red Hat, Inc.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 only, as
 * published by the Free Software Foundation.
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
 * Please contact Oracle, 500 Oracle Parkway, Redwood Shores, CA 94065 USA
 * or visit www.oracle.com if you need additional information or have any
 * questions.
 *
 */

#ifndef CPU_ZERO_VM_BYTECODEINTERPRETER_ZERO_INLINE_HPP
#define CPU_ZERO_VM_BYTECODEINTERPRETER_ZERO_INLINE_HPP

#include <obliv.h>
#include <oblivoh.h>

typedef class BytecodeInterpreter* interpreterState;

#define DEFAULTINTRETURNVALUE 1
#define DEFAULTLONGRETURNVALUE 1UL
#define DEFAULTFLOATRETURNVALUE 1.0f
#define DEFAULTDOUBLERETURNVALUE 1.0

#define DEFAULTCHARRETURNVALUE 1
#define DEFAULTSHORTRETURNVALUE 1
#define DEFAULTBYTERETURNVALUE 1

#define DEFAULTCOMPARERETURNVALUE 1

// Inline interpreter functions for zero

inline jfloat BytecodeInterpreter::VMfloatAdd(jfloat op1, jfloat op2) {
  return op1 + op2;
}

inline jfloat BytecodeInterpreter::VMObliviousFloatAdd(intptr_t* topOfStack, GrowableArray<OblivContainer>* oblivStack) {

  SET_STACK_OBLIVIOUS_POSITION(0, STACK_SLOT(-1));
  ofloat32 oop2 = oblivStack->pop().getObliv().getFloat();
  SET_STACK_OBLIVIOUS_POSITION(0, STACK_SLOT(-2));
  ofloat32 oop1 = oblivStack->pop().getObliv().getFloat();

  ofloat32 dest;
  memset((void *)(& dest), 0, sizeof(ofloat32));
  __obliv_c__setSignedKnown(&dest, 32UL, (widest_t )((unsigned int )0));

  obliv_float_add_circuit((OblivBit*) &dest, (OblivBit*)&oop1, (OblivBit*)&oop2);

  Obliv newOblivVal(dest, 0, Obliv::FLOAT);
  oblivStack->push(OblivContainer(newOblivVal));
  SET_STACK_OBLIVIOUS_POSITION(oblivStack->length()-1, STACK_SLOT(-2));

  return (jfloat) DEFAULTFLOATRETURNVALUE;
}

inline jfloat BytecodeInterpreter::VMfloatSub(jfloat op1, jfloat op2) {
  return op1 - op2;
}

inline jfloat BytecodeInterpreter::VMObliviousFloatSub(intptr_t* topOfStack, GrowableArray<OblivContainer>* oblivStack) {

  SET_STACK_OBLIVIOUS_POSITION(-1, STACK_SLOT(-1));
  ofloat32 oop2 = oblivStack->pop().getObliv().getFloat();
  SET_STACK_OBLIVIOUS_POSITION(-1, STACK_SLOT(-2));
  ofloat32 oop1 = oblivStack->pop().getObliv().getFloat();

  ofloat32 dest;
  memset((void *)(& dest), 0, sizeof(ofloat32));
  __obliv_c__setSignedKnown(&dest, 32UL, (widest_t )((unsigned int )0));

  obliv_float_sub_circuit((OblivBit*) &dest, (OblivBit*)&oop1, (OblivBit*)&oop2);

  Obliv newOblivVal(dest, 0, Obliv::FLOAT);
  oblivStack->push(OblivContainer(newOblivVal));
  SET_STACK_OBLIVIOUS_POSITION(oblivStack->length()-1, STACK_SLOT(-2));

  return (jfloat) DEFAULTFLOATRETURNVALUE;
}

inline jfloat BytecodeInterpreter::VMfloatMul(jfloat op1, jfloat op2) {
  return op1 * op2;
}

inline jfloat BytecodeInterpreter::VMObliviousFloatMul(intptr_t* topOfStack, GrowableArray<OblivContainer>* oblivStack) {

  SET_STACK_OBLIVIOUS_POSITION(-1, STACK_SLOT(-1));
  ofloat32 oop2 = oblivStack->pop().getObliv().getFloat();
  SET_STACK_OBLIVIOUS_POSITION(-1, STACK_SLOT(-2));
  ofloat32 oop1 = oblivStack->pop().getObliv().getFloat();

  ofloat32 dest;
  memset((void *)(& dest), 0, sizeof(ofloat32));
  __obliv_c__setSignedKnown(&dest, 32UL, (widest_t )((unsigned int )0));

  obliv_float_mult_circuit((OblivBit*) &dest, (OblivBit*)&oop1, (OblivBit*)&oop2);

  Obliv newOblivVal(dest, 0, Obliv::FLOAT);
  oblivStack->push(OblivContainer(newOblivVal));
  SET_STACK_OBLIVIOUS_POSITION(oblivStack->length()-1, STACK_SLOT(-2));

  return (jfloat) DEFAULTFLOATRETURNVALUE;
}

inline jfloat BytecodeInterpreter::VMfloatDiv(jfloat op1, jfloat op2) {
  return op1 / op2;
}

inline jfloat BytecodeInterpreter::VMObliviousFloatDiv(intptr_t* topOfStack, GrowableArray<OblivContainer>* oblivStack) {

  SET_STACK_OBLIVIOUS_POSITION(-1, STACK_SLOT(-1));
  ofloat32 oop2 = oblivStack->pop().getObliv().getFloat();
  SET_STACK_OBLIVIOUS_POSITION(-1, STACK_SLOT(-2));
  ofloat32 oop1 = oblivStack->pop().getObliv().getFloat();

  ofloat32 dest;
  memset((void *)(& dest), 0, sizeof(ofloat32));
  __obliv_c__setSignedKnown(&dest, 32UL, (widest_t )((unsigned int )0));

  obliv_float_div_circuit((OblivBit*) &dest, (OblivBit*)&oop1, (OblivBit*)&oop2);

  Obliv newOblivVal(dest, 0, Obliv::FLOAT);
  oblivStack->push(OblivContainer(newOblivVal));
  SET_STACK_OBLIVIOUS_POSITION(oblivStack->length()-1, STACK_SLOT(-2));

  return (jfloat) DEFAULTFLOATRETURNVALUE;
}

inline jfloat BytecodeInterpreter::VMfloatRem(jfloat op1, jfloat op2) {
  return fmod(op1, op2);
}

inline jfloat BytecodeInterpreter::VMObliviousFloatRem(intptr_t* topOfStack, GrowableArray<OblivContainer>* oblivStack) {

  SET_STACK_OBLIVIOUS_POSITION(-1, STACK_SLOT(-1));
  ofloat32 oop2 = oblivStack->pop().getObliv().getFloat();
  SET_STACK_OBLIVIOUS_POSITION(-1, STACK_SLOT(-2));
  ofloat32 oop1 = oblivStack->pop().getObliv().getFloat();

  ofloat32 dest = float32_rem(&__obliv_c__trueCond, oop1, oop2);

  Obliv newOblivVal(dest, 0, Obliv::FLOAT);
  oblivStack->push(OblivContainer(newOblivVal));
  SET_STACK_OBLIVIOUS_POSITION(oblivStack->length()-1, STACK_SLOT(-2));

  return (jfloat) DEFAULTFLOATRETURNVALUE;
}

inline jfloat BytecodeInterpreter::VMfloatNeg(jfloat op) {
  return -op;
}

inline jfloat BytecodeInterpreter::VMObliviousFloatNeg(intptr_t* topOfStack, GrowableArray<OblivContainer>* oblivStack) {

  SET_STACK_OBLIVIOUS_POSITION(-1, STACK_SLOT(-1));
  ofloat32 oop1 = oblivStack->pop().getObliv().getFloat();

  ofloat32 dest = float32_neg(&__obliv_c__trueCond, oop1);

  Obliv newOblivVal(dest, 0, Obliv::FLOAT);
  oblivStack->push(OblivContainer(newOblivVal));
  SET_STACK_OBLIVIOUS_POSITION(oblivStack->length()-1, STACK_SLOT(-1));

  return (jfloat) DEFAULTFLOATRETURNVALUE;
}

inline int32_t BytecodeInterpreter::VMfloatCompare(jfloat  op1,
                                                   jfloat  op2,
                                                   int32_t direction) {
  return ( op1 < op2 ? -1 :
               op1 > op2 ? 1 :
                   op1 == op2 ? 0 :
                       (direction == -1 || direction == 1) ? direction : 0);

}

inline int32_t BytecodeInterpreter::VMObliviousFloatCompare(intptr_t* topOfStack, GrowableArray<OblivContainer>* oblivStack, int32_t direction) {

  SET_STACK_OBLIVIOUS_POSITION(-1, STACK_SLOT(-1));
  ofloat32 oop2 = oblivStack->pop().getObliv().getFloat();
  SET_STACK_OBLIVIOUS_POSITION(-1, STACK_SLOT(-2));
  ofloat32 oop1 = oblivStack->pop().getObliv().getFloat();

  oint dest = floatCompare(&__obliv_c__trueCond, oop1, oop2);

  Obliv newOblivVal(dest, 0, Obliv::INT);
  oblivStack->push(OblivContainer(newOblivVal));
  SET_STACK_OBLIVIOUS_POSITION(oblivStack->length()-1, STACK_SLOT(-2));

  return DEFAULTCOMPARERETURNVALUE;
}

inline void BytecodeInterpreter::VMmemCopy64(uint32_t       to[2],
                                             const uint32_t from[2]) {
  *(uint64_t *) to = *(uint64_t *) from;
}

inline jlong BytecodeInterpreter::VMlongAdd(jlong op1, jlong op2) {
  return op1 + op2;
}

inline jlong BytecodeInterpreter::VMObliviousLongAdd(intptr_t* topOfStack, GrowableArray<OblivContainer>* oblivStack) {

  SET_STACK_LONG_OBLIVIOUS_POSITION(-1, STACK_SLOT(-1));
  olong oop2 = oblivStack->pop().getObliv().getLong();
  SET_STACK_LONG_OBLIVIOUS_POSITION(-1, STACK_SLOT(-3));
  olong oop1 = oblivStack->pop().getObliv().getLong();

  olong dest;
  memset((void *)(& dest), 0, sizeof(olong));
  __obliv_c__setSignedKnown(&dest, 64UL, (widest_t )((unsigned long long)0));

  __obliv_c__setPlainAdd((void*)&dest, (const void*)&oop1, (const void*)&oop2, 64UL);

  Obliv newOblivVal(dest, 0, Obliv::LONG);
  oblivStack->push(OblivContainer(newOblivVal));
  SET_STACK_LONG_OBLIVIOUS_POSITION(oblivStack->length()-1, STACK_SLOT(-3));

  return DEFAULTLONGRETURNVALUE;
}

inline jlong BytecodeInterpreter::VMlongAnd(jlong op1, jlong op2) {
  return op1 & op2;
}

inline jlong BytecodeInterpreter::VMObliviousLongAnd(intptr_t* topOfStack, GrowableArray<OblivContainer>* oblivStack) {

  SET_STACK_LONG_OBLIVIOUS_POSITION(-1, STACK_SLOT(-1));
  olong oop2 = oblivStack->pop().getObliv().getLong();
  SET_STACK_LONG_OBLIVIOUS_POSITION(-1, STACK_SLOT(-3));
  olong oop1 = oblivStack->pop().getObliv().getLong();

  olong dest;
  memset((void *)(& dest), 0, sizeof(olong));
  __obliv_c__setSignedKnown(&dest, 64UL, (widest_t )((unsigned long long)0));

  __obliv_c__setBitwiseAnd((void*)&dest, (const void*)&oop1, (const void*)&oop2, 64UL);

  Obliv newOblivVal(dest, 0, Obliv::LONG);
  oblivStack->push(OblivContainer(newOblivVal));
  SET_STACK_LONG_OBLIVIOUS_POSITION(oblivStack->length()-1, STACK_SLOT(-3));

  return DEFAULTLONGRETURNVALUE;
}

inline jlong BytecodeInterpreter::VMlongDiv(jlong op1, jlong op2) {
  /* it's possible we could catch this special case implicitly */
  if (op1 == (jlong) 0x8000000000000000LL && op2 == -1) return op1;
  else return op1 / op2;
}

inline jlong BytecodeInterpreter::VMObliviousLongDiv(intptr_t* topOfStack, GrowableArray<OblivContainer>* oblivStack) {

  SET_STACK_LONG_OBLIVIOUS_POSITION(-1, STACK_SLOT(-1));
  olong oop2 = oblivStack->pop().getObliv().getLong();
  SET_STACK_LONG_OBLIVIOUS_POSITION(-1, STACK_SLOT(-3));
  olong oop1 = oblivStack->pop().getObliv().getLong();

  olong dest;
  memset((void *)(& dest), 0, sizeof(olong));
  __obliv_c__setSignedKnown(&dest, 64UL, (widest_t )((unsigned long long)0));

  __obliv_c__setDivSigned((void*)&dest, (const void*)&oop1, (const void*)&oop2, 64UL);

  Obliv newOblivVal(dest, 0, Obliv::LONG);
  oblivStack->push(OblivContainer(newOblivVal));
  SET_STACK_LONG_OBLIVIOUS_POSITION(oblivStack->length()-1, STACK_SLOT(-3));

  return DEFAULTLONGRETURNVALUE;
}

inline jlong BytecodeInterpreter::VMlongMul(jlong op1, jlong op2) {
  return op1 * op2;
}

inline jlong BytecodeInterpreter::VMObliviousLongMul(intptr_t* topOfStack, GrowableArray<OblivContainer>* oblivStack) {

  SET_STACK_LONG_OBLIVIOUS_POSITION(-1, STACK_SLOT(-1));
  olong oop2 = oblivStack->pop().getObliv().getLong();
  SET_STACK_LONG_OBLIVIOUS_POSITION(-1, STACK_SLOT(-3));
  olong oop1 = oblivStack->pop().getObliv().getLong();

  olong dest;
  memset((void *)(& dest), 0, sizeof(olong));
  __obliv_c__setSignedKnown(&dest, 64UL, (widest_t )((unsigned long long)0));

  __obliv_c__setMul((void*)&dest, (const void*)&oop1, (const void*)&oop2, 64UL);

  Obliv newOblivVal(dest, 0, Obliv::LONG);
  oblivStack->push(OblivContainer(newOblivVal));
  SET_STACK_LONG_OBLIVIOUS_POSITION(oblivStack->length()-1, STACK_SLOT(-3));

  return DEFAULTLONGRETURNVALUE;
}

inline jlong BytecodeInterpreter::VMlongOr(jlong op1, jlong op2) {
  return op1 | op2;
}

inline jlong BytecodeInterpreter::VMObliviousLongOr(intptr_t* topOfStack, GrowableArray<OblivContainer>* oblivStack) {

  SET_STACK_LONG_OBLIVIOUS_POSITION(-1, STACK_SLOT(-1));
  olong oop2 = oblivStack->pop().getObliv().getLong();
  SET_STACK_LONG_OBLIVIOUS_POSITION(-1, STACK_SLOT(-3));
  olong oop1 = oblivStack->pop().getObliv().getLong();

  olong dest;
  memset((void *)(& dest), 0, sizeof(olong));
  __obliv_c__setSignedKnown(&dest, 64UL, (widest_t )((unsigned long long)0));

  __obliv_c__setBitwiseOr((void*)&dest, (const void*)&oop1, (const void*)&oop2, 64UL);

  Obliv newOblivVal(dest, 0, Obliv::LONG);
  oblivStack->push(OblivContainer(newOblivVal));
  SET_STACK_LONG_OBLIVIOUS_POSITION(oblivStack->length()-1, STACK_SLOT(-3));

  return DEFAULTLONGRETURNVALUE;
}

inline jlong BytecodeInterpreter::VMlongSub(jlong op1, jlong op2) {
  return op1 - op2;
}

inline jlong BytecodeInterpreter::VMObliviousLongSub(intptr_t* topOfStack, GrowableArray<OblivContainer>* oblivStack) {

  SET_STACK_LONG_OBLIVIOUS_POSITION(-1, STACK_SLOT(-1));
  olong oop2 = oblivStack->pop().getObliv().getLong();
  SET_STACK_LONG_OBLIVIOUS_POSITION(-1, STACK_SLOT(-3));
  olong oop1 = oblivStack->pop().getObliv().getLong();

  olong dest;
  memset((void *)(& dest), 0, sizeof(olong));
  __obliv_c__setSignedKnown(&dest, 64UL, (widest_t )((unsigned long long)0));

  __obliv_c__setPlainSub((void*)&dest, (const void*)&oop1, (const void*)&oop2, 64UL);

  Obliv newOblivVal(dest, 0, Obliv::LONG);
  oblivStack->push(OblivContainer(newOblivVal));
  SET_STACK_LONG_OBLIVIOUS_POSITION(oblivStack->length()-1, STACK_SLOT(-3));

  return DEFAULTLONGRETURNVALUE;
}

inline jlong BytecodeInterpreter::VMlongXor(jlong op1, jlong op2) {
  return op1 ^ op2;
}

inline jlong BytecodeInterpreter::VMObliviousLongXor(intptr_t* topOfStack, GrowableArray<OblivContainer>* oblivStack) {

  SET_STACK_LONG_OBLIVIOUS_POSITION(-1, STACK_SLOT(-1));
  olong oop2 = oblivStack->pop().getObliv().getLong();
  SET_STACK_LONG_OBLIVIOUS_POSITION(-1, STACK_SLOT(-3));
  olong oop1 = oblivStack->pop().getObliv().getLong();

  olong dest;
  memset((void *)(& dest), 0, sizeof(olong));
  __obliv_c__setSignedKnown(&dest, 64UL, (widest_t )((unsigned long long)0));

  __obliv_c__setBitwiseXor((void*)&dest, (const void*)&oop1, (const void*)&oop2, 64UL);

  Obliv newOblivVal(dest, 0, Obliv::LONG);
  oblivStack->push(OblivContainer(newOblivVal));
  SET_STACK_LONG_OBLIVIOUS_POSITION(oblivStack->length()-1, STACK_SLOT(-3));

  return DEFAULTLONGRETURNVALUE;
}

inline jlong BytecodeInterpreter::VMlongRem(jlong op1, jlong op2) {
  /* it's possible we could catch this special case implicitly */
  if (op1 == (jlong) 0x8000000000000000LL && op2 == -1) return 0;
  else return op1 % op2;
}

inline jlong BytecodeInterpreter::VMObliviousLongRem(intptr_t* topOfStack, GrowableArray<OblivContainer>* oblivStack) {

  SET_STACK_LONG_OBLIVIOUS_POSITION(-1, STACK_SLOT(-1));
  olong oop2 = oblivStack->pop().getObliv().getLong();
  SET_STACK_LONG_OBLIVIOUS_POSITION(-1, STACK_SLOT(-3));
  olong oop1 = oblivStack->pop().getObliv().getLong();

  olong dest;
  memset((void *)(& dest), 0, sizeof(olong));
  __obliv_c__setSignedKnown(&dest, 64UL, (widest_t )((unsigned long long)0));

  __obliv_c__setModSigned((void*)&dest, (const void*)&oop1, (const void*)&oop2, 64UL);

  Obliv newOblivVal(dest, 0, Obliv::LONG);
  oblivStack->push(OblivContainer(newOblivVal));
  SET_STACK_LONG_OBLIVIOUS_POSITION(oblivStack->length()-1, STACK_SLOT(-3));

  return DEFAULTLONGRETURNVALUE;
}

inline jlong BytecodeInterpreter::VMlongUshr(jlong op1, jint op2) {
  return ((unsigned long long) op1) >> (op2 & 0x3F);
}

inline jlong BytecodeInterpreter::VMObliviousLongUshr(intptr_t* topOfStack, GrowableArray<OblivContainer>* oblivStack) {

  SET_STACK_LONG_OBLIVIOUS_POSITION(-1, STACK_SLOT(-1));
  olong oop2 = oblivStack->pop().getObliv().getLong();
  SET_STACK_LONG_OBLIVIOUS_POSITION(-1, STACK_SLOT(-3));
  olong oop1 = oblivStack->pop().getObliv().getLong();

  olong dest = longURightShift(&__obliv_c__trueCond, oop1, oop2);

  Obliv newOblivVal(dest, 0, Obliv::LONG);
  oblivStack->push(OblivContainer(newOblivVal));
  SET_STACK_LONG_OBLIVIOUS_POSITION(oblivStack->length()-1, STACK_SLOT(-3));

  return DEFAULTLONGRETURNVALUE;
}

inline jlong BytecodeInterpreter::VMlongShr(jlong op1, jint op2) {
  return op1 >> (op2 & 0x3F);
}

inline jlong BytecodeInterpreter::VMObliviousLongShr(intptr_t* topOfStack, GrowableArray<OblivContainer>* oblivStack) {

  SET_STACK_LONG_OBLIVIOUS_POSITION(-1, STACK_SLOT(-1));
  olong oop2 = oblivStack->pop().getObliv().getLong();
  SET_STACK_LONG_OBLIVIOUS_POSITION(-1, STACK_SLOT(-3));
  olong oop1 = oblivStack->pop().getObliv().getLong();

  olong dest = longRightShift(&__obliv_c__trueCond, oop1, oop2);

  Obliv newOblivVal(dest, 0, Obliv::LONG);
  oblivStack->push(OblivContainer(newOblivVal));
  SET_STACK_LONG_OBLIVIOUS_POSITION(oblivStack->length()-1, STACK_SLOT(-3));

  return DEFAULTLONGRETURNVALUE;
}

inline jlong BytecodeInterpreter::VMlongShl(jlong op1, jint op2) {
  return op1 << (op2 & 0x3F);
}

inline jlong BytecodeInterpreter::VMObliviousLongShl(intptr_t* topOfStack, GrowableArray<OblivContainer>* oblivStack) {

  SET_STACK_LONG_OBLIVIOUS_POSITION(-1, STACK_SLOT(-1));
  olong oop2 = oblivStack->pop().getObliv().getLong();
  SET_STACK_LONG_OBLIVIOUS_POSITION(-1, STACK_SLOT(-3));
  olong oop1 = oblivStack->pop().getObliv().getLong();

  olong dest = longLeftShift(&__obliv_c__trueCond, oop1, oop2);

  Obliv newOblivVal(dest, 0, Obliv::LONG);
  oblivStack->push(OblivContainer(newOblivVal));
  SET_STACK_LONG_OBLIVIOUS_POSITION(oblivStack->length()-1, STACK_SLOT(-3));

  return DEFAULTLONGRETURNVALUE;
}

inline jlong BytecodeInterpreter::VMlongNeg(jlong op) {
  return -op;
}

inline jlong BytecodeInterpreter::VMObliviousLongNeg(intptr_t* topOfStack, GrowableArray<OblivContainer>* oblivStack) {

  SET_STACK_LONG_OBLIVIOUS_POSITION(-1, STACK_SLOT(-1));
  olong oop1 = oblivStack->pop().getObliv().getLong();

  olong dest;
  memset((void *)(& dest), 0, sizeof(olong));
  __obliv_c__setSignedKnown(&dest, 64UL, (widest_t )((unsigned long long)0));

  __obliv_c__setNeg((void*) &dest, (const void*)&oop1, 64UL);

  Obliv newOblivVal(dest, 0, Obliv::LONG);
  oblivStack->push(OblivContainer(newOblivVal));
  SET_STACK_LONG_OBLIVIOUS_POSITION(oblivStack->length()-1, STACK_SLOT(-1));

  return DEFAULTLONGRETURNVALUE;
}

inline jlong BytecodeInterpreter::VMlongNot(jlong op) {
  return ~op;
}

inline jlong BytecodeInterpreter::VMObliviousLongNot(intptr_t* topOfStack, GrowableArray<OblivContainer>* oblivStack) {

  SET_STACK_LONG_OBLIVIOUS_POSITION(-1, STACK_SLOT(-1));
  olong oop1 = oblivStack->pop().getObliv().getLong();

  olong dest;
  memset((void *)(& dest), 0, sizeof(olong));
  __obliv_c__setSignedKnown(&dest, 64UL, (widest_t )((unsigned long long)0));

  __obliv_c__setBitwiseNot((void*) &dest, (const void*)&oop1, 64UL);

  Obliv newOblivVal(dest, 0, Obliv::LONG);
  oblivStack->push(OblivContainer(newOblivVal));
  SET_STACK_LONG_OBLIVIOUS_POSITION(oblivStack->length()-1, STACK_SLOT(-1));

  return DEFAULTLONGRETURNVALUE;
}

inline int32_t BytecodeInterpreter::VMlongLtz(jlong op) {
  return (op <= 0);
}

inline int32_t BytecodeInterpreter::VMObliviousLongLtz(intptr_t* topOfStack, GrowableArray<OblivContainer>* oblivStack) {

  SET_STACK_LONG_OBLIVIOUS_POSITION(-1, STACK_SLOT(-1));
  olong oop1 = oblivStack->pop().getObliv().getLong();

  olong oop2;
  memset((void *)(& oop2), 0, sizeof(olong));
  __obliv_c__setSignedKnown(&oop2, 64UL, (widest_t )((unsigned long long)0));

  olong dest;
  memset((void *)(& dest), 0, sizeof(olong));
  __obliv_c__setSignedKnown(&dest, 64UL, (widest_t )((unsigned long long)0));

  __obliv_c__setLessOrEqualSigned((void*)&dest, (const void*)&oop1, (const void*)&oop2, 64UL);

  Obliv newOblivVal(dest, 0, Obliv::LONG);
  oblivStack->push(OblivContainer(newOblivVal));
  SET_STACK_LONG_OBLIVIOUS_POSITION(oblivStack->length()-1, STACK_SLOT(-1));

  return DEFAULTCOMPARERETURNVALUE;
}

inline int32_t BytecodeInterpreter::VMlongGez(jlong op) {
  return (op >= 0);
}

inline int32_t BytecodeInterpreter::VMObliviousLongGez(intptr_t* topOfStack, GrowableArray<OblivContainer>* oblivStack) {

  SET_STACK_LONG_OBLIVIOUS_POSITION(-1, STACK_SLOT(-1));
  olong oop1 = oblivStack->pop().getObliv().getLong();

  olong oop2;
  memset((void *)(& oop2), 0, sizeof(olong));
  __obliv_c__setSignedKnown(&oop2, 64UL, (widest_t )((unsigned long long)0));

  olong dest;
  memset((void *)(& dest), 0, sizeof(olong));
  __obliv_c__setSignedKnown(&dest, 64UL, (widest_t )((unsigned long long)0));

  // change order
  __obliv_c__setLessOrEqualSigned((void*)&dest, (const void*)&oop2, (const void*)&oop1, 64UL);

  Obliv newOblivVal(dest, 0, Obliv::LONG);
  oblivStack->push(OblivContainer(newOblivVal));
  SET_STACK_LONG_OBLIVIOUS_POSITION(oblivStack->length()-1, STACK_SLOT(-1));

  return DEFAULTCOMPARERETURNVALUE;
}

inline int32_t BytecodeInterpreter::VMlongEqz(jlong op) {
  return (op == 0);
}

inline int32_t BytecodeInterpreter::VMObliviousLongEqz(intptr_t* topOfStack, GrowableArray<OblivContainer>* oblivStack) {

  SET_STACK_LONG_OBLIVIOUS_POSITION(-1, STACK_SLOT(-1));
  olong oop1 = oblivStack->pop().getObliv().getLong();

  olong oop2;
  memset((void *)(& oop2), 0, sizeof(olong));
  __obliv_c__setSignedKnown(&oop2, 64UL, (widest_t )((unsigned long long)0));

  olong dest;
  memset((void *)(& dest), 0, sizeof(olong));
  __obliv_c__setSignedKnown(&dest, 64UL, (widest_t )((unsigned long long)0));

  __obliv_c__setEqualTo((void*)&dest, (const void*)&oop1, (const void*)&oop2, 64UL);

  Obliv newOblivVal(dest, 0, Obliv::LONG);
  oblivStack->push(OblivContainer(newOblivVal));
  SET_STACK_LONG_OBLIVIOUS_POSITION(oblivStack->length()-1, STACK_SLOT(-1));

  return DEFAULTCOMPARERETURNVALUE;
}

inline int32_t BytecodeInterpreter::VMlongEq(jlong op1, jlong op2) {
  return (op1 == op2);
}

inline int32_t BytecodeInterpreter::VMObliviousLongEq(intptr_t* topOfStack, GrowableArray<OblivContainer>* oblivStack) {

  SET_STACK_LONG_OBLIVIOUS_POSITION(-1, STACK_SLOT(-1));
  olong oop2 = oblivStack->pop().getObliv().getLong();
  SET_STACK_LONG_OBLIVIOUS_POSITION(-1, STACK_SLOT(-3));
  olong oop1 = oblivStack->pop().getObliv().getLong();

  olong dest;
  memset((void *)(& dest), 0, sizeof(olong));
  __obliv_c__setSignedKnown(&dest, 64UL, (widest_t )((unsigned long long)0));

  __obliv_c__setEqualTo((void*)&dest, (const void*)&oop1, (const void*)&oop2, 64UL);

  Obliv newOblivVal(dest, 0, Obliv::LONG);
  oblivStack->push(OblivContainer(newOblivVal));
  SET_STACK_LONG_OBLIVIOUS_POSITION(oblivStack->length()-1, STACK_SLOT(-3));

  return DEFAULTCOMPARERETURNVALUE;
}

inline int32_t BytecodeInterpreter::VMlongNe(jlong op1, jlong op2) {
  return (op1 != op2);
}

inline int32_t BytecodeInterpreter::VMObliviousLongNe(intptr_t* topOfStack, GrowableArray<OblivContainer>* oblivStack) {

  SET_STACK_LONG_OBLIVIOUS_POSITION(-1, STACK_SLOT(-1));
  olong oop2 = oblivStack->pop().getObliv().getLong();
  SET_STACK_LONG_OBLIVIOUS_POSITION(-1, STACK_SLOT(-3));
  olong oop1 = oblivStack->pop().getObliv().getLong();

  olong dest;
  memset((void *)(& dest), 0, sizeof(olong));
  __obliv_c__setSignedKnown(&dest, 64UL, (widest_t )((unsigned long long)0));

  __obliv_c__setNotEqual((void*)&dest, (const void*)&oop1, (const void*)&oop2, 64UL);

  Obliv newOblivVal(dest, 0, Obliv::LONG);
  oblivStack->push(OblivContainer(newOblivVal));
  SET_STACK_LONG_OBLIVIOUS_POSITION(oblivStack->length()-1, STACK_SLOT(-3));

  return DEFAULTCOMPARERETURNVALUE;
}

inline int32_t BytecodeInterpreter::VMlongGe(jlong op1, jlong op2) {
  return (op1 >= op2);
}

inline int32_t BytecodeInterpreter::VMObliviousLongGe(intptr_t* topOfStack, GrowableArray<OblivContainer>* oblivStack) {

  SET_STACK_LONG_OBLIVIOUS_POSITION(-1, STACK_SLOT(-1));
  olong oop2 = oblivStack->pop().getObliv().getLong();
  SET_STACK_LONG_OBLIVIOUS_POSITION(-1, STACK_SLOT(-3));
  olong oop1 = oblivStack->pop().getObliv().getLong();

  olong dest;
  memset((void *)(& dest), 0, sizeof(olong));
  __obliv_c__setSignedKnown(&dest, 64UL, (widest_t )((unsigned long long)0));

  // change order
  __obliv_c__setLessOrEqualSigned((void*)&dest, (const void*)&oop2, (const void*)&oop1, 64UL);

  Obliv newOblivVal(dest, 0, Obliv::LONG);
  oblivStack->push(OblivContainer(newOblivVal));
  SET_STACK_LONG_OBLIVIOUS_POSITION(oblivStack->length()-1, STACK_SLOT(-3));

  return DEFAULTCOMPARERETURNVALUE;
}

inline int32_t BytecodeInterpreter::VMlongLe(jlong op1, jlong op2) {
  return (op1 <= op2);
}

inline int32_t BytecodeInterpreter::VMObliviousLongLe(intptr_t* topOfStack, GrowableArray<OblivContainer>* oblivStack) {

  SET_STACK_LONG_OBLIVIOUS_POSITION(-1, STACK_SLOT(-1));
  olong oop2 = oblivStack->pop().getObliv().getLong();
  SET_STACK_LONG_OBLIVIOUS_POSITION(-1, STACK_SLOT(-3));
  olong oop1 = oblivStack->pop().getObliv().getLong();

  olong dest;
  memset((void *)(& dest), 0, sizeof(olong));
  __obliv_c__setSignedKnown(&dest, 64UL, (widest_t )((unsigned long long)0));

  __obliv_c__setLessOrEqualSigned((void*)&dest, (const void*)&oop1, (const void*)&oop2, 64UL);

  Obliv newOblivVal(dest, 0, Obliv::LONG);
  oblivStack->push(OblivContainer(newOblivVal));
  SET_STACK_LONG_OBLIVIOUS_POSITION(oblivStack->length()-1, STACK_SLOT(-3));

  return DEFAULTCOMPARERETURNVALUE;
}

inline int32_t BytecodeInterpreter::VMlongLt(jlong op1, jlong op2) {
  return (op1 < op2);
}

inline int32_t BytecodeInterpreter::VMObliviousLongLt(intptr_t* topOfStack, GrowableArray<OblivContainer>* oblivStack) {

  SET_STACK_LONG_OBLIVIOUS_POSITION(-1, STACK_SLOT(-1));
  olong oop2 = oblivStack->pop().getObliv().getLong();
  SET_STACK_LONG_OBLIVIOUS_POSITION(-1, STACK_SLOT(-3));
  olong oop1 = oblivStack->pop().getObliv().getLong();

  olong dest;
  memset((void *)(& dest), 0, sizeof(olong));
  __obliv_c__setSignedKnown(&dest, 64UL, (widest_t )((unsigned long long)0));

  __obliv_c__setLessThanSigned((void*)&dest, (const void*)&oop1, (const void*)&oop2, 64UL);

  Obliv newOblivVal(dest, 0, Obliv::LONG);
  oblivStack->push(OblivContainer(newOblivVal));
  SET_STACK_LONG_OBLIVIOUS_POSITION(oblivStack->length()-1, STACK_SLOT(-3));

  return DEFAULTCOMPARERETURNVALUE;
}

inline int32_t BytecodeInterpreter::VMlongGt(jlong op1, jlong op2) {
  return (op1 > op2);
}

inline int32_t BytecodeInterpreter::VMObliviousLongGt(intptr_t* topOfStack, GrowableArray<OblivContainer>* oblivStack) {

  SET_STACK_LONG_OBLIVIOUS_POSITION(-1, STACK_SLOT(-1));
  olong oop2 = oblivStack->pop().getObliv().getLong();
  SET_STACK_LONG_OBLIVIOUS_POSITION(-1, STACK_SLOT(-3));
  olong oop1 = oblivStack->pop().getObliv().getLong();

  olong dest;
  memset((void *)(& dest), 0, sizeof(olong));
  __obliv_c__setSignedKnown(&dest, 64UL, (widest_t )((unsigned long long)0));

  //change order
  __obliv_c__setLessThanSigned((void*)&dest, (const void*)&oop2, (const void*)&oop1, 64UL);

  Obliv newOblivVal(dest, 0, Obliv::LONG);
  oblivStack->push(OblivContainer(newOblivVal));
  SET_STACK_LONG_OBLIVIOUS_POSITION(oblivStack->length()-1, STACK_SLOT(-3));

  return DEFAULTCOMPARERETURNVALUE;
}

inline int32_t BytecodeInterpreter::VMlongCompare(jlong op1, jlong op2) {
  return (VMlongLt(op1, op2) ? -1 : VMlongGt(op1, op2) ? 1 : 0);
}

inline int32_t BytecodeInterpreter::VMObliviousLongCompare(intptr_t* topOfStack, GrowableArray<OblivContainer>* oblivStack ) {

  SET_STACK_LONG_OBLIVIOUS_POSITION(-1, STACK_SLOT(-1));
  olong oop2 = oblivStack->pop().getObliv().getLong();
  SET_STACK_LONG_OBLIVIOUS_POSITION(-1, STACK_SLOT(-3));
  olong oop1 = oblivStack->pop().getObliv().getLong();

  oint dest = longCompare(&__obliv_c__trueCond, oop1, oop2);

  Obliv newOblivVal(dest, 0, Obliv::INT);
  oblivStack->push(OblivContainer(newOblivVal));

  return DEFAULTCOMPARERETURNVALUE;
}

// Long conversions

inline jdouble BytecodeInterpreter::VMlong2Double(jlong val) {
  return (jdouble) val;
}

inline jdouble BytecodeInterpreter::VMObliviousLong2Double(intptr_t* topOfStack, GrowableArray<OblivContainer>* oblivStack
) {
  SET_STACK_LONG_OBLIVIOUS_POSITION(-1, STACK_SLOT(-1));
  olong oop1 = oblivStack->pop().getObliv().getLong();

  ofloat64 dest = long2Double(&__obliv_c__trueCond, oop1);

  Obliv newOblivVal(dest, 0, Obliv::DOUBLE);
  oblivStack->push(OblivContainer(newOblivVal));

  return DEFAULTDOUBLERETURNVALUE;
}

inline jfloat BytecodeInterpreter::VMlong2Float(jlong val) {
  return (jfloat) val;
}

inline jfloat BytecodeInterpreter::VMObliviousLong2Float(intptr_t* topOfStack, GrowableArray<OblivContainer>* oblivStack)
{
  SET_STACK_LONG_OBLIVIOUS_POSITION(-1, STACK_SLOT(-1));
  olong oop1 = oblivStack->pop().getObliv().getLong();

  ofloat32 dest = long2Float(&__obliv_c__trueCond, oop1);

  Obliv newOblivVal(dest, 0, Obliv::FLOAT);
  oblivStack->push(OblivContainer(newOblivVal));

  return DEFAULTFLOATRETURNVALUE;
}

inline jint BytecodeInterpreter::VMlong2Int(jlong val) {
  return (jint) val;
}

inline jint BytecodeInterpreter::VMObliviousLong2Int(intptr_t* topOfStack, GrowableArray<OblivContainer>* oblivStack) {

  SET_STACK_LONG_OBLIVIOUS_POSITION(-1, STACK_SLOT(-1));
  olong oop1 = oblivStack->pop().getObliv().getLong();

  oint dest = long2Int(&__obliv_c__trueCond, oop1);

  Obliv newOblivVal(dest, 0, Obliv::INT);
  oblivStack->push(OblivContainer(newOblivVal));

  return DEFAULTINTRETURNVALUE;
}

// Double Arithmetic

inline jdouble BytecodeInterpreter::VMdoubleAdd(jdouble op1, jdouble op2) {
  return op1 + op2;
}

inline jdouble BytecodeInterpreter::VMObliviousDoubleAdd(intptr_t* topOfStack, GrowableArray<OblivContainer>* oblivStack)
{
  SET_STACK_DOUBLE_OBLIVIOUS_POSITION(-1, STACK_SLOT(-1));
  ofloat64 oop2 = oblivStack->pop().getObliv().getDouble();
  SET_STACK_DOUBLE_OBLIVIOUS_POSITION(-1, STACK_SLOT(-3));
  ofloat64 oop1 = oblivStack->pop().getObliv().getDouble();

  ofloat64 dest = float64_add(&__obliv_c__trueCond , oop1, oop2);

  Obliv newOblivVal(dest, 0, Obliv::DOUBLE);
  oblivStack->push(OblivContainer(newOblivVal));
  SET_STACK_DOUBLE_OBLIVIOUS_POSITION(oblivStack->length()-1, STACK_SLOT(-3));

  return DEFAULTDOUBLERETURNVALUE;
}

inline jdouble BytecodeInterpreter::VMdoubleDiv(jdouble op1, jdouble op2) {
  // Divide by zero... QQQ
  return op1 / op2;
}

inline jdouble BytecodeInterpreter::VMObliviousDoubleDiv(intptr_t* topOfStack, GrowableArray<OblivContainer>* oblivStack) {

  SET_STACK_DOUBLE_OBLIVIOUS_POSITION(-1, STACK_SLOT(-1));
  ofloat64 oop2 = oblivStack->pop().getObliv().getDouble();
  SET_STACK_DOUBLE_OBLIVIOUS_POSITION(-1, STACK_SLOT(-3));
  ofloat64 oop1 = oblivStack->pop().getObliv().getDouble();

  ofloat64 dest = float64_div(&__obliv_c__trueCond , oop1, oop2);

  Obliv newOblivVal(dest, 0, Obliv::DOUBLE);
  oblivStack->push(OblivContainer(newOblivVal));
  SET_STACK_DOUBLE_OBLIVIOUS_POSITION(oblivStack->length()-1, STACK_SLOT(-3));

  return DEFAULTDOUBLERETURNVALUE;
}

inline jdouble BytecodeInterpreter::VMdoubleMul(jdouble op1, jdouble op2) {
  return op1 * op2;
}

inline jdouble BytecodeInterpreter::VMObliviousDoubleMul(intptr_t* topOfStack, GrowableArray<OblivContainer>* oblivStack)
{
  SET_STACK_DOUBLE_OBLIVIOUS_POSITION(-1, STACK_SLOT(-1));
  ofloat64 oop2 = oblivStack->pop().getObliv().getDouble();
  SET_STACK_DOUBLE_OBLIVIOUS_POSITION(-1, STACK_SLOT(-3));
  ofloat64 oop1 = oblivStack->pop().getObliv().getDouble();

  ofloat64 dest = float64_mul(&__obliv_c__trueCond , oop1, oop2);

  Obliv newOblivVal(dest, 0, Obliv::DOUBLE);
  oblivStack->push(OblivContainer(newOblivVal));
  SET_STACK_DOUBLE_OBLIVIOUS_POSITION(oblivStack->length()-1, STACK_SLOT(-3));

  return DEFAULTDOUBLERETURNVALUE;
}

inline jdouble BytecodeInterpreter::VMdoubleNeg(jdouble op) {
  return -op;
}

inline jdouble BytecodeInterpreter::VMObliviousDoubleNeg(intptr_t* topOfStack, GrowableArray<OblivContainer>* oblivStack)
{
  SET_STACK_DOUBLE_OBLIVIOUS_POSITION(-1, STACK_SLOT(-1));
  ofloat64 oop1 = oblivStack->pop().getObliv().getDouble();

  ofloat64 dest = float64_neg(&__obliv_c__trueCond , oop1);

  Obliv newOblivVal(dest, 0, Obliv::DOUBLE);
  oblivStack->push(OblivContainer(newOblivVal));
  SET_STACK_DOUBLE_OBLIVIOUS_POSITION(oblivStack->length()-1, STACK_SLOT(-3));

  return DEFAULTDOUBLERETURNVALUE;
}

inline jdouble BytecodeInterpreter::VMdoubleRem(jdouble op1, jdouble op2) {
  return fmod(op1, op2);
}

inline jdouble BytecodeInterpreter::VMObliviousDoubleRem(intptr_t* topOfStack, GrowableArray<OblivContainer>* oblivStack)
{
  SET_STACK_DOUBLE_OBLIVIOUS_POSITION(-1, STACK_SLOT(-1));
  ofloat64 oop2 = oblivStack->pop().getObliv().getDouble();
  SET_STACK_DOUBLE_OBLIVIOUS_POSITION(-1, STACK_SLOT(-3));
  ofloat64 oop1 = oblivStack->pop().getObliv().getDouble();

  ofloat64 dest = float64_rem(&__obliv_c__trueCond, oop1, oop2);

  Obliv newOblivVal(dest, 0, Obliv::DOUBLE);
  oblivStack->push(OblivContainer(newOblivVal));
  SET_STACK_DOUBLE_OBLIVIOUS_POSITION(oblivStack->length()-1, STACK_SLOT(-3));

  return DEFAULTDOUBLERETURNVALUE;
}

inline jdouble BytecodeInterpreter::VMdoubleSub(jdouble op1, jdouble op2) {
  return op1 - op2;
}

inline jdouble BytecodeInterpreter::VMObliviousDoubleSub(intptr_t* topOfStack, GrowableArray<OblivContainer>* oblivStack) {  
	
  SET_STACK_DOUBLE_OBLIVIOUS_POSITION(-1, STACK_SLOT(-1));
  ofloat64 oop2 = oblivStack->pop().getObliv().getDouble();
  SET_STACK_DOUBLE_OBLIVIOUS_POSITION(-1, STACK_SLOT(-3));
  ofloat64 oop1 = oblivStack->pop().getObliv().getDouble();

  ofloat64 dest = float64_sub(&__obliv_c__trueCond , oop1, oop2);

  Obliv newOblivVal(dest, 0, Obliv::DOUBLE);
  oblivStack->push(OblivContainer(newOblivVal));
  SET_STACK_DOUBLE_OBLIVIOUS_POSITION(oblivStack->length()-1, STACK_SLOT(-3));

  return DEFAULTDOUBLERETURNVALUE;
}

inline int32_t BytecodeInterpreter::VMdoubleCompare(jdouble op1,
                                                    jdouble op2,
                                                    int32_t direction) {
  return ( op1 < op2 ? -1 :
               op1 > op2 ? 1 :
                   op1 == op2 ? 0 :
                       (direction == -1 || direction == 1) ? direction : 0);
}

inline int32_t BytecodeInterpreter::VMObliviousDoubleCompare(intptr_t* topOfStack, GrowableArray<OblivContainer>* oblivStack,
                                                              int32_t direction) {

  SET_STACK_DOUBLE_OBLIVIOUS_POSITION(-1, STACK_SLOT(-1));
  ofloat64 oop2 = oblivStack->pop().getObliv().getDouble();
  SET_STACK_DOUBLE_OBLIVIOUS_POSITION(-1, STACK_SLOT(-3));
  ofloat64 oop1 = oblivStack->pop().getObliv().getDouble();

  oint dest = doubleCompare(&__obliv_c__trueCond , oop1, oop2);

  Obliv newOblivVal(dest, 0, Obliv::INT);
  oblivStack->push(OblivContainer(newOblivVal));

  return DEFAULTCOMPARERETURNVALUE;
}

// Double Conversions

inline jfloat BytecodeInterpreter::VMdouble2Float(jdouble val) {
  return (jfloat) val;
}

inline jfloat BytecodeInterpreter::VMObliviousDouble2Float(intptr_t* topOfStack, GrowableArray<OblivContainer>* oblivStack)
{
  SET_STACK_DOUBLE_OBLIVIOUS_POSITION(-1, STACK_SLOT(-1));
  ofloat64 oop1 = oblivStack->pop().getObliv().getDouble();

  ofloat32 dest = double2Float(&__obliv_c__trueCond, oop1);

  Obliv newOblivVal(dest, 0, Obliv::FLOAT);
  oblivStack->push(OblivContainer(newOblivVal));

  return DEFAULTFLOATRETURNVALUE;
}

inline jint BytecodeInterpreter::VMObliviousDouble2Int(intptr_t* topOfStack, GrowableArray<OblivContainer>* oblivStack)
{
  SET_STACK_DOUBLE_OBLIVIOUS_POSITION(-1, STACK_SLOT(-1));
  ofloat64 oop1 = oblivStack->pop().getObliv().getDouble();

  oint dest = float64_to_oint32(&__obliv_c__trueCond, oop1);

  Obliv newOblivVal(dest, 0, Obliv::INT);
  oblivStack->push(OblivContainer(newOblivVal));

  return DEFAULTINTRETURNVALUE;
}

inline jlong BytecodeInterpreter::VMObliviousDouble2Long(intptr_t* topOfStack, GrowableArray<OblivContainer>* oblivStack)
{
  SET_STACK_DOUBLE_OBLIVIOUS_POSITION(-1, STACK_SLOT(-1));
  ofloat64 oop1 = oblivStack->pop().getObliv().getDouble();
/*
                double *pout, out;
                long long *pin, in;
                revealOblivLLong(&in, oop1, 0);
                pout = &out; pin = &in;
                memcpy(pout, pin, sizeof(*pout));

  tty->print_cr("Double2Long: input %f", out);

  olong dest = float64_to_oint64(&__obliv_c__trueCond, oop1);

                long long in2;
                revealOblivLLong(&in2, dest, 0);

  tty->print_cr("Double2Long: output %lld", in2);
  tty->print_cr("Double2Long: output %llu", in2);

  olong dest2 = float64_to_oint64_round_to_zero(&__obliv_c__trueCond, oop1);

                long long in3;
                revealOblivLLong(&in3, dest2, 0);

  tty->print_cr("Double2Long: output %lld", in3);
  tty->print_cr("Double2Long: output %llu", in3);
  */
  olong dest = float32_to_int64_round_to_zero(&__obliv_c__trueCond, double2Float(&__obliv_c__trueCond, oop1));

  Obliv newOblivVal(dest, 0, Obliv::LONG);
  oblivStack->push(OblivContainer(newOblivVal));

  return DEFAULTLONGRETURNVALUE;
}

// Float Conversions

inline jdouble BytecodeInterpreter::VMfloat2Double(jfloat op) {
  return (jdouble) op;
}

inline jdouble BytecodeInterpreter::VMObliviousFloat2Double(intptr_t* topOfStack, GrowableArray<OblivContainer>* oblivStack) {

  SET_STACK_OBLIVIOUS_POSITION(-1, STACK_SLOT(-1));
  ofloat32 oop1 = oblivStack->pop().getObliv().getFloat();

  ofloat64 dest = float2Double(&__obliv_c__trueCond, oop1);

  Obliv newOblivVal(dest, 0, Obliv::DOUBLE);
  oblivStack->push(OblivContainer(newOblivVal));

  return DEFAULTDOUBLERETURNVALUE;
}

inline jint BytecodeInterpreter::VMObliviousFloat2Int(intptr_t* topOfStack, GrowableArray<OblivContainer>* oblivStack) {

  SET_STACK_OBLIVIOUS_POSITION(-1, STACK_SLOT(-1));
  ofloat32 oop1 = oblivStack->pop().getObliv().getFloat();

  oint dest = float32_to_int(&__obliv_c__trueCond, oop1);

  Obliv newOblivVal(dest, 0, Obliv::INT);
  oblivStack->push(OblivContainer(newOblivVal));
  SET_STACK_OBLIVIOUS_POSITION(oblivStack->length()-1, STACK_SLOT(-1));

  return DEFAULTINTRETURNVALUE;
}

inline jlong BytecodeInterpreter::VMObliviousFloat2Long(intptr_t* topOfStack, GrowableArray<OblivContainer>* oblivStack) {

  SET_STACK_OBLIVIOUS_POSITION(-1, STACK_SLOT(-1));
  ofloat32 oop1 = oblivStack->pop().getObliv().getFloat();

  olong dest = float32_to_int64_round_to_zero(&__obliv_c__trueCond, oop1);

  Obliv newOblivVal(dest, 0, Obliv::LONG);
  oblivStack->push(OblivContainer(newOblivVal));

  return DEFAULTLONGRETURNVALUE;
}

// Integer Arithmetic

inline jint BytecodeInterpreter::VMintAdd(jint op1, jint op2) {
  return op1 + op2;
}

inline jint BytecodeInterpreter::VMObliviousIntAdd(intptr_t* topOfStack, GrowableArray<OblivContainer>* oblivStack) {

  SET_STACK_OBLIVIOUS_POSITION(-1, STACK_SLOT(-1));
  oint oop2 = oblivStack->pop().getObliv().getInt();
  SET_STACK_OBLIVIOUS_POSITION(-1, STACK_SLOT(-2));
  oint oop1 = oblivStack->pop().getObliv().getInt();

  oint dest;
  memset((void *)(& dest), 0, sizeof(oint));
  __obliv_c__setSignedKnown(&dest, 32UL, (widest_t )((unsigned int )0));

  __obliv_c__setPlainAdd((void*)&dest, (const void*)&oop1, (const void*)&oop2, 32UL);

  Obliv newOblivVal(dest, 0, Obliv::INT);
  oblivStack->push(OblivContainer(newOblivVal));
  SET_STACK_OBLIVIOUS_POSITION(oblivStack->length()-1, STACK_SLOT(-2));

  return DEFAULTINTRETURNVALUE;
}

inline jint BytecodeInterpreter::VMintAnd(jint op1, jint op2) {
  return op1 & op2;
}

inline jint BytecodeInterpreter::VMObliviousIntAnd(intptr_t* topOfStack, GrowableArray<OblivContainer>* oblivStack) {

  SET_STACK_OBLIVIOUS_POSITION(-1, STACK_SLOT(-1));
  oint oop2 = oblivStack->pop().getObliv().getInt();
  SET_STACK_OBLIVIOUS_POSITION(-1, STACK_SLOT(-2));
  oint oop1 = oblivStack->pop().getObliv().getInt();

  oint dest;
  memset((void *)(& dest), 0, sizeof(oint));
  __obliv_c__setSignedKnown(&dest, 32UL, (widest_t )((unsigned int )0));

  __obliv_c__setBitwiseAnd((void*)&dest, (const void*)&oop1, (const void*)&oop2, 32UL);

  Obliv newOblivVal(dest, 0, Obliv::INT);
  oblivStack->push(OblivContainer(newOblivVal));
  SET_STACK_OBLIVIOUS_POSITION(oblivStack->length()-1, STACK_SLOT(-2));

  return DEFAULTINTRETURNVALUE;
}

inline jint BytecodeInterpreter::VMintDiv(jint op1, jint op2) {
  /* it's possible we could catch this special case implicitly */
  if (op1 == (jint) 0x80000000 && op2 == -1) return op1;
  else return op1 / op2;
}

inline jint BytecodeInterpreter::VMObliviousIntDiv(intptr_t* topOfStack, GrowableArray<OblivContainer>* oblivStack) {

  SET_STACK_OBLIVIOUS_POSITION(-1, STACK_SLOT(-1));
  oint oop2 = oblivStack->pop().getObliv().getInt();
  SET_STACK_OBLIVIOUS_POSITION(-1, STACK_SLOT(-2));
  oint oop1 = oblivStack->pop().getObliv().getInt();

  oint dest;
  memset((void *)(& dest), 0, sizeof(oint));
  __obliv_c__setSignedKnown(&dest, 32UL, (widest_t )((unsigned int )0));

  __obliv_c__setDivSigned((void*)&dest, (const void*)&oop1, (const void*)&oop2, 32UL);

  Obliv newOblivVal(dest, 0, Obliv::INT);
  oblivStack->push(OblivContainer(newOblivVal));
  SET_STACK_OBLIVIOUS_POSITION(oblivStack->length()-1, STACK_SLOT(-2));

  return DEFAULTINTRETURNVALUE;
}

inline jint BytecodeInterpreter::VMintMul(jint op1, jint op2) {
  return op1 * op2;
}

inline jint BytecodeInterpreter::VMObliviousIntMul(intptr_t* topOfStack, GrowableArray<OblivContainer>* oblivStack) {

  SET_STACK_OBLIVIOUS_POSITION(-1, STACK_SLOT(-1));
  oint oop2 = oblivStack->pop().getObliv().getInt();
  SET_STACK_OBLIVIOUS_POSITION(-1, STACK_SLOT(-2));
  oint oop1 = oblivStack->pop().getObliv().getInt();

  oint dest;
  memset((void *)(& dest), 0, sizeof(oint));
  __obliv_c__setSignedKnown(&dest, 32UL, (widest_t )((unsigned int )0));

  __obliv_c__setMul((void*)&dest, (const void*)&oop1, (const void*)&oop2, 32UL);

  Obliv newOblivVal(dest, 0, Obliv::INT);
  oblivStack->push(OblivContainer(newOblivVal));
  SET_STACK_OBLIVIOUS_POSITION(oblivStack->length()-1, STACK_SLOT(-2));

  return DEFAULTINTRETURNVALUE;
}

inline jint BytecodeInterpreter::VMintNeg(jint op) {
  return -op;
}

inline jint BytecodeInterpreter::VMObliviousIntNeg(intptr_t* topOfStack, GrowableArray<OblivContainer>* oblivStack) {

  SET_STACK_OBLIVIOUS_POSITION(-1, STACK_SLOT(-1));
  ofloat32 oop1 = oblivStack->pop().getObliv().getFloat();

  ofloat32 dest;
  memset((void *)(& dest), 0, sizeof(ofloat32));
  __obliv_c__setSignedKnown(&dest, 32UL, (widest_t )((unsigned int )0));

  __obliv_c__setNeg((void*) &dest, (const void*)&oop1, 32UL);

  Obliv newOblivVal(dest, 0, Obliv::FLOAT);
  oblivStack->push(OblivContainer(newOblivVal));
  SET_STACK_OBLIVIOUS_POSITION(oblivStack->length()-1, STACK_SLOT(-2));

  return DEFAULTINTRETURNVALUE;
}

inline jint BytecodeInterpreter::VMintOr(jint op1, jint op2) {
  return op1 | op2;
}

inline jint BytecodeInterpreter::VMObliviousIntOr(intptr_t* topOfStack, GrowableArray<OblivContainer>* oblivStack) {

  SET_STACK_OBLIVIOUS_POSITION(-1, STACK_SLOT(-1));
  oint oop2 = oblivStack->pop().getObliv().getInt();
  SET_STACK_OBLIVIOUS_POSITION(-1, STACK_SLOT(-2));
  oint oop1 = oblivStack->pop().getObliv().getInt();

  oint dest;
  memset((void *)(& dest), 0, sizeof(oint));
  __obliv_c__setSignedKnown(&dest, 32UL, (widest_t )((unsigned int )0));

  __obliv_c__setBitwiseOr((void*)&dest, (const void*)&oop1, (const void*)&oop2, 32UL);

  Obliv newOblivVal(dest, 0, Obliv::INT);
  oblivStack->push(OblivContainer(newOblivVal));
  SET_STACK_OBLIVIOUS_POSITION(oblivStack->length()-1, STACK_SLOT(-2));

  return DEFAULTINTRETURNVALUE;
}

inline jint BytecodeInterpreter::VMintRem(jint op1, jint op2) {
  /* it's possible we could catch this special case implicitly */
  if (op1 == (jint) 0x80000000 && op2 == -1) return 0;
  else return op1 % op2;
}

inline jint BytecodeInterpreter::VMObliviousIntRem(intptr_t* topOfStack, GrowableArray<OblivContainer>* oblivStack) {

  SET_STACK_OBLIVIOUS_POSITION(-1, STACK_SLOT(-1));
  oint oop2 = oblivStack->pop().getObliv().getInt();
  SET_STACK_OBLIVIOUS_POSITION(-1, STACK_SLOT(-2));
  oint oop1 = oblivStack->pop().getObliv().getInt();

  oint dest;
  memset((void *)(& dest), 0, sizeof(oint));
  __obliv_c__setSignedKnown(&dest, 32UL, (widest_t )((unsigned int )0));

  __obliv_c__setModSigned((void*)&dest, (const void*)&oop1, (const void*)&oop2, 32UL);

  Obliv newOblivVal(dest, 0, Obliv::INT);
  oblivStack->push(OblivContainer(newOblivVal));
  SET_STACK_OBLIVIOUS_POSITION(oblivStack->length()-1, STACK_SLOT(-2));

  return DEFAULTINTRETURNVALUE;
}

inline jint BytecodeInterpreter::VMintShl(jint op1, jint op2) {
  return op1 << (op2 & 0x1F);
}

inline jint BytecodeInterpreter::VMObliviousIntShl(intptr_t* topOfStack, GrowableArray<OblivContainer>* oblivStack) {

  SET_STACK_OBLIVIOUS_POSITION(-1, STACK_SLOT(-1));
  oint oop2 = oblivStack->pop().getObliv().getInt();
  SET_STACK_OBLIVIOUS_POSITION(-1, STACK_SLOT(-2));
  oint oop1 = oblivStack->pop().getObliv().getInt();

  oint dest = intLeftShift(&__obliv_c__trueCond, oop1, oop2);

  Obliv newOblivVal(dest, 0, Obliv::INT);
  oblivStack->push(OblivContainer(newOblivVal));
  SET_STACK_OBLIVIOUS_POSITION(oblivStack->length()-1, STACK_SLOT(-2));

  return DEFAULTINTRETURNVALUE;
}

inline jint BytecodeInterpreter::VMintShr(jint op1, jint op2) {
  return op1 >> (op2 & 0x1F);
}

inline jint BytecodeInterpreter::VMObliviousIntShr(intptr_t* topOfStack, GrowableArray<OblivContainer>* oblivStack) {

  SET_STACK_OBLIVIOUS_POSITION(-1, STACK_SLOT(-1));
  oint oop2 = oblivStack->pop().getObliv().getInt();
  SET_STACK_OBLIVIOUS_POSITION(-1, STACK_SLOT(-2));
  oint oop1 = oblivStack->pop().getObliv().getInt();

  oint dest = intRightShift(&__obliv_c__trueCond, oop1, oop2);

  Obliv newOblivVal(dest, 0, Obliv::INT);
  oblivStack->push(OblivContainer(newOblivVal));
  SET_STACK_OBLIVIOUS_POSITION(oblivStack->length()-1, STACK_SLOT(-2));

  return DEFAULTINTRETURNVALUE;
}

inline jint BytecodeInterpreter::VMintSub(jint op1, jint op2) {
  return op1 - op2;
}

inline jint BytecodeInterpreter::VMObliviousIntSub(intptr_t* topOfStack, GrowableArray<OblivContainer>* oblivStack) {

  SET_STACK_OBLIVIOUS_POSITION(-1, STACK_SLOT(-1));
  oint oop2 = oblivStack->pop().getObliv().getInt();
  SET_STACK_OBLIVIOUS_POSITION(-1, STACK_SLOT(-2));
  oint oop1 = oblivStack->pop().getObliv().getInt();

  oint dest;
  memset((void *)(& dest), 0, sizeof(oint));
  __obliv_c__setSignedKnown(&dest, 32UL, (widest_t )((unsigned int )0));

  __obliv_c__setPlainSub((void*)&dest, (const void*)&oop1, (const void*)&oop2, 32UL);

  Obliv newOblivVal(dest, 0, Obliv::INT);
  oblivStack->push(OblivContainer(newOblivVal));
  SET_STACK_OBLIVIOUS_POSITION(oblivStack->length()-1, STACK_SLOT(-2));

  return DEFAULTINTRETURNVALUE;
}

inline juint BytecodeInterpreter::VMintUshr(jint op1, jint op2) {
  return ((juint) op1) >> (op2 & 0x1F);
}

inline juint BytecodeInterpreter::VMObliviousIntUshr(intptr_t* topOfStack, GrowableArray<OblivContainer>* oblivStack) {

  SET_STACK_OBLIVIOUS_POSITION(-1, STACK_SLOT(-1));
  oint oop2 = oblivStack->pop().getObliv().getInt();
  SET_STACK_OBLIVIOUS_POSITION(-1, STACK_SLOT(-2));
  oint oop1 = oblivStack->pop().getObliv().getInt();

  oint dest = intURightShift(&__obliv_c__trueCond, oop1, oop2);

  Obliv newOblivVal(dest, 0, Obliv::INT);
  oblivStack->push(OblivContainer(newOblivVal));
  SET_STACK_OBLIVIOUS_POSITION(oblivStack->length()-1, STACK_SLOT(-2));

  return DEFAULTINTRETURNVALUE;
}

inline jint BytecodeInterpreter::VMintXor(jint op1, jint op2) {
  return op1 ^ op2;
}

inline jint BytecodeInterpreter::VMObliviousIntXor(intptr_t* topOfStack, GrowableArray<OblivContainer>* oblivStack) {

  SET_STACK_OBLIVIOUS_POSITION(-1, STACK_SLOT(-1));
  oint oop2 = oblivStack->pop().getObliv().getInt();
  SET_STACK_OBLIVIOUS_POSITION(-1, STACK_SLOT(-2));
  oint oop1 = oblivStack->pop().getObliv().getInt();

  oint dest;
  memset((void *)(& dest), 0, sizeof(oint));
  __obliv_c__setSignedKnown(&dest, 32UL, (widest_t )((unsigned int )0));

  __obliv_c__setBitwiseXor((void*)&dest, (const void*)&oop1, (const void*)&oop2, 32UL);

  Obliv newOblivVal(dest, 0, Obliv::INT);
  oblivStack->push(OblivContainer(newOblivVal));
  SET_STACK_OBLIVIOUS_POSITION(oblivStack->length()-1, STACK_SLOT(-2));

  return DEFAULTINTRETURNVALUE;
}

inline jdouble BytecodeInterpreter::VMint2Double(jint val) {
  return (jdouble) val;
}

inline jdouble BytecodeInterpreter::VMObliviousInt2Double(intptr_t* topOfStack, GrowableArray<OblivContainer>* oblivStack)
{
  SET_STACK_OBLIVIOUS_POSITION(-1, STACK_SLOT(-1));
  oint oop1 = oblivStack->pop().getObliv().getInt();

  ofloat64 dest = int2Double(&__obliv_c__trueCond, oop1);

  Obliv newOblivVal(dest, 0, Obliv::DOUBLE);
  oblivStack->push(OblivContainer(newOblivVal));

  return DEFAULTDOUBLERETURNVALUE;
}

inline jfloat BytecodeInterpreter::VMint2Float(jint val) {
  return (jfloat) val;
}

inline jfloat BytecodeInterpreter::VMObliviousInt2Float(intptr_t* topOfStack, GrowableArray<OblivContainer>* oblivStack) {

  SET_STACK_OBLIVIOUS_POSITION(-1, STACK_SLOT(-1));
  oint oop1 = oblivStack->pop().getObliv().getInt();

  ofloat32 dest = int2Float(&__obliv_c__trueCond, oop1);

  Obliv newOblivVal(dest, 0, Obliv::FLOAT);
  oblivStack->push(OblivContainer(newOblivVal));
  SET_STACK_OBLIVIOUS_POSITION(oblivStack->length()-1, STACK_SLOT(-1));

  return DEFAULTFLOATRETURNVALUE;
}

inline jlong BytecodeInterpreter::VMint2Long(jint val) {
  return (jlong) val;
}

inline jlong BytecodeInterpreter::VMObliviousInt2Long(intptr_t* topOfStack, GrowableArray<OblivContainer>* oblivStack) {

  SET_STACK_OBLIVIOUS_POSITION(-1, STACK_SLOT(-1));
  oint oop1 = oblivStack->pop().getObliv().getInt();

  olong dest = int2Long(&__obliv_c__trueCond, oop1);

  Obliv newOblivVal(dest, 0, Obliv::LONG);
  oblivStack->push(OblivContainer(newOblivVal));

  return DEFAULTLONGRETURNVALUE;
}

inline jchar BytecodeInterpreter::VMint2Char(jint val) {
  return (jchar) val;
}

inline jchar BytecodeInterpreter::VMObliviousInt2Char(intptr_t* topOfStack, GrowableArray<OblivContainer>* oblivStack) {

  SET_STACK_OBLIVIOUS_POSITION(-1, STACK_SLOT(-1));
  oint oop1 = oblivStack->pop().getObliv().getInt();

  ochar dest = int2Char(&__obliv_c__trueCond, oop1);

  Obliv newOblivVal(dest, 0);
  oblivStack->push(OblivContainer(newOblivVal));
  SET_STACK_OBLIVIOUS_POSITION(oblivStack->length()-1, STACK_SLOT(-1));

  return DEFAULTCHARRETURNVALUE;
}

inline jshort BytecodeInterpreter::VMint2Short(jint val) {
  return (jshort) val;
}

inline jshort BytecodeInterpreter::VMObliviousInt2Short(intptr_t* topOfStack, GrowableArray<OblivContainer>* oblivStack) {

  SET_STACK_OBLIVIOUS_POSITION(-1, STACK_SLOT(-1));
  oint oop1 = oblivStack->pop().getObliv().getInt();

  oshort dest = int2Short(&__obliv_c__trueCond, oop1);

  Obliv newOblivVal(dest, 0);
  oblivStack->push(OblivContainer(newOblivVal));
  SET_STACK_OBLIVIOUS_POSITION(oblivStack->length()-1, STACK_SLOT(-1));

  return DEFAULTSHORTRETURNVALUE;
}

inline jbyte BytecodeInterpreter::VMint2Byte(jint val) {
  return (jbyte) val;
}

inline jbyte BytecodeInterpreter::VMObliviousInt2Byte(intptr_t* topOfStack, GrowableArray<OblivContainer>* oblivStack) {

  SET_STACK_OBLIVIOUS_POSITION(-1, STACK_SLOT(-1));
  oint oop1 = oblivStack->pop().getObliv().getInt();

  ochar dest = int2Byte(&__obliv_c__trueCond, oop1);

  Obliv newOblivVal(dest, 0);
  oblivStack->push(OblivContainer(newOblivVal));
  SET_STACK_OBLIVIOUS_POSITION(oblivStack->length()-1, STACK_SLOT(-1));

  return DEFAULTBYTERETURNVALUE;
}

#endif // CPU_ZERO_VM_BYTECODEINTERPRETER_ZERO_INLINE_HPP
