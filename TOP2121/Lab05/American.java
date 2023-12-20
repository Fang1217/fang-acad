import java.awt.*;

public class American extends Person {
    
    String name;

    American(String name) {
        super(name);
    }
    
    public String speak() {
        return "What's up?";
    }

    public Color dressColor() {
        return Color.blue;
    }
}
