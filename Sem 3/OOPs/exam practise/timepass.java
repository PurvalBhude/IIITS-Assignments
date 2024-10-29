
// interface mark{
//     int marks;
//     void show();
// }

// class purval extends mark{

//     @Override
//     void show() {
//         System.out.println("marks");
//     }
    
// }
// public class timepass{
//     public static void main(String args[]){
        
// }

class A{
    private int b;
    String a = "purval";
    void seta(int b){
        this.b = b;
    } 
    void show(){
        System.out.println("in a ");
    }
    
}
class B extends A{
    String a = "bhude";  
    
    void show(){
        System.out.println("in b ");
    }
}

class timepass{
    public static void main(String[] args) {
        
        A time = new B();
        System.out.println(time.a);
        time.show();
    }
}


// class emp{
//     void show(Salary s){
//         System.out.println("emp exect");
//     }
// }

// abstract class employee{
//     int a = 10;
// }

// class empex extends employee{
//     super.a = 5;
// } 

// class Salary extends emp{
//     void show(emp e){
//         System.out.println("salary exact");
//     }
// }
// class timepass{
//     public static void main(String[] args) {
//         Salary s = new Salary();
//         s.show((Salary)s);
//     }
// }