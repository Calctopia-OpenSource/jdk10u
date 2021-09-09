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

import jdk.internal.misc.Unsafe;
import java.lang.String;

/**
 * General configuration for Secure Computation
 */
public class SecureComputation  {

	/**
	 * Initialise secure computation
	 *
	 * @param party Number identifying the party (0-2)
	 * @param port	Port number
	 * @param destIP Destination IP address
	 */
	public static void initSecureComputation(String party, String port, String destIP)
	{
		Unsafe.getUnsafe().initSecureComputation(party, port, destIP);
	}

	/**
	 * Stop secure computation
	 */
	public static void stopSecureComputation()
	{
		Unsafe.getUnsafe().stopSecureComputation();
	}
}
