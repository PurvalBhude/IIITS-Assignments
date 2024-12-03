/**
 * Name: Purval Madhukar Bhude
 * Roll No. S20230010193
 * Lab 10 Question 1
 */

import java.io.*;
import java.util.*;

public class Q1_S20230010193 {
    private static String sourceFile = "input.txt";
    private static String targetFile = "output.txt";
    private static Scanner inputScanner = new Scanner(System.in);

    public static void main(String[] args) {
        try {
            createSourceFile();

            boolean keepRunning = true;
            while (keepRunning) {
                displayMenu();
                int selectedOption = inputScanner.nextInt();
                inputScanner.nextLine();
                
                switch (selectedOption) {
                    case 1:
                        transferLines();
                        break;
                    case 2:
                        transferWords();
                        break;
                    case 3:
                        transferCharacters();
                        break;
                    case 4:
                        displayFileContent();
                        break;
                    case 5:
                        calculateFileStats();
                        break;
                    case 6:
                        System.out.print("Enter the keyword to search: ");
                        String searchTerm = inputScanner.nextLine();
                        locateKeyword(searchTerm);
                        break;
                    case 7:
                        System.out.println("Exiting the program. Goodbye!");
                        keepRunning = false;
                        break;
                    default:
                        System.out.println("Invalid selection! Please choose again.");
                        break;
                }
            }
        } catch (Exception e) {
            System.out.println("An error occurred: " + e.getMessage());
            e.printStackTrace();
        } finally {
            inputScanner.close();
        }
    }

    private static void createSourceFile() throws IOException {
        PrintWriter fileWriter = new PrintWriter(new FileWriter(sourceFile));
        fileWriter.println("Name: John Doe");
        fileWriter.println("Roll No. S20230010193");
        fileWriter.println("OOPS Lab Project");
        fileWriter.println("Proud student at IIIT Sricity.");
        fileWriter.close();
    }

    private static void displayMenu() {
        System.out.println("\n=== Operations Menu ===");
        System.out.println("1. Copy by Lines");
        System.out.println("2. Copy by Words");
        System.out.println("3. Copy by Characters");
        System.out.println("4. Display Content");
        System.out.println("5. File Details");
        System.out.println("6. Find Keyword");
        System.out.println("7. Exit");
        System.out.print("Select an option: ");
    }

    private static void transferLines() throws IOException {
        BufferedReader fileReader = new BufferedReader(new FileReader(sourceFile));
        BufferedWriter fileWriter = new BufferedWriter(new FileWriter(targetFile));
        String currentLine;
        
        while ((currentLine = fileReader.readLine()) != null) {
            fileWriter.write(currentLine);
            fileWriter.newLine();
        }
        fileReader.close();
        fileWriter.close();
        System.out.println("Lines successfully transferred!");
    }

    private static void transferWords() throws IOException {
        BufferedReader fileReader = new BufferedReader(new FileReader(sourceFile));
        PrintWriter fileWriter = new PrintWriter(new FileWriter(targetFile));
        String currentLine;
        int wordsPerLine = 4;
        int wordCounter = 0;

        while ((currentLine = fileReader.readLine()) != null) {
            String[] wordArray = currentLine.split("\\s+");
            for (String word : wordArray) {
                fileWriter.print(word + " ");
                wordCounter++;
                if (wordCounter % wordsPerLine == 0) {
                    fileWriter.println();
                }
            }
        }
        fileReader.close();
        fileWriter.close();
        System.out.println("Words successfully transferred!");
    }

    private static void transferCharacters() throws IOException {
        FileInputStream inputFile = new FileInputStream(sourceFile);
        FileOutputStream outputFile = new FileOutputStream(targetFile);
        int charCounter = 0;
        int charsPerLine = 60;

        int data;
        while ((data = inputFile.read()) != -1) {
            outputFile.write(data);
            charCounter++;
            if (charCounter % charsPerLine == 0) {
                outputFile.write('\n');
            }
        }
        inputFile.close();
        outputFile.close();
        System.out.println("Characters successfully transferred!");
    }

    private static void displayFileContent() throws IOException {
        BufferedReader fileReader = new BufferedReader(new FileReader(targetFile));
        System.out.println("\n=== Content of File ===");
        String currentLine;
        int lineCounter = 1;

        while ((currentLine = fileReader.readLine()) != null) {
            System.out.printf("Line %d: %s%n", lineCounter++, currentLine);
        }
        fileReader.close();
    }

    private static void calculateFileStats() throws IOException {
        BufferedReader fileReader = new BufferedReader(new FileReader(targetFile));
        int totalLines = 0, totalWords = 0, totalChars = 0, specialCharCounter = 0;
        String currentLine;

        while ((currentLine = fileReader.readLine()) != null) {
            totalLines++;
            totalChars += currentLine.length();
            specialCharCounter += currentLine.replaceAll("[a-zA-Z0-9\\s]", "").length();
            totalWords += currentLine.split("\\s+").length;
        }
        fileReader.close();

        System.out.println("\n=== File Information ===");
        System.out.println("Lines Count: " + totalLines);
        System.out.println("Words Count: " + totalWords);
        System.out.println("Characters Count: " + totalChars);
        System.out.println("Special Characters Count: " + specialCharCounter);
        System.out.println("Alphanumeric Characters: " + (totalChars - specialCharCounter - totalLines));
    }

    private static void locateKeyword(String searchKey) throws IOException {
        BufferedReader fileReader = new BufferedReader(new FileReader(targetFile));
        String currentLine;
        int lineCounter = 1;
        int totalMatches = 0;
        StringBuilder matchingLines = new StringBuilder();

        while ((currentLine = fileReader.readLine()) != null) {
            String[] wordArray = currentLine.split("\\s+");
            int lineMatches = 0;

            for (String word : wordArray) {
                if (word.equalsIgnoreCase(searchKey)) {
                    lineMatches++;
                }
            }
            if (lineMatches > 0) {
                matchingLines.append(lineCounter).append(" ");
                totalMatches += lineMatches;
            }
            lineCounter++;
        }
        fileReader.close();

        System.out.println("\n=== Keyword Search Results ===");
        System.out.println("Keyword: '" + searchKey + "'");
        System.out.println("Total Matches: " + totalMatches);
        System.out.println("Located in lines: " + matchingLines.toString());
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
