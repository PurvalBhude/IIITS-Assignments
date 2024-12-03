/**
 * Name : Purval Madhukar Bhude
 * Roll No. S20230010193
 * OOPS Assignment 12 Question 2
 */

import java.lang.*;
import java.util.*;

// Enum to define file categories with corresponding priority levels
enum FileCategory {
    IMAGE("Image", Thread.MAX_PRIORITY), // Image files get highest priority
    DOCUMENT("Document", Thread.NORM_PRIORITY), // Document files get normal priority
    VIDEO("Video", Thread.MIN_PRIORITY); // Video files get lowest priority

    private final String categoryName; // Category name of the file
    private final int priorityLevel; // Priority level assigned to the category

    // Constructor for FileCategory
    FileCategory(String categoryName, int priorityLevel) {
        this.categoryName = categoryName;
        this.priorityLevel = priorityLevel;
    }

    // Getter for category name
    public String getCategoryName() {
        return categoryName;
    }

    // Getter for priority level
    public int getPriorityLevel() {
        return priorityLevel;
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

// Class representing a file to be processed
class ProcessableFile {
    private String fileName; // Name of the file
    private FileCategory fileCategory; // Category of the file
    private int processingDuration; // Processing time in milliseconds

    // Constructor to initialize file properties
    public ProcessableFile(String fileName, FileCategory fileCategory, int processingDuration) {
        this.fileName = fileName;
        this.fileCategory = fileCategory;
        this.processingDuration = processingDuration;
    }

    // Getter for file name
    public String getFileName() {
        return fileName;
    }

    // Getter for file category
    public FileCategory getFileCategory() {
        return fileCategory;
    }

    // Getter for processing duration
    public int getProcessingDuration() {
        return processingDuration;
    }
}

// Thread class to handle processing of individual files
class FileProcessor extends Thread {
    private ProcessableFile fileToProcess; // File being processed
    private static final Object statusLock = new Object(); // Lock for synchronized status updates
    private boolean isProcessingComplete = false; // Flag for completion status
    private int processAttempts = 0; // Number of attempts made
    private final int maxAttempts; // Maximum allowed attempts

    // Constructor to initialize file processor
    public FileProcessor(ProcessableFile fileToProcess, int maxAttempts) {
        this.fileToProcess = fileToProcess;
        this.maxAttempts = maxAttempts;
        setPriority(fileToProcess.getFileCategory().getPriorityLevel()); // Set thread priority
    }

    // Helper method to display synchronized status messages
    private void displayProcessingStatus(String message) {
        synchronized (statusLock) {
            System.out.println(String.format("[%s] %s - %s (Priority: %d)",
                    Thread.currentThread().getName(),
                    fileToProcess.getFileCategory().getCategoryName(),
                    message,
                    getPriority()));
        }
    }

    // Overriding the run method to handle file processing
    @Override
    public void run() {
        do {
            try {
                processAttempts++; // Increment attempts
                displayProcessingStatus("Starting to process " + fileToProcess.getFileName());

                // Simulate processing by sleeping for the given duration
                Thread.sleep(fileToProcess.getProcessingDuration());

                displayProcessingStatus("Successfully processed " + fileToProcess.getFileName());
                isProcessingComplete = true; // Mark as completed

            } catch (InterruptedException e) {
                displayProcessingStatus("Processing interrupted for " + fileToProcess.getFileName());
            }
        } while (!isProcessingComplete && processAttempts < maxAttempts); // Retry if not completed

        if (!isProcessingComplete) {
            displayProcessingStatus("Failed to process " + fileToProcess.getFileName() +
                                 " after " + maxAttempts + " attempts");
        }
    }
}

// Class to manage the monitoring of file processing
class FileProcessingMonitor {
    private static final int DEFAULT_MAX_ATTEMPTS = 3; // Default max attempts for each file

    // Method to monitor and manage file processing threads
    public void monitorFileProcessing(List<ProcessableFile> filesToProcess) {
        ArrayList<FileProcessor> activeProcessors = new ArrayList<>(); // List of active threads

        // Create and start threads for each file
        for (ProcessableFile file : filesToProcess) {
            FileProcessor processor = new FileProcessor(file, DEFAULT_MAX_ATTEMPTS);
            activeProcessors.add(processor);
            processor.start(); // Start thread
        }

        // Wait for all threads to complete
        for (FileProcessor processor : activeProcessors) {
            try {
                processor.join(); // Wait for thread to finish
            } catch (InterruptedException e) {
                System.out.println("Monitoring interrupted for: " + processor.getName());
            }
        }
    }
}

// Main class to demonstrate the file processing system
public class S20230010193_Q2 {
    public static void main(String[] args) {
        // Create a list of sample files for processing
        List<ProcessableFile> filesToProcess = Arrays.asList(
            new ProcessableFile("vacation.jpg", FileCategory.IMAGE, 1000),
            new ProcessableFile("report.pdf", FileCategory.DOCUMENT, 2000),
            new ProcessableFile("tutorial.mp4", FileCategory.VIDEO, 3000),
            new ProcessableFile("profile.png", FileCategory.IMAGE, 1500),
            new ProcessableFile("contract.docx", FileCategory.DOCUMENT, 2500),
            new ProcessableFile("presentation.pptx", FileCategory.DOCUMENT, 1800),
            new ProcessableFile("lecture.mp4", FileCategory.VIDEO, 3500)
        );

        // Display initial system information
        System.out.println("=== Starting File Processing System ===");
        System.out.println("Number of files to process: " + filesToProcess.size());
        System.out.println("Processing priorities:");
        for (FileCategory category : FileCategory.values()) {
            System.out.println(category.getCategoryName() + ": Priority " + 
                             category.getPriorityLevel());
        }
        System.out.println("\n=== Beginning File Processing ===\n");

        // Start the monitoring of file processing
        FileProcessingMonitor monitor = new FileProcessingMonitor();
        monitor.monitorFileProcessing(filesToProcess);

        // Display completion message
        System.out.println("\n=== File Processing Complete ===");
    }
}
