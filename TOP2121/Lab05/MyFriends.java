import java.applet.*; 
import java.awt.*;

public class MyFriends extends Applet {
    Person p1 = new Malaysian("Ali");
    Person p2 = new American("Bob");
    Person p3 = new Spaniard("Charlie");
    Person p4 = new Person("Mary");

    public void paint(Graphics g) {
        p1.draw(g);
        p2.draw(g);
        p3.draw(g);
        p4.draw(g);
    }
}