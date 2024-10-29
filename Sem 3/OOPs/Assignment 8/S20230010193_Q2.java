/**
 * Name: Purval Madhukar Bhude
 * Roll No. S20230010193
 * Assignment 8 Exercise 2
 */

abstract class BankAccont {
    String accountNumber;
    String accountHolder;
    double balance;

    BankAccont(String accountNumber, String accountHolder, double balance) {
        this.accountNumber = accountNumber;
        this.accountHolder = accountHolder;
        this.balance = balance;
    }

    abstract void deposit(double amount);
    abstract void withdraw(double amount);
    abstract void getBalance();
    abstract void getAccountDetails();
}

interface InterestBearing {
    double INTEREST_RATE = 0.05;

    void calculateInterest(double rate);
}

class SavingsAccount extends BankAccont implements InterestBearing {
    SavingsAccount(String accountNumber, String accountHolder, double balance) {
        super(accountNumber, accountHolder, balance);
    }

    @Override
    void deposit(double amount) {
        balance += amount;
        System.out.println("Deposited " + amount + " into SavingsAccount.");
    }

    @Override
    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            System.out.println("Withdrew " + amount + " from SavingsAccount.");
        } else {
            System.out.println("Insufficient balance in SavingsAccount.");
        }
    }

    @Override
    void getBalance() {
        System.out.println("SavingsAccount balance: " + balance);
    }

    @Override
    void getAccountDetails() {
        System.out.println("SavingsAccount Number: " + accountNumber);
        System.out.println("Account Holder: " + accountHolder);
        System.out.println("Balance: " + balance);
    }

    @Override
    public void calculateInterest(double rate) {
        double interest = balance * rate;
        balance += interest;
        System.out.println("Interest calculated: " + interest);
    }
}

class CurrentAccount extends BankAccont {
    double overdraftLimit;

    CurrentAccount(String accountNumber, String accountHolder, double balance, double overdraftLimit) {
        super(accountNumber, accountHolder, balance);
        this.overdraftLimit = overdraftLimit;
    }

    @Override
    void deposit(double amount) {
        balance += amount;
        System.out.println("Deposited " + amount + " into CurrentAccount.");
    }

    @Override
    void withdraw(double amount) {
        if (balance + overdraftLimit >= amount) {
            balance -= amount;
            System.out.println("Withdrew " + amount + " from CurrentAccount.");
        } else {
            System.out.println("Overdraft limit exceeded in CurrentAccount.");
        }
    }

    @Override
    void getBalance() {
        System.out.println("CurrentAccount balance: " + balance);
    }

    @Override
    void getAccountDetails() {
        System.out.println("CurrentAccount Number: " + accountNumber);
        System.out.println("Account Holder: " + accountHolder);
        System.out.println("Balance: " + balance);
        System.out.println("Overdraft Limit: " + overdraftLimit);
    }
}

class Bank {
    void performTransaction(BankAccont account) {
        account.deposit(1000);
        account.withdraw(500);
        account.getBalance();
    }
}

class S20230010193_Q2 {
    public static void main(String[] args) {
        Bank bank = new Bank();

        SavingsAccount savings = new SavingsAccount("001", "Purval", 2000);
        CurrentAccount current = new CurrentAccount("002", "Advait", 1500, 500);

        System.out.println("Performing transactions for SavingsAccount:");
        bank.performTransaction(savings);
        savings.calculateInterest(InterestBearing.INTEREST_RATE);
        savings.getAccountDetails();

        System.out.println("\nPerforming transactions for CurrentAccount:");
        bank.performTransaction(current);
        current.getAccountDetails();
    }
}