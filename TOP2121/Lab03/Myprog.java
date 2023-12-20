class Myprog {
    public static void main(String[] args) {
        Account a1 = new Account( 20.50, 12345678, "Bob");
        Account a2 = new Account(200.00, 23456789, "Emily");
        Account a3 = new Account(100000, 34567890, "Jake");
        a1.credit(200);
        a1.withdraw(50);
        a2.credit(50);
        a3.credit(300);
        
        a1.printBalance();
        a2.printBalance();
        a3.printBalance();

        a3 = a1;
	    a3.balance=10000;  //***
	    a1.printBalance();  //print balance of a1

        System.out.print("Number of accounts = " + Account.k);

    }

}