import java.awt.*;

public class Malaysian extends Person {
    
    String name;

    Malaysian(String name) {
        super(name);
    }
    
    public String speak() {
        return "Apa khabar?";
    }

    public Color dressColor() {
        return Color.red;
    }
}
