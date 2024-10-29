/*
 * Name: Purval Madhukar Bhude
 * Roll no. S20230010193
 * Assignment 4 Problem 5
*/

import java.util.Scanner;

public class S20230010193_Assignment4P5{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter the data value");
        System.err.print("Enter a: ");
        int a = scan.nextInt();
        System.err.print("Enter b: ");
        int b = scan.nextInt();
        System.err.print("Enter c: ");
        int c = scan.nextInt();
        System.err.print("Enter d: ");
        int d = scan.nextInt();
        
        System.out.println("maximum element is "+ maximum(a,b,c,d));
    }
    static int maximum(int a,int b,int c,int d){
        int max = a;
        if(max<b){
            max=b;
        }
        if(max<c){
            max=c;
        }
        if(max<d){
            max=d;
        }
        return max;
    }
}