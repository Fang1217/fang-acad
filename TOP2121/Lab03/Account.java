public class Account {
    double balance;
    int number;
    String name;

    static int k = 0; //Number of accounts

    Account (double balance, int number, String name) {
        this.balance = balance;
        this.number = number;
        this.name = name;
        k++;               
    }
    
    public void credit(double amount) {
        balance += amount;
    }

    public void withdraw(double amount) {
        balance -= amount;
    }

    public void printBalance() {
        System.out.println("Account number " + number + " of " + name + " balance: RM " + balance);
    }

    public static void main(String[] args) {};

}