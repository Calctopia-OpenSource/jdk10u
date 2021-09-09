/*
 * Copyright (c) 2021 Calctopia and/or its affiliates. All rights reserved.
 * Copyright (c) 2001, 2005, Oracle and/or its affiliates. All rights reserved.
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
 * Please contact Oracle, 500 Oracle Parkway, Redwood Shores, CA 94065 USA
 * or visit www.oracle.com if you need additional information or have any
 * questions.
 */

package jdk.internal.reflect;

import java.lang.reflect.Field;
import java.lang.reflect.Modifier;

class UnsafeIntegerFieldAccessorImpl extends UnsafeFieldAccessorImpl {
    UnsafeIntegerFieldAccessorImpl(Field field) {
        super(field);
    }

    public Object get(Object obj) throws IllegalArgumentException {
        return Integer.valueOf(getInt(obj));
    }

    public boolean getBoolean(Object obj) throws IllegalArgumentException {
        throw newGetBooleanIllegalArgumentException();
    }

    public boolean revealOblivBoolean(Object obj) throws IllegalArgumentException {
        throw newGetBooleanIllegalArgumentException();
    }

    public byte getByte(Object obj) throws IllegalArgumentException {
        throw newGetByteIllegalArgumentException();
    }

    public byte revealOblivByte(Object obj) throws IllegalArgumentException {
        throw newGetByteIllegalArgumentException();
    }

    public char getChar(Object obj) throws IllegalArgumentException {
        throw newGetCharIllegalArgumentException();
    }

    public char revealOblivChar(Object obj) throws IllegalArgumentException {
        throw newGetCharIllegalArgumentException();
    }

    public short getShort(Object obj) throws IllegalArgumentException {
        throw newGetShortIllegalArgumentException();
    }

    public short revealOblivShort(Object obj) throws IllegalArgumentException {
        throw newGetShortIllegalArgumentException();
    }

    public int getInt(Object obj) throws IllegalArgumentException {
        ensureObj(obj);
        return unsafe.getInt(obj, fieldOffset);
    }

    public int revealOblivInt(Object obj) throws IllegalArgumentException {
        ensureObj(obj);
        return unsafe.revealOblivInt(obj, fieldOffset);
    }

    public long getLong(Object obj) throws IllegalArgumentException {
        return getInt(obj);
    }

    public long revealOblivLong(Object obj) throws IllegalArgumentException {
        return revealOblivInt(obj);
    }

    public float getFloat(Object obj) throws IllegalArgumentException {
        return getInt(obj);
    }

    public float revealOblivFloat(Object obj) throws IllegalArgumentException {
        return revealOblivInt(obj);
    }

    public double getDouble(Object obj) throws IllegalArgumentException {
        return getInt(obj);
    }

    public double revealOblivDouble(Object obj) throws IllegalArgumentException {
        return revealOblivInt(obj);
    }

    public void set(Object obj, Object value)
        throws IllegalArgumentException, IllegalAccessException
    {
        ensureObj(obj);
        if (isFinal) {
            throwFinalFieldIllegalAccessException(value);
        }
        if (value == null) {
            throwSetIllegalArgumentException(value);
        }
        if (value instanceof Byte) {
            unsafe.putInt(obj, fieldOffset, ((Byte) value).byteValue());
            return;
        }
        if (value instanceof Short) {
            unsafe.putInt(obj, fieldOffset, ((Short) value).shortValue());
            return;
        }
        if (value instanceof Character) {
            unsafe.putInt(obj, fieldOffset, ((Character) value).charValue());
            return;
        }
        if (value instanceof Integer) {
            unsafe.putInt(obj, fieldOffset, ((Integer) value).intValue());
            return;
        }
        throwSetIllegalArgumentException(value);
    }

    public void setBoolean(Object obj, boolean z)
        throws IllegalArgumentException, IllegalAccessException
    {
        throwSetIllegalArgumentException(z);
    }

    public void condAssignBoolean(Object obj, Field cond, Field of)
        throws IllegalArgumentException, IllegalAccessException
    {
        throwSetIllegalArgumentException(of);
    }

    public void setByte(Object obj, byte b)
        throws IllegalArgumentException, IllegalAccessException
    {
        setInt(obj, b);
    }

    public void condAssignByte(Object obj, Field cond, Field of)
        throws IllegalArgumentException, IllegalAccessException
    {
        throwSetIllegalArgumentException(of);
    }

    public void setChar(Object obj, char c)
        throws IllegalArgumentException, IllegalAccessException
    {
        setInt(obj, c);
    }

    public void condAssignChar(Object obj, Field cond, Field of)
        throws IllegalArgumentException, IllegalAccessException
    {
        throwSetIllegalArgumentException(of);
    }

    public void setShort(Object obj, short s)
        throws IllegalArgumentException, IllegalAccessException
    {
        setInt(obj, s);
    }

    public void condAssignShort(Object obj, Field cond, Field of)
        throws IllegalArgumentException, IllegalAccessException
    {
        throwSetIllegalArgumentException(of);
    }

    public void setInt(Object obj, int i)
        throws IllegalArgumentException, IllegalAccessException
    {
        ensureObj(obj);
        if (isFinal) {
            throwFinalFieldIllegalAccessException(i);
        }
        unsafe.putInt(obj, fieldOffset, i);
    }

    public void condAssignInt(Object obj, Field cond, Field of)
        throws IllegalArgumentException, IllegalAccessException
    {
        ensureObj(obj);
        if (isFinal) {
            throwFinalFieldIllegalAccessException(of);
        }
        long fieldOffsetCond, fieldOffsetInt;
        if (Modifier.isStatic(cond.getModifiers()))
            fieldOffsetCond = unsafe.staticFieldOffset(cond);
        else
            fieldOffsetCond = unsafe.objectFieldOffset(cond);
        if (Modifier.isStatic(of.getModifiers()))
            fieldOffsetInt = unsafe.staticFieldOffset(of);
        else
            fieldOffsetInt = unsafe.objectFieldOffset(of);
        unsafe.condAssignInt(obj, fieldOffset, fieldOffsetCond, fieldOffsetInt);
    }

    public void setLong(Object obj, long l)
        throws IllegalArgumentException, IllegalAccessException
    {
        throwSetIllegalArgumentException(l);
    }

    public void condAssignLong(Object obj, Field cond, Field of)
        throws IllegalArgumentException, IllegalAccessException
    {
        throwSetIllegalArgumentException(of);
    }

    public void setFloat(Object obj, float f)
        throws IllegalArgumentException, IllegalAccessException
    {
        throwSetIllegalArgumentException(f);
    }

    public void condAssignFloat(Object obj, Field cond, Field of)
        throws IllegalArgumentException, IllegalAccessException
    {
        throwSetIllegalArgumentException(of);
    }

    public void setDouble(Object obj, double d)
        throws IllegalArgumentException, IllegalAccessException
    {
        throwSetIllegalArgumentException(d);
    }

    public void condAssignDouble(Object obj, Field cond, Field of)
        throws IllegalArgumentException, IllegalAccessException
    {
        throwSetIllegalArgumentException(of);
    }
}
