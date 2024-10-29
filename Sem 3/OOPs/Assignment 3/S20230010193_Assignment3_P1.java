/*
 * Name: Purval Madhukar Bhude
 * Roll No. S20230010193
 * Assignment 3 Question 1
 */

import java.util.Scanner;

class student {

    private int roll_no;
    private String name;
    private float grade;
    private int year_of_study;
    private String branch;

    int getrollno() {
        return this.roll_no;
    }

    String getname() {
        return this.name;
    }

    float getgrade() {
        return this.grade;
    }

    int getyearofstudy() {
        return this.year_of_study;
    }

    String getbranch() {
        return this.branch;
    }

    void init() {
        this.roll_no = 0;
        this.name = "";
        this.grade = 0.0f;
        this.year_of_study = 0;
        this.branch = "";
    }

    void init_value(int roll_no, String name, float grade, int year_of_study, String branch) {
        this.roll_no = roll_no;
        this.name = name;
        this.grade = grade;
        this.year_of_study = year_of_study;
        this.branch = branch;
    }

}

public class S20230010193_Assignment3_P1 {

    public static void main(String[] args) {
        student[] student = new student[3];

        Scanner scan = new Scanner(System.in);

        int roll_no;
        String name;
        float grade;
        int year_of_study;
        String branch;

        for (int i = 0; i < 3; i++) {
            System.err.println("\nEnter student " + (i + 1) + " details\n");
            student[i] = new student();
            student[i].init();
            System.out.print("Enter name: ");
            name = scan.nextLine();
            System.out.print("Enter roll no: ");
            roll_no = scan.nextInt();
            System.out.print("Enter grade: ");
            grade = scan.nextFloat();
            System.out.print("Enter year of study: ");
            year_of_study = scan.nextInt();
            scan.nextLine();
            System.out.print("Enter branch: ");
            branch = scan.nextLine();
            student[i].init_value(roll_no, name, grade, year_of_study, branch);
        }

        // student topper = student[0];
        // if(student[1].getgrade()>topper.getgrade()){
        //     topper = student[1];
        // }
        // else if(student[2].getgrade()>topper.getgrade()){
        //     topper = student[2];
        // }
        // System.out.println("\n-- details of topper student --\n");
        // System.out.println("roll-no: "+ topper.getrollno());
        // System.out.println("name: "+ topper.getname());
        // System.out.println("grade: "+ topper.getgrade());
        // System.out.println("year_of_study: "+ topper.getyearofstudy());
        // System.out.println("branch: "+ topper.getbranch());
        scan.close();

    }
}
