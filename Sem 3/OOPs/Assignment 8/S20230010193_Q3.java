/**
 * Name: Purval Madhukar Bhude
 * Roll No. S20230010193
 * Assignment 8 Exercise 3
 */

abstract class student {
    String name;
    String studentID;

    student(String name, String studentID) {
        this.name = name;
        this.studentID = studentID;
    }

    abstract int calculateGrade();
    abstract void getDetails();
}

interface ScholarshipEligible {
    boolean isEligibleForScholarship(double GPA);
}

class UndergraduateStudent extends student implements ScholarshipEligible {
    double[] marks;

    UndergraduateStudent(String name, String studentID, double[] marks) {
        super(name, studentID);
        this.marks = marks;
    }

    @Override
    int calculateGrade() {
        double total = 0;
        for (double mark : marks) {
            total += mark;
        }
        double average = total / marks.length;
        return (int) average;
    }

    @Override
    void getDetails() {
        System.out.println("Undergraduate Student Name: " + name);
        System.out.println("Student ID: " + studentID);
        System.out.println("Average Grade: " + calculateGrade());
    }

    @Override
    public boolean isEligibleForScholarship(double GPA) {
        return GPA >= 3.5;
    }
}

class GraduateStudent extends UndergraduateStudent {
    String thesisTopic;

    GraduateStudent(String name, String studentID, double[] marks, String thesisTopic) {
        super(name, studentID, marks);
        this.thesisTopic = thesisTopic;
    }

    @Override
    void getDetails() {
        System.out.println("Graduate Student Name: " + name);
        System.out.println("Student ID: " + studentID);
        System.out.println("Thesis Topic: " + thesisTopic);
        System.out.println("Average Grade: " + calculateGrade());
    }

    @Override
    public boolean isEligibleForScholarship(double GPA) {
        return GPA >= 3.5;
    }

    class Transcript {
        String courseName;
        int credits;
        String grade;

        Transcript(String courseName, int credits, String grade) {
            this.courseName = courseName;
            this.credits = credits;
            this.grade = grade;
        }

        void getTranscriptDetails() {
            System.out.println("Course Name: " + courseName);
            System.out.println("Credits: " + credits);
            System.out.println("Grade: " + grade);
        }
    }
}

class S20230010193_Q3 {
    public static void main(String[] args) {
        double[] marksUG = {85.0, 90.0, 78.0, 88.0};
        UndergraduateStudent undergrad = new UndergraduateStudent("Purval", "193", marksUG);
        undergrad.getDetails();
        System.out.println("Scholarship Eligibility: " + undergrad.isEligibleForScholarship(3.8));

        double[] marksGrad = {92.0, 85.0, 87.0, 90.0};
        GraduateStudent grad = new GraduateStudent("advait", "365-", marksGrad, "AI in Healthcare");
        grad.getDetails();
        System.out.println("Scholarship Eligibility: " + grad.isEligibleForScholarship(3.7));

        GraduateStudent.Transcript transcript = grad.new Transcript("Machine Learning", 3, "A");
        transcript.getTranscriptDetails();
    }
}
