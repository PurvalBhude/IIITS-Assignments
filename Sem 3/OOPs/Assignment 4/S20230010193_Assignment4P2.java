/*
 * Name: Purval Madhukar Bhude
 * Roll no. S20230010193
 * Assignment 4 Problem 2
*/

import java.util.Scanner;

public class S20230010193_Assignment4P2 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter the value of r: ");
        double r = scan.nextDouble();
        System.out.print("Enter the value of h: ");
        double h = scan.nextDouble();

        System.out.println("Cube Volume: " + cubeVolume(h));
        System.out.println("Cube Surface Area: " + cubeSurface(h));
        System.out.println("Sphere Volume: " + sphereVolume(r));
        System.out.println("Sphere Surface Area: " + sphereSurface(r));
        System.out.println("Cylinder Volume: " + cylinderVolume(r, h));
        System.out.println("Cylinder Surface Area: " + cylinderSurface(r, h));
        System.out.println("Cone Volume: " + coneVolume(r, h));
        System.out.println("Cone Surface Area: " + coneSurface(r, h));
    }

    public static double cubeVolume(double h) {
        return Math.pow(h, 3); // Volume = h^3
    }

    public static double cubeSurface(double h) {
        return 6 * Math.pow(h, 2); // Surface Area = 6 * h^2
    }

    public static double sphereVolume(double r) {
        return (4.0 / 3.0) * Math.PI * Math.pow(r, 3); // Volume = (4/3) * π * r^3
    }

    public static double sphereSurface(double r) {
        return 4 * Math.PI * Math.pow(r, 2); // Surface Area = 4 * π * r^2
    }

    public static double cylinderVolume(double r, double h) {
        return Math.PI * Math.pow(r, 2) * h; // Volume = π * r^2 * h
    }

    public static double cylinderSurface(double r, double h) {
        return 2 * Math.PI * r * (r + h); // Surface Area = 2 * π * r * (r + h)
    }

    public static double coneVolume(double r, double h) {
        return (1.0 / 3.0) * Math.PI * Math.pow(r, 2) * h; // Volume = (1/3) * π * r^2 * h
    }

    public static double coneSurface(double r, double h) {
        double slantHeight = Math.sqrt(Math.pow(r, 2) + Math.pow(h, 2)); // Slant height = √(r^2 + h^2)
        return Math.PI * r * (r + slantHeight); // Surface Area = π * r * (r + slant height)
    }
}
