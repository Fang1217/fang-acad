import java.util.*;
import javax.swing.*;

class HashExample {
    public static void main(String args[]) {
        String skey;
        String[] keys = { "1991234", "100", "200", "300"
                // ..., ---include a few student ID numbers---
                // ...
        };
        String[] names = { "Martin", "Ali", "Mary", "Bala"
                // ..., --- include student names ---
                // ...
        };

        Hashtable<Object, Object> ht = new Hashtable<Object, Object>();
        for (int i = 0; i < keys.length; i++) // Stores data in hash table
            ht.put(keys[i], names[i]);
        skey = JOptionPane.showInputDialog("Enter Search Key");
        JOptionPane.showMessageDialog(null, 
                ht.get(skey) == null ? "There is no student with this ID" : ("The student's name is " + ht.get(skey)));
        System.exit(0);
    }
}
