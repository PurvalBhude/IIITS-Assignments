/**
 * Name: Purval Madhukar Bhude
 * Roll No. S20230010193
 * Lab 10 Question 2
 */

import java.io.*;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.*;

// TransactionRecord class
class TransactionRecord implements Serializable {
    private static final long serialVersionUID = 1L;
    private int accountNumber;
    private double amount;
    private LocalDateTime transactionDate;

    public TransactionRecord(int accountNumber, double amount) {
        this.accountNumber = accountNumber;
        this.amount = amount;
        this.transactionDate = LocalDateTime.now();
    }

    // Getters and setters
    public int getAccountNumber() { return accountNumber; }
    public double getAmount() { return amount; }
    public LocalDateTime getTransactionDate() { return transactionDate; }

    @Override
    public String toString() {
        return String.format("Account: %d, Amount: $%.2f, Date: %s", 
            accountNumber, amount, transactionDate.format(DateTimeFormatter.ISO_LOCAL_DATE_TIME));
    }
}

// AccountRecord class
class AccountRecord implements Serializable {
    private static final long serialVersionUID = 1L;
    private int accountNumber;
    private String firstName;
    private String lastName;
    private double balance;
    private LocalDateTime lastUpdated;

    public AccountRecord(int accountNumber, String firstName, String lastName, double balance) {
        this.accountNumber = accountNumber;
        this.firstName = firstName;
        this.lastName = lastName;
        this.balance = balance;
        this.lastUpdated = LocalDateTime.now();
    }

    // Method to combine transaction into account balance
    public void combine(TransactionRecord transaction) {
        if (transaction.getAccountNumber() != this.accountNumber) {
            throw new IllegalArgumentException("Account numbers do not match");
        }
        this.balance += transaction.getAmount();
        this.lastUpdated = LocalDateTime.now();
    }

    // Getters and toString
    public int getAccountNumber() { return accountNumber; }
    public String getFirstName() { return firstName; }
    public String getLastName() { return lastName; }
    public double getBalance() { return balance; }
    public LocalDateTime getLastUpdated() { return lastUpdated; }

    @Override
    public String toString() {
        return String.format("Account: %d, Name: %s %s, Balance: $%.2f, Last Updated: %s",
            accountNumber, firstName, lastName, balance,
            lastUpdated.format(DateTimeFormatter.ISO_LOCAL_DATE_TIME));
    }
}

// FileMatch class for file-matching functionality
class FileMatch {
    private final String logFile;
    private Map<Integer, AccountRecord> masterRecords;
    private List<String> errorLog;

    public FileMatch(String logFile) {
        this.logFile = logFile;
        this.masterRecords = new HashMap<>();
        this.errorLog = new ArrayList<>();
    }

    public void processFiles(String oldMasterFile, String transactionFile, String newMasterFile) {
        try {
            loadMasterFile(oldMasterFile);
            processTransactions(transactionFile);
            writeNewMasterFile(newMasterFile);
            writeLogFile();
        } catch (IOException | ClassNotFoundException e) {
            System.err.println("Error processing files: " + e.getMessage());
            errorLog.add("Critical error: " + e.getMessage());
            writeLogFile();
        }
    }

    private void loadMasterFile(String filename) throws IOException, ClassNotFoundException {
        try (ObjectInputStream input = new ObjectInputStream(new FileInputStream(filename))) {
            while (true) {
                try {
                    AccountRecord record = (AccountRecord) input.readObject();
                    masterRecords.put(record.getAccountNumber(), record);
                } catch (EOFException e) {
                    break;
                }
            }
        }
    }

    private void processTransactions(String filename) throws IOException, ClassNotFoundException {
        try (ObjectInputStream input = new ObjectInputStream(new FileInputStream(filename))) {
            while (true) {
                try {
                    TransactionRecord trans = (TransactionRecord) input.readObject();
                    processTransaction(trans);
                } catch (EOFException e) {
                    break;
                }
            }
        }
    }

    private void processTransaction(TransactionRecord trans) {
        AccountRecord account = masterRecords.get(trans.getAccountNumber());
        if (account == null) {
            errorLog.add(String.format("Unmatched transaction record for account number: %d, Amount: $%.2f, Date: %s",
                trans.getAccountNumber(), trans.getAmount(), 
                trans.getTransactionDate().format(DateTimeFormatter.ISO_LOCAL_DATE_TIME)));
            return;
        }

        try {
            account.combine(trans);
        } catch (IllegalStateException e) {
            errorLog.add(String.format("Failed to process transaction for account %d: %s",
                trans.getAccountNumber(), e.getMessage()));
        }
    }

    private void writeNewMasterFile(String filename) throws IOException {
        try (ObjectOutputStream output = new ObjectOutputStream(new FileOutputStream(filename))) {
            List<AccountRecord> sortedRecords = new ArrayList<>(masterRecords.values());
            sortedRecords.sort(Comparator.comparingInt(AccountRecord::getAccountNumber));
            
            for (AccountRecord record : sortedRecords) {
                output.writeObject(record);
            }
        }
    }

    private void writeLogFile() {
        try (PrintWriter writer = new PrintWriter(new FileWriter(logFile))) {
            writer.println("Processing Log - " + LocalDateTime.now());
            writer.println("----------------------------------------");
            
            if (errorLog.isEmpty()) {
                writer.println("No errors or unmatched transactions found.");
            } else {
                errorLog.forEach(writer::println);
            }
        } catch (IOException e) {
            System.err.println("Error writing to log file: " + e.getMessage());
        }
    }
}

// TestDataGenerator class to create test files
class TestDataGenerator {
    public static void main(String[] args) {
        try {
            generateMasterFile("oldmast.txt");
            generateTransactionFile("trans.txt");
            System.out.println("Test data generated successfully!");
        } catch (IOException e) {
            System.err.println("Error generating test data: " + e.getMessage());
        }
    }

    private static void generateMasterFile(String filename) throws IOException {
        try (ObjectOutputStream output = new ObjectOutputStream(new FileOutputStream(filename))) {
            AccountRecord[] accounts = {
                new AccountRecord(1000, "Purval Bhude", "Advait", 140),
                new AccountRecord(2000, "yash", "advait", 240),
                new AccountRecord(3000, "Shyam modi", "yash", 55),
                new AccountRecord(4000, "advait", "vinneet", 10000)
            };

            for (AccountRecord account : accounts) {
                output.writeObject(account);
            }
        }
    }

    private static void generateTransactionFile(String filename) throws IOException {
        try (ObjectOutputStream output = new ObjectOutputStream(new FileOutputStream(filename))) {
            TransactionRecord[] transactions = {
                new TransactionRecord(1000, 50.25),
                new TransactionRecord(2000, -25.50),
                new TransactionRecord(3000, 100.00),
                new TransactionRecord(5000, 75.25)  // Unmatched transaction
            };

            for (TransactionRecord transaction : transactions) {
                output.writeObject(transaction);
            }
        }
    }
}

// Main application class
public class Q2_S20230010193 {
    public static void main(String[] args) {
        // Generate test data
        TestDataGenerator.main(args);

        // Process the files
        FileMatch matcher = new FileMatch("log.txt");
        matcher.processFiles("oldmast.txt", "trans.txt", "newmast.txt");
        
        System.out.println("File processing completed. Check log.txt for any errors or unmatched transactions.");
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
