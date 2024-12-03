import java.io.*;

class TEST {
    public static void main(String args[]) {
        try (
            FileInputStream input = new FileInputStream("input.txt");
            FileOutputStream output = new FileOutputStream("output.txt")) {

            

            int i;
            while ((i = input.read()) != -1) { // Read and write data
                output.write(i);
            }
            input.close();
            output.close();
        } catch (FileNotFoundException e) {
            System.out.println("File Not Found!!!!");
        } catch (IOException e) {
            System.out.println("An I/O error occurred: " + e.getMessage());
        }
    }
}
