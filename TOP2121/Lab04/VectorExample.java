import java.util.*;

class VectorExample {
    public static void main(String args[]) {
        int n;
        Vector<String> v = new Vector<String>();
        v.addElement("aristotle");
        v.addElement("descartes");
        v.addElement("euclid");
        v.addElement("newton");
        v.addElement("einstein");
        // add a few more names!

        // Output number of elements
        n = v.size();
        System.out.println("Vector size: " + n);
    
        // Output elements in vector
        for (int i = 0; i < v.size(); i++) {
            System.out.println("Element at " + i + ": " + v.elementAt(i));
        }

        System.err.println("First element: " + v.firstElement());
        System.err.println("Last element: " + v.lastElement());
        v.removeElementAt(2);
        v.isEmpty();
    }
}
