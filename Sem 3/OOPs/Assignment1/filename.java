import java.util.Scanner;

// package com.apnacollege;

public class filename{
    public static void main(String[] args){
        int gen = (int)(Math.random()*100);
        System.out.println("guess the random number which is genrated");
        System.out.println("click -1 to exit");

        Scanner sc = new Scanner(System.in);
        int input;
        while (true) { 
            input = sc.nextInt();
            if(input == gen){
                System.out.println("you are the winner!!!");
                break;
            }
            else if(input>gen){
                System.out.println("think the number below it");
            }
            else{
                System.out.println("think the number above it");
            }

            if(input == -1){
                System.out.println("random was :"+ gen);
                break;
            }
        }
    }
}