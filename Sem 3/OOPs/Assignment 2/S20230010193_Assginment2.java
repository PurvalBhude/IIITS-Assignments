/*
Name: Purval Madhukar Bhude
Roll No. S20230010193
Subject : OOPS
Assgniment 2
 */

import java.util.Scanner;

//creating employee class
class employee {

    String Name;
    String employeeID;
    double Basic_Salary;
    int allowance_percentage;
    boolean loan_eligibility;
    float Leaves;

    //creating methods for class
    double calculateSalary() {
        return (Basic_Salary + ((allowance_percentage * Basic_Salary) / 100));
    }

    void DisplayEmployeeByRecords() {
        System.out.print("Name: "+Name+"\nEmployeeID: " + employeeID + "\nBasic Salary: " + Basic_Salary + "\nAllowance Percentage: " + allowance_percentage + "\nLoan Eligibility: " + loan_eligibility + "\nleaves: " + Leaves);
    }

    float ShowNoOfLeaves() {
        return Leaves;
    }
}

public class S20230010193_Assginment2 {

    //creating function to call all list of employee

    public static void listemployee(employee[] emp, int n) {
        for (int i = 0; i < n; i++) {
            emp[i].DisplayEmployeeByRecords();
            System.out.println("\nSalary including allowance: " + emp[i].calculateSalary() + "\n");
        }
    }

    //creating main class
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter number of employee you want to enter: ");
        int n = scan.nextInt();
        scan.nextLine();
        employee[] emp = new employee[n];

        System.out.println("Enter the details");

        for (int i = 0; i < n; i++) {
            emp[i] = new employee();
            System.out.println("Enter Employee " + (i + 1) + " Details \n");
            System.out.print("enter Name: ");
            emp[i].Name = scan.nextLine();
            System.out.print("enter employee ID: ");
            emp[i].employeeID = scan.nextLine();
            System.out.print("enter Basic Salary: ");
            emp[i].Basic_Salary = scan.nextFloat();
            System.out.print("enter Allowance Percentage: ");
            emp[i].allowance_percentage = scan.nextInt();
            System.out.print("enter Loan Eligibility (true/false): ");
            emp[i].loan_eligibility = scan.nextBoolean();
            System.out.print("enter Leaves: ");
            emp[i].Leaves = scan.nextFloat();
            scan.nextLine();
        }

        System.out.println("\ndisplaying Employee Detials using created methods \n");

        listemployee(emp, n);
    }

}
