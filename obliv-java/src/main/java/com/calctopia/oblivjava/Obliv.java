package org.javaparser.samples;

import java.lang.annotation.*;

/**
 * A field may be annotated as oblivious if it's going to be encrypted for securr
e computation
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

	@Obliv(0)
	public static final boolean trueCond = true;
}
