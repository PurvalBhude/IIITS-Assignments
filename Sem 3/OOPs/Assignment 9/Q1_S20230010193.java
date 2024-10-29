public class Q1_S20230010193 {    
    public static void main(String[] args) {        
        try {            
            //write the code here!!!     
        } 
        catch (ArithmeticException e) {            
            System.out.println("Invalid division");
            System.out.println("Exception Handling Completed");         
        } 
        catch (NumberFormatException e) {            
            System.out.println("Format mismatch"); 
            System.out.println("Exception Handling Completed");        
        } 
        catch (StringIndexOutOfBoundsException e) {            
            System.out.println("Index is invalid"); 
            System.out.println("Exception Handling Completed");        
        } 
        catch (ArrayIndexOutOfBoundsException e) {            
            System.out.println("Array index is invalid");
            System.out.println("Exception Handling Completed");         
        } 
        catch (Exception e) {            
            System.out.println("An unexpected error occurred: " + e.getMessage()); 
            System.out.println("Exception Handling Completed");        
        }   
    }
}
