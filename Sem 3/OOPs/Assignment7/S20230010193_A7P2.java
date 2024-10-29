import java.lang.*;

class Book {
    String title;
    String author;
    double price;

    public Book(String title, String author, double price) {
        this.title = title;
        this.author = author;
        this.price = price;
    }

    public void displayInfo() {
        System.out.println("Title: " + title);
        System.out.println("Author: " + author);
        System.out.println("Price: Rs." + price);
    }
}

class EBook extends Book {
    double fileSize;

    public EBook(String title, String author, double price, double fileSize) {
        super(title, author, price);
        this.fileSize = fileSize;
    }

    @Override
    public void displayInfo() {
        super.displayInfo();
        System.out.println("File Size: " + fileSize + " MB");
    }
}

final class PrintedBook extends Book {
    int numberOfPages;

    public PrintedBook(String title, String author, double price, int numberOfPages) {
        super(title, author, price);
        this.numberOfPages = numberOfPages;
    }

    @Override
    public void displayInfo() {
        super.displayInfo();
        System.out.println("Number of Pages: " + numberOfPages);
    }
}

public class S20230010193_A7P2{
    public static void main(String[] args) {
        EBook ebook = new EBook("whispers in the dark", "advait kulkarni", 999, 25);
        ebook.displayInfo();
        System.out.println();

        PrintedBook printedBook = new PrintedBook("monk who sold his farrari", "yash malve", 499, 48);
        printedBook.displayInfo();
    }
}
