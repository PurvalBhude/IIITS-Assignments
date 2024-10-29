/*
 * Name: Purval Madhukar Bhude
 * Roll No. S20230010193
 * Assignment 3 Question 1
 */

import java.util.*;

class Account_Details {

    private int account_no;
    private String name;
    private String password;
    private float balance;

    void create(int account_no, String name, String password, float balance) {
        this.account_no = account_no;
        this.name = name;
        this.password = password;
        this.balance = balance;
    }

    int get_accountno() {
        return this.account_no;
    }

    String get_password() {
        return this.password;
    }

    float get_balance() {
        return this.balance;
    }

    void debit(float money) {
        if (balance >= money) {
            balance -= money;
            System.out.println("Money debited successfully! Current balance: " + balance);
        } else {
            System.out.println("Insufficient balance!");
        }
    }

    void credit(float money) {
        balance += money;
        System.out.println("Money credited successfully! Current balance: " + balance);
    }
}

public class S20230010193_Assignment3_P3 {

    public static void main(String[] args) {
        // Create 3 account objects
        Account_Details acc1 = new Account_Details();
        Account_Details acc2 = new Account_Details();
        Account_Details acc3 = new Account_Details();

        Scanner scan = new Scanner(System.in);
        int select;
        int account_no;
        String password;
        float money;
        String name;
        float balance;
        int i = 1;
        System.out.println("-- Welcome to Bank Dashboard --");

        while (true) {
            System.out.println("\nEnter the operation you want to perform:");
            System.out.println("1. Create account");
            System.out.println("2. Login to Bank Dashboard");
            System.out.println("3. Exit");
            System.out.print("Enter selection: ");
            select = scan.nextInt();
            if (select == 1) {
                System.out.print("Enter acc_no: ");
                account_no = scan.nextInt();
                scan.nextLine();
                System.out.print("Enter name: ");
                name = scan.nextLine();
                System.out.print("Enter password: ");
                password = scan.nextLine();
                System.out.print("Enter balance: ");
                balance = scan.nextFloat();
                scan.nextLine();

                if (i == 1) {
                    acc1.create(account_no, name, password, balance);
                } else if (i == 2) {
                    acc2.create(account_no, name, password, balance);
                } else if (i == 3) {
                    acc3.create(account_no, name, password, balance);
                }
                i++;
            }
            if (select == 2) {
                System.out.print("Enter Account Number: ");
                account_no = scan.nextInt();
                scan.nextLine();  // Consume the newline
                System.out.print("Enter Password: ");
                password = scan.nextLine();

                Account_Details currentAccount = null;

                // Check which account matches the input
                if (acc1.get_accountno() == account_no && acc1.get_password().equals(password)) {
                    currentAccount = acc1;
                } else if (acc2.get_accountno() == account_no && acc2.get_password().equals(password)) {
                    currentAccount = acc2;
                } else if (acc3.get_accountno() == account_no && acc3.get_password().equals(password)) {
                    currentAccount = acc3;
                }

                if (currentAccount != null) {
                    System.out.println("Login successful!");
                    while (true) {
                        System.out.println("\nSelect the operation:");
                        System.out.println("1. Debit");
                        System.out.println("2. Credit");
                        System.out.println("3. Logout");
                        System.out.print("Enter selection: ");
                        select = scan.nextInt();

                        if (select == 1) {
                            System.out.print("Enter the amount to be debited: ");
                            money = scan.nextFloat();
                            currentAccount.debit(money);
                        } else if (select == 2) {
                            System.out.print("Enter the amount to be credited: ");
                            money = scan.nextFloat();
                            currentAccount.credit(money);
                        } else if (select == 3) {
                            System.out.println("Logged out successfully!");
                            break;
                        } else {
                            System.out.println("Invalid selection, please try again.");
                        }
                    }
                } else {
                    System.out.println("Account number or password incorrect!");
                }
            } else if(select == 3) {
                System.out.println("Program end!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                break;
            }
        }
        scan.close();
    }
}
