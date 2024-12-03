/**
 * Name: Purval Madhukar Bhude
 * Roll No. S20230010193
 * Assignment 11 Question 2
 */

import java.util.*;

class BookEntity {
    private String uniqueIsbn;
    private String bookTitle;
    private String authorName;
    
    public BookEntity(String uniqueIsbn, String bookTitle, String authorName) {
        this.uniqueIsbn = uniqueIsbn;
        this.bookTitle = bookTitle;
        this.authorName = authorName;
    }
    
    // Getters and setters with unique names
    public String fetchIsbn() { return uniqueIsbn; }
    public String fetchTitle() { return bookTitle; }
    public String fetchAuthor() { return authorName; }
    
    public void updateTitle(String newTitle) { this.bookTitle = newTitle; }
    public void updateAuthor(String newAuthor) { this.authorName = newAuthor; }
    
    @Override
    public String toString() {
        return String.format("ISBN: %s | Title: %s | Author: %s", 
            uniqueIsbn, bookTitle, authorName);
    }
}

class LibraryManager {
    private Map<String, BookEntity> bookInventory;
    private int modificationCounter;
    
    public LibraryManager() {
        this.bookInventory = new TreeMap<>();  // Using TreeMap for automatic sorting by ISBN
        this.modificationCounter = 0;
    }
    
    public void catalogBook(String uniqueIsbn, String bookTitle, String authorName) {
        boolean isNewBook = !bookInventory.containsKey(uniqueIsbn);
        
        while (true) {
            try {
                if (uniqueIsbn == null || uniqueIsbn.trim().isEmpty()) {
                    throw new IllegalArgumentException("Invalid ISBN provided");
                }
                
                if (isNewBook) {
                    bookInventory.put(uniqueIsbn, new BookEntity(uniqueIsbn, bookTitle, authorName));
                    System.out.println("New book added successfully!");
                } else {
                    BookEntity existingBook = bookInventory.get(uniqueIsbn);
                    existingBook.updateTitle(bookTitle);
                    existingBook.updateAuthor(authorName);
                    System.out.println("Existing book updated successfully!");
                }
                modificationCounter++;
                break;
                
            } catch (IllegalArgumentException e) {
                System.out.println("Error: " + e.getMessage());
                break;
            }
        }
    }
    
    public boolean withdrawBook(String uniqueIsbn) {
        boolean removalStatus = false;
        
        while (true) {
            if (bookInventory.containsKey(uniqueIsbn)) {
                bookInventory.remove(uniqueIsbn);
                modificationCounter++;
                removalStatus = true;
                System.out.println("Book successfully removed from inventory");
            } else {
                System.out.println("Book with ISBN " + uniqueIsbn + " not found in inventory");
            }
            break;
        }
        
        return removalStatus;
    }
    
    public String locateBook(String uniqueIsbn) {
        String searchResult = "Book not found";
        
        while (true) {
            BookEntity foundBook = bookInventory.get(uniqueIsbn);
            if (foundBook != null) {
                searchResult = foundBook.toString();
            }
            break;
        }
        
        return searchResult;
    }
    
    public List<String> generateInventoryReport() {
        List<String> inventoryList = new ArrayList<>();
        
        while (!bookInventory.isEmpty()) {
            for (BookEntity book : bookInventory.values()) {
                inventoryList.add(book.toString());
            }
            break;
        }
        
        return inventoryList;
    }
    
    public int getModificationCount() {
        return modificationCounter;
    }
}

// Example usage
public class Q2_S20230010193 {
    public static void main(String[] args) {
        LibraryManager libraryManager = new LibraryManager();
        
        // Add some books
        libraryManager.catalogBook("978-0123456789", "The Art of Programming", "John Smith");
        libraryManager.catalogBook("978-9876543210", "Data Structures Unleashed", "Jane Doe");
        
        // Update an existing book
        libraryManager.catalogBook("978-0123456789", "The Art of Clean Programming", "John Smith");
        
        // Find a book
        System.out.println(libraryManager.locateBook("978-0123456789"));
        
        // List all books
        List<String> inventory = libraryManager.generateInventoryReport();
        System.out.println("\nCurrent Library Inventory:");
        for (String bookInfo : inventory) {
            System.out.println(bookInfo);
        }
        
        // Remove a book
        libraryManager.withdrawBook("978-9876543210");
        
        // Check modification count
        System.out.println("\nTotal modifications made: " + libraryManager.getModificationCount());
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