import java.awt.*;
import javax.swing.*;

public class Drawing extends JApplet {
    int choice;

    public void init() {
        String input;
        input = JOptionPane.showInputDialog(
                "Enter 1 to draw lines\n" +
                "Enter 2 to draw squares\n" +
                "Enter 3 to draw circles\n");
        choice = Integer.parseInt(input);
    }

    public void paint(Graphics g) {
        int[] x = { 300, 293, 276, 250, 217, 183, 151, 124, 107, 101, 107, 124, 150, 183, 217, 249, 276, 293 };
        int[] y = { 200, 234, 264, 286, 298, 298, 286, 264, 234, 200, 166, 136, 114, 102, 102, 114, 136, 166 };

        Color c[] = { Color.red, Color.yellow, Color.green,  Color.cyan, Color.magenta, Color.blue};


        if (choice > 3 || choice < 1) {
            JOptionPane.showMessageDialog(null, "Invalid input");
            return;
        }
        
        for (int i = 0; i < 18; i++) {
            g.setColor(c[i % 6]);
            switch (choice) {
                case 1:
                    g.drawLine(200, 200, x[i], y[i]);
                    break;
                case 2:
                    g.fillRect(x[i], y[i], 100, 100);
                    break;
                case 3:
                    g.fillOval(x[i], y[i], 100, 100);
                    break;
            }
        } // for
    }
}
