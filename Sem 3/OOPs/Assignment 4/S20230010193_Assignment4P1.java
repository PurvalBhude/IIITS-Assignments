/*
 * Name: Purval Madhukar Bhude
 * Roll no. S20230010193
 * Assignment 4 Problem 1
*/

class Purval {
    private int a;
    public int b;
    private int c;
    public int d;

    // Constructor
    Purval(int a, int b, int c, int d) {
        this.a = a;
        this.b = b;
        this.c = c;
        this.d = d;
    }

    // Overloaded compute methods

    // Method 1: Return the value of a
    int compute(int a) {
        return a;
    }

    // Method 2: Return the sum of two numbers
    int compute(int a, int b) {
        return a + b;
    }

    // Method 3: Return the sum of three numbers plus the instance variable 'd'
    int compute(int a, int b, int c) {
        return a + b + c + d;
    }

    // Method 4: Return the sum of four numbers
    int compute(int a, int b, int c, int d) {
        return a + b + c + d;
    }
}

public class S20230010193_Assignment4P1 {
    public static void main(String[] args) {
        Purval obj = new Purval(1, 2, 3, 4);

        System.out.println(obj.compute(5));          
        System.out.println(obj.compute(5, 10));       
        System.out.println(obj.compute(5, 10, 15));   
        System.out.println(obj.compute(5, 10, 15, 20)); 
    }
}
