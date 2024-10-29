class Employee {
    private String name;
    private String address;
    private double salary;
    private String jobTitle;

    public Employee(String name, String address, double salary, String jobTitle) {
        this.name = name;
        this.address = address;
        this.salary = salary;
        this.jobTitle = jobTitle;
    }

    public String getName() { return name; }
    public String getAddress() { return address; }
    public double getSalary() { return salary; }
    public String getJobTitle() { return jobTitle; }

    public double calculateBonus() {
        return 0.0;
    }

    public String generatePerformanceReport() {
        return "No performance report available.";
    }
}

class Manager extends Employee {
    public Manager(String name, String address, double salary, String jobTitle) {
        super(name, address, salary, jobTitle);
    }

    @Override
    public double calculateBonus() {
        return getSalary() * 0.15;
    }

    @Override
    public String generatePerformanceReport() {
        return "Excellent";
    }
}

class Developer extends Employee {
    public Developer(String name, String address, double salary, String jobTitle) {
        super(name, address, salary, jobTitle);
    }

    @Override
    public double calculateBonus() {
        return getSalary() * 0.15;
    }

    @Override
    public String generatePerformanceReport() {
        return "Average";
    }
}

class Programmer extends Employee {
    public Programmer(String name, String address, double salary, String jobTitle) {
        super(name, address, salary, jobTitle);
    }

    @Override
    public double calculateBonus() {
        return getSalary() * 0.15;
    }

    @Override
    public String generatePerformanceReport() {
        return "Poor";
    }
}

public class Q3_S20230010193 {
    public static void main(String[] args) {
        try {
            Manager manager = new Manager("Purval Bhude", "aurangabad", 100000, "CEO");
            Developer developer = new Developer("Advait kulkarni", "Akola", 90000, "CoO");
            Programmer programmer = new Programmer("Yash Malve", "chatt. sambhajinagar", 80000, "CXO");

            System.out.println("Manager Bonus: " + manager.calculateBonus());
            System.out.println("Developer Bonus: " + developer.calculateBonus());
            System.out.println("Programmer Bonus: " + programmer.calculateBonus());

            System.out.println("Manager Performance: " + manager.generatePerformanceReport());
            System.out.println("Developer Performance: " + developer.generatePerformanceReport());
            System.out.println("Programmer Performance: " + programmer.generatePerformanceReport());
        } catch (Exception e) {
            System.out.println("An error occurred: " + e.getMessage());
            System.out.println("Exception Handling Completed");
        }
    }
}
