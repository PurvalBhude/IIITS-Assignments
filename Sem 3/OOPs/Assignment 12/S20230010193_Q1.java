/**
 * Name : Purval Madhukar Bhude
 * Roll No. S20230010193
 * OOPS Assignment 12 Question 1
 */

import java.lang.*;

// Class representing a bank account system
class BankAccountSystem {
    private double currentBalance; // The current balance of the account
    private String accountIdentifier; // The unique identifier for the account

    // Constructor to initialize account with an identifier and initial balance
    public BankAccountSystem(String accountIdentifier, double initialBalance) {
        this.accountIdentifier = accountIdentifier;
        this.currentBalance = initialBalance;
    }

    // Synchronized method to process withdrawals
    public synchronized boolean processWithdrawal(double withdrawalAmount, String userIdentifier) {
        System.out.println("\nUser " + userIdentifier + " attempting withdrawal...");
        System.out.println("Current balance before withdrawal: $" + currentBalance);

        // Check if sufficient funds are available
        if (currentBalance >= withdrawalAmount) {
            currentBalance -= withdrawalAmount; // Deduct the amount
            System.out.println("Withdrawal successful! Amount: $" + withdrawalAmount);
            System.out.println("Updated balance: $" + currentBalance);
            return true;
        } else {
            // Handle insufficient funds
            System.out.println("ERROR: Insufficient funds for withdrawal!");
            System.out.println("Requested amount: $" + withdrawalAmount);
            System.out.println("Available balance: $" + currentBalance);
            return false;
        }
    }

    // Synchronized method to process deposits
    public synchronized void processDeposit(double depositAmount, String userIdentifier) {
        System.out.println("\nUser " + userIdentifier + " making deposit...");
        System.out.println("Current balance before deposit: $" + currentBalance);
        currentBalance += depositAmount; // Add the deposit amount to the balance
        System.out.println("Deposit successful! Amount: $" + depositAmount);
        System.out.println("Updated balance: $" + currentBalance);
    }

    // Method to retrieve the current balance (non-synchronized for read-only access)
    public double retrieveBalance() {
        return currentBalance;
    }
}

class BasicCalculator {
    public double add(double number1, double number2) {
        return number1 + number2;
    }
    public double subtract(double number1, double number2) {
        return number1 - number2;
    }
    public double multiply(double number1, double number2) {
        return number1 * number2;
    }
    public double divide(double number1, double number2) {
        if (number2 == 0) {
            System.out.println("Error: Division by zero is undefined.");
            return 0;
        }
        return number1 / number2;
    }
}

// Class representing a bank user, implementing Runnable for multithreading
class BankUser implements Runnable {
    private BankAccountSystem bankAccount; // Shared bank account
    private String userIdentifier; // Identifier for the user
    private int maxTransactions; // Maximum number of transactions a user can perform

    // Constructor to initialize the user and their transaction limit
    public BankUser(BankAccountSystem bankAccount, String userIdentifier, int maxTransactions) {
        this.bankAccount = bankAccount;
        this.userIdentifier = userIdentifier;
        this.maxTransactions = maxTransactions;
    }

    @Override
    public void run() {
        int transactionCount = 0; // Track the number of transactions
        do {
            // Randomly choose between deposit and withdrawal
            if (Math.random() < 0.5) {
                // Generate a random withdrawal amount
                double withdrawalAmount = Math.round(Math.random() * 100 * 100.0) / 100.0;
                bankAccount.processWithdrawal(withdrawalAmount, userIdentifier);
            } else {
                // Generate a random deposit amount
                double depositAmount = Math.round(Math.random() * 100 * 100.0) / 100.0;
                bankAccount.processDeposit(depositAmount, userIdentifier);
            }

            // Add small delay between transactions to simulate real-world conditions
            try {
                Thread.sleep(500); // Pause for 500 milliseconds
            } catch (InterruptedException e) {
                System.out.println("Transaction interrupted for user: " + userIdentifier);
            }
            transactionCount++; // Increment the transaction count
        } while (transactionCount < maxTransactions); // Repeat until max transactions are reached
    }
}

// Main class to simulate the bank system
public class S20230010193_Q1 {
    public static void main(String[] args) {
        // Initialize a shared bank account with $1000
        BankAccountSystem sharedAccount = new BankAccountSystem("ACCT001", 1000.0);

        // Number of users and transactions per user
        int numberOfUsers = 3;
        int transactionsPerUser = 5;
        Thread[] userThreads = new Thread[numberOfUsers]; // Array to hold user threads

        // Start threads for each user
        for (int i = 0; i < numberOfUsers; i++) {
            userThreads[i] = new Thread(new BankUser(sharedAccount, "USER" + (i + 1), transactionsPerUser));
            userThreads[i].start(); // Start the thread
        }

        // Wait for all threads to complete
        try {
            for (Thread thread : userThreads) {
                thread.join(); // Main thread waits for each user thread to finish
            }
        } catch (InterruptedException e) {
            System.out.println("Main thread interrupted!");
        }

        // Display the final balance after all transactions
        System.out.println("\n=== FINAL ACCOUNT BALANCE ===");
        System.out.println("Balance: $" + sharedAccount.retrieveBalance());
    }
}
