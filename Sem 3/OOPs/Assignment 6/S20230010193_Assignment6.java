/*
* Name : Purval Madhukar Bhude
* Roll No. : S20230010193
* Subject : OOPS
* Assignment 6
 */

import java.time.LocalDate;
import java.time.Period;
import java.util.Date;
import java.util.Scanner;

class Person {

    private String Name;
    private String AADHAR_No;
    private char Gender;
    private Date Date_of_Birth;

    Person(String name, String ANo, char G, Date DOB) {
        this.Name = name;
        this.AADHAR_No = ANo;
        this.Gender = G;
        this.Date_of_Birth = DOB;
    }

    // Setter method

    void set_name(String name) {
        this.Name = name;
    }

    void set_AADHAR(String AADHAR_No) {
        this.AADHAR_No = AADHAR_No;
    }

    void set_Gender(char Gender) {
        this.Gender = Gender;
    }

    void set_Date_of_Birth(Date DOB) {
        this.Date_of_Birth = DOB;
    }

    //Getter Method 

    String get_name() {
        return this.Name;
    }

    String get_AADHAR() {
        return this.AADHAR_No;
    }

    char get_Gender() {
        return this.Gender;
    }

    Date get_Date_of_Birth() {
        return this.Date_of_Birth;
    }

    // calculating age using currentdata-DOB
    int CalculateAge() {
        LocalDate birthDate = new java.sql.Date(this.Date_of_Birth.getTime()).toLocalDate();
        return Period.between(birthDate, LocalDate.now()).getYears();
    }
}

class Student extends Person {

    private int Roll_No;
    private String Institute_Name;
    private String Dept;
    private String Specialization;
    private String Subjects[];
    char Grades;

    Student(String name, String ANo, char G, Date DOB) {
        super(name, ANo, G, DOB);
        System.out.println("Student object created for: " + name);
    }

    // Admiting student method
    void Admit_student(String Name, String Aadhar_no, char Gender, Date DOB, String Institute_Name) {
        set_name(Name);
        set_AADHAR(Aadhar_no);
        set_Gender(Gender);
        set_Date_of_Birth(DOB);
        this.Institute_Name = Institute_Name;
    }

    // Enroll student method
    void enroll_student(String Dept, String Specialization, String[] Subjects, int Roll_No) {
        this.Dept = Dept;
        this.Specialization = Specialization;
        this.Subjects = Subjects;
        this.Roll_No = Roll_No;
    }

    // printing student info
    void print_student_info() {
        System.out.println("Student: " + get_name() + "\nRoll No: " + this.Roll_No + "\nDept: " + this.Dept + "\nSpecialization: " + this.Specialization);
    }
}

class Faculty extends Person {
    private int Emp_id;
    private String Dept;
    private String Institute_Name;
    private String Specialization;
    private String Subject;
    private int Salary;

    Faculty(String name, String ANo, char G, Date DOB) {
        super(name, ANo, G, DOB);
    }

    // join faculty method
    void Join_Faculty(String Name, String AADHAR_No, char Gender, Date Date_of_Birth, int Emp_id, String Institute_Name) {
        set_name(Name);
        set_AADHAR(AADHAR_No);
        set_Gender(Gender);
        set_Date_of_Birth(Date_of_Birth);
        this.Emp_id = Emp_id;
        this.Institute_Name = Institute_Name;
    }

    // Assign faculty method
    void Assign_Faculty(String Dept, String Specialization, String Subject, int Salary) {
        this.Dept = Dept;
        this.Specialization = Specialization;
        this.Subject = Subject;
        this.Salary = Salary;
    }

    void Assign_Grades(Student student, char Grade) {
        student.Grades = Grade;
    }
}

public class S20230010193_Assignment6 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of students to admit: ");
        int studentCount = sc.nextInt();
        sc.nextLine();

        Student[] students = new Student[studentCount];
        for (int i = 0; i < studentCount; i++) {
            System.out.println("Enter details for Student " + (i + 1));

            System.out.print("Name: ");
            String name = sc.nextLine();

            System.out.print("AADHAR Number: ");
            String AADHAR_No = sc.nextLine();

            System.out.print("Gender (M/F): ");
            char gender = sc.next().charAt(0);

            System.out.print("Roll No: ");
            int rollNo = sc.nextInt();
            sc.nextLine();

            System.out.print("Date of Birth (yyyy-MM-dd): ");
            String dob = sc.nextLine();
            Date dateOfBirth = java.sql.Date.valueOf(dob);

            System.out.print("Institute Name: ");
            String instituteName = sc.nextLine();

            System.out.print("Department: ");
            String dept = sc.nextLine();

            System.out.print("Specialization: ");
            String specialization = sc.nextLine();

            System.out.print("Subjects (comma-separated): ");
            String subjectsStr = sc.nextLine();
            String[] subjects = subjectsStr.split(",");

            students[i] = new Student(name, AADHAR_No, gender, dateOfBirth);
            students[i].Admit_student(name, AADHAR_No, gender, dateOfBirth, instituteName);
            students[i].enroll_student(dept, specialization, subjects, rollNo);
        }

        System.out.print("Enter the number of faculty members to join: ");
        int facultyCount = sc.nextInt();
        sc.nextLine();

        Faculty[] faculties = new Faculty[facultyCount];
        for (int i = 0; i < facultyCount; i++) {
            System.out.println("Enter details for Faculty " + (i + 1));

            System.out.print("Name: ");
            String name = sc.nextLine();

            System.out.print("AADHAR Number: ");
            String AADHAR_No = sc.nextLine();

            System.out.print("Gender (M/F): ");
            char gender = sc.next().charAt(0);

            System.out.print("Emp ID: ");
            int empId = sc.nextInt();
            sc.nextLine(); // consume newline

            System.out.print("Date of Birth (yyyy-MM-dd): ");
            String dob = sc.nextLine();
            Date dateOfBirth = java.sql.Date.valueOf(dob);

            System.out.print("Institute Name: ");
            String instituteName = sc.nextLine();

            System.out.print("Department: ");
            String dept = sc.nextLine();

            System.out.print("Specialization: ");
            String specialization = sc.nextLine();

            System.out.print("Subject: ");
            String subject = sc.nextLine();

            System.out.print("Salary: ");
            int salary = sc.nextInt();
            sc.nextLine();

            faculties[i] = new Faculty(name, AADHAR_No, gender, dateOfBirth);
            faculties[i].Join_Faculty(name, AADHAR_No, gender, dateOfBirth, empId, instituteName);
            faculties[i].Assign_Faculty(dept, specialization, subject, salary);
        }

        for (int i = 0; i < facultyCount; i++) {
            System.out.println("Faculty " + faculties[i].get_name() + " is assigning grades.");
            for (int j = 0; j < studentCount; j++) {
                System.out.print("Enter grade for Student " + students[j].get_name() + ": ");
                char grade = sc.next().charAt(0);
                faculties[i].Assign_Grades(students[j], grade);
            }
        }

        for (int i = 0; i < studentCount; i++) {
            students[i].print_student_info();
        }

        sc.close();
    }
}
