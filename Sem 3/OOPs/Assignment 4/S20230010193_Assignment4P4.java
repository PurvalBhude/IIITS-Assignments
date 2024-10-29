/*
 * Name: Purval Madhukar Bhude
 * Roll no. S20230010193
 * Assignment 4 Problem 4
*/

public class S20230010193_Assignment4P4 {
    // Instance variables
    private int a;
    private int b;

    // Constructor to initialize instance variables
    public S20230010193_Assignment4P4(int a, int b) {
        this.a = a;
        this.b = b;
    }

    // Method without parameters but with return type
    public int methodWithoutParameter() {
        return a + b;
    }

    // Method with two parameters and a return type
    public int methodWith2Parameter(int x, int y) {
        return (x + y);
    }

    // Method without parameters and without return type
    public void methodWithoutParameterAndReturnType() {
        System.out.println("This method has no parameters and no return type.");
    }

    // Static method that accepts data and returns a result
    public static int staticMethod(int x, int y) {
        return x * y;
    }

    // Method that can access instance variables
    public int accessInstanceVariables() {
        return this.a * this.b;
    }

    public static void main(String[] args) {
        S20230010193_Assignment4P4 obj = new S20230010193_Assignment4P4(999, 1);

        System.out.println("Method without parameters but with return type: " + obj.methodWithoutParameter());
        System.out.println("Method with two parameters and a return type: " + obj.methodWith2Parameter(3, 7));
        obj.methodWithoutParameterAndReturnType();
        System.out.println("Static method result: " + S20230010193_Assignment4P4.staticMethod(2, 3));
        System.out.println("Accessing instance variables: " + obj.accessInstanceVariables());
    }
}
