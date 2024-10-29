/*
* Name : Purval Madhukar Bhude
* Roll No. S20230010193
*/

import Datestore.Date;
import java.util.Scanner;

class EmailAccount {
    String UserName;
    String Password;
    String[] Send_Message;
    Date DateofBirth; 
    String[] Recieve_Message;
    static int totalnumberofaccounts = 0;
    int sendIndex = 0;
    int receiveIndex = 0;

    EmailAccount(String User, String Pass, Date dob) {
        this.UserName = User;
        this.Password = Pass;
        this.DateofBirth = dob;
        this.Send_Message = new String[10];
        this.Recieve_Message = new String[10];
        totalnumberofaccounts++;
    }

    void update_Account(String user, String oldpass, String newpass) {
        if (this.UserName.equals(user) && this.Password.equals(oldpass)) {
            this.Password = newpass;
            System.out.println("Password updated successfully!");
        } else {
            System.out.println("Invalid username or password!");
        }
    }

    void checkMsg(String user, String pass) {
        if (this.UserName.equals(user) && this.Password.equals(pass)) {
            System.out.println("Received Messages:");
            for (String msg : Recieve_Message) {
                if (msg != null) {
                    System.out.println(msg);
                }
            }
        } else {
            System.out.println("Invalid username or password!");
        }
    }

    void SendMsg(String user, String pass, EmailAccount receiver, String message) {
        if (this.UserName.equals(user) && this.Password.equals(pass)) {
            if (sendIndex < Send_Message.length) {
                Send_Message[sendIndex++] = message;
            } else {
                System.out.println("Send message storage full!");
            }

            if (receiver.receiveIndex < receiver.Recieve_Message.length) {
                receiver.Recieve_Message[receiver.receiveIndex++] = message;
            } else {
                System.out.println("Receiver's message storage full!");
            }

            System.out.println("Message sent successfully!");
        } else {
            System.out.println("Invalid username or password!");
        }
    }

    void printAccountDetails() {
        System.out.println("UserName: " + UserName+"\n");
        DateofBirth.printvalue();
        System.out.println("\nTotal Messages Sent: " + sendIndex);
        System.out.println("Total Messages Received: " + receiveIndex+"\n\n");
    }
}

public class S20230010193_A5P2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        EmailAccount[] accounts = new EmailAccount[3];
        for (int i = 0; i < accounts.length; i++) {
            System.out.println("Enter Username for Account " + (i + 1) + ": ");
            String user = sc.nextLine();
            System.out.println("Enter Password for Account " + (i + 1) + ": ");
            String pass = sc.nextLine();
            Date dob = new Date();
            accounts[i] = new EmailAccount(user, pass, dob);
        }

        // Display account details of all accounts
        System.out.println("\nAccount Details:");
        for (EmailAccount account : accounts) {
            account.printAccountDetails();
        }

        // Example usage of sending messages between accounts
        accounts[0].SendMsg(accounts[0].UserName, accounts[0].Password, accounts[1], "Hello from Account 1!");
        accounts[1].checkMsg(accounts[1].UserName, accounts[1].Password);
    }
}
