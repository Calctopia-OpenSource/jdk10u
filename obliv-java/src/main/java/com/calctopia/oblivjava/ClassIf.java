package org.javaparser.samples;

public class ClassIf {

    @Obliv(1)
    static int x;
    @Obliv(2)
    static int y;
    @Obliv(0)
    static int z;

    @Obliv(1)
    static boolean a;

    public void testIF() {
	if (x>y) {
		z=x+y;
		z=y-x;
	} else {
		z=x-y;
	}
    }
}
