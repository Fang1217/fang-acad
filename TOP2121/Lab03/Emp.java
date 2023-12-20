import java.util.*;

class Emp {
    String fname, lname;
    int sal;
    Date date;

    Emp() {
        fname = "Unknown";
        lname = "Unknown";
        sal = 0;
    }

    Emp(String firstName, String lastName, int salary) {
        fname = firstName;
        lname = lastName;
        sal = salary;   
    }

    void setFirstName(String input) {
        fname = input;
    } 

    String getFirstName() {
        return fname;
    }

    void setLastName(String input) {
        lname = input;
    }
    
    String getLastName() {
        return lname;
    }
    
    void setSalary(int input) {
        sal = input;
    } 

    public static void main (String[] args) {}
}