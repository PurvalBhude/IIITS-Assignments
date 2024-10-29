import java.util.Scanner;

public class Q2_S20230010193 {    

    void stringexception(String input) throws Exception {
        if (!input.matches(".*[aeiouAEIOU].*")) {
            throw new Exception("No vowels found in the string.");
        }
    }

    void checkDuplicates(int[] numbers) throws Exception {
        for (int i = 0; i < numbers.length; i++) {
            for (int j = i + 1; j < numbers.length; j++) {
                if (numbers[i] == numbers[j]) {
                    throw new Exception("Duplicate number found: " + numbers[i]);
                }
            }
        }
    }

    void unreachableCatchBlock() throws Exception {
        try {
            throw new ArrayIndexOutOfBoundsException("Array index out of bounds.");
        } catch (ArrayIndexOutOfBoundsException e) {
            throw e;
        } catch (Exception e) {
            System.out.println("This catch block is unreachable.");
        }
    }

    void demonstrateThrowAndThrows() throws Exception {
        throw new ArithmeticException("Arithmetic Exception thrown.");
    }

    public static void main(String[] args) {
        Q2_S20230010193 obj = new Q2_S20230010193();
        Scanner sc = new Scanner(System.in);
        try {
            System.out.print("Enter a string: ");
            String input = sc.nextLine();
            obj.stringexception(input);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
        try {
            System.out.print("Enter number of elements in array: ");
            int n = sc.nextInt();
            int[] numbers = new int[n];
            System.out.println("Enter the elements: ");
            for (int i = 0; i < n; i++) {
                numbers[i] = sc.nextInt();
            }
            obj.checkDuplicates(numbers);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
        try {
            obj.unreachableCatchBlock();
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
        try {
            obj.demonstrateThrowAndThrows();
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }

        System.out.println("Exception Handling Completed");
    }
}
