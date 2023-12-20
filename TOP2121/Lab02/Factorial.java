import javax.swing.*;

public class Factorial {
    // Demo on recursive functions.
    public static void main(String a[]) {
        String s = "";
        int k;
        JTextArea out = new JTextArea(7, 10);
        for (int i = 0; i < 10; i++) {
            k = fact(i);
            s = s + i + "\t" + k + "\n";
        }
        out.setText(s);
        JOptionPane.showMessageDialog(null, out,
            "My Output", JOptionPane.INFORMATION_MESSAGE);
        System.exit(0);
    }

    static int fact(int i){
        if (i < 0) return 0; // Negative factorials are not defined.
        return (i == 0 ? 1 : i*fact(i-1));
    }

}
