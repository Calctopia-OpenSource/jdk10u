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

package java.security;

import java.lang.annotation.*;
import java.lang.reflect.Field;
import jdk.internal.misc.Unsafe;

/**
 * A field may be annotated as oblivious if it's going to be encrypted for secure computation
 */

//@Target({ElementType.FIELD, ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
@Target(ElementType.FIELD)
@Retention(RetentionPolicy.RUNTIME)
public @interface Obliv  {
        /** 
         * Oblivious Party (e.g., 0-2)
         *
         * @return Value of the oblivious party
         */
	public int value() default 0;

	/**
	 * Return obliv boolean that equals the  true condition
	 */
	@Obliv(0)
	public static final boolean trueCond = Unsafe.getUnsafe().trueCond(Obliv.class, Unsafe.getUnsafe().staticFieldOffset(Obliv.class.getSafeField("trueCond")));
}
