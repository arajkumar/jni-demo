package demo;

public class Foo {
    static {
        System.loadLibrary("foo");
    }

    public static void main(String... args) {
        hello("Hello Native");
    }

    private static native void hello(String s);
}
