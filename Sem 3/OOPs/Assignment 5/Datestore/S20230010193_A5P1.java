/*
* Name : Purval Madhukar Bhude
* Roll No. S20230010193
*/

package Datestore;

import java.time.LocalDateTime;

public class Date {
    int Day;
    String Month;
    long Year;
    public Date() {
        LocalDateTime current = LocalDateTime.now();
        int M = current.getMonthValue();
        String[] months = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};
        this.Month = months[M - 1];
        this.Day = current.getDayOfMonth();
        this.Year = current.getYear();
    }

    public void printvalue() {
        System.out.printf("Day: " + this.Day + "\nMonth: " + this.Month + "\nYear: " + this.Year);
    }
}
