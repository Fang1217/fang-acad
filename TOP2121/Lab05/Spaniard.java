import java.awt.*;

public class Spaniard extends Person {

    String name;

    Spaniard(String name) {
        super(name);
    }
    
    public String speak() {
        return "Hola!";
    }

    public Color dressColor() {
        return Color.orange;
    }
}