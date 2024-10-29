
import java.util.Scanner;

class character{
    char a;

    character(char a) {
        this.a = a;
    }

    void nextchar(){
        (this.a)++;
    }
    
}

public class Purval_Exam{
    public static void main(String args[]){
    Scanner scan = new Scanner(System.in);
    Character c = scan.next().charAt(0);
    // nextchar(c);
    // System.out.println("next is (using nextchar wrapper function) "+ c);

    character a = new character(c);
    a.nextchar();
    System.out.println("next is (using nextchar wrapper function) "+ a.a);

    }
    static void nextchar(Character ch){
        ch++;
    }

}