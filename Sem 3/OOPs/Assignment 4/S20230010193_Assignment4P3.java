/*
 * Name: Purval Madhukar Bhude
 * Roll no. S20230010193
 * Assignment 4 Problem 3
*/

import java.util.Scanner;

public class S20230010193_Assignment4P3 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter value of radius: ");
        double radius = scan.nextDouble();
        double area = Math.PI * radius * radius;

        System.out.printf("The area of the circle is: %f\n", area);
        System.out.printf("Formatted Area: %010.2f\n", area);
    }
}
