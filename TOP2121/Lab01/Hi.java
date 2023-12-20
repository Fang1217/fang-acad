class Hi{
    public static void main(String[] a){
        if(a.length == 0)
            System.out.println("Welcome to Java");
        else
            System.out.print("This is the first Java program of ");
            for (int i = 0; i < a.length; i++)
                System.out.print(a[i] + " ");
    }
}

