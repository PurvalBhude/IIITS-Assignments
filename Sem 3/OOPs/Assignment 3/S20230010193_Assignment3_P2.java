/*
 * Name: Purval Madhukar Bhude
 * Roll No. S20230010193
 * Assignment 3 Question 1
 */

import java.util.*;

class Attribute {
    int integer;
    String string;
    char character;
    float float_;
    double double_;
    boolean bool;
    long long_integer;

    // Non-parameterized constructor
    Attribute() {
        this.integer = 0;
        this.string = "default";
        this.character = 'D';
        this.float_ = 0.0f;
        this.double_ = 0.0;
        this.bool = false;
        this.long_integer = 0L;
    }

    // Parameterized constructor with one parameter
    Attribute(int integer) {
        this();
        this.integer = integer;
    }

    // Parameterized constructor with two parameters
    Attribute(int integer, String string) {
        this(integer);
        this.string = string;
    }

    // Parameterized constructor with three parameters
    Attribute(int integer, String string, char character) {
        this(integer, string);
        this.character = character;
    }

    // display everything
    void display() {
        System.out.println("Integer: " + integer);
        System.out.println("String: " + string);
        System.out.println("Character: " + character);
        System.out.println("Float: " + float_);
        System.out.println("Double: " + double_);
        System.out.println("Boolean: " + bool);
        System.out.println("Long: " + long_integer);
    }
}

public class S20230010193_Assignment3_P2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Object created using the non-parameterized constructor:");
        Attribute obj1 = new Attribute();
        obj1.display();

        System.out.print("\nEnter an integer for one-parameter constructor: ");
        int integer = scanner.nextInt();
        Attribute obj2 = new Attribute(integer);
        obj2.display();

        System.out.print("\nEnter an integer and a string for two-parameter constructor: ");
        integer = scanner.nextInt();
        scanner.nextLine();
        String string = scanner.nextLine();
        Attribute obj3 = new Attribute(integer, string);
        obj3.display();

        System.out.print("\nEnter an integer, a string, and a character for three-parameter constructor: ");
        integer = scanner.nextInt();
        scanner.nextLine();
        string = scanner.nextLine();
        char character = scanner.next().charAt(0);
        Attribute obj4 = new Attribute(integer, string, character);
        obj4.display();
        scanner.close();
    }
}
