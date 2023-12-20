
import java.awt.*;

public class Ball {
    private Color c; // Color
    private int s; // Size
    private int x, y; // Position
    private int dx, dy; // Direction

    public Ball(Color col, int posx, int posy, int siz, int movx, int movy) {
        c = col;
        x = posx;
        y = posy;
        s = siz;
        dx = movx;
        dy = movy;
    }

    public void move() {
        x += dx; // Update x, y
        y += dy;
        if (x <= BallWorld.left) { // Hit the left boundary
            x = BallWorld.left;
            dx = -dx;
        }
        if (x >= BallWorld.right-s) {
            x = BallWorld.right-s;
            dx = -dx;  
        }
        if (y <= BallWorld.top) {
            y = BallWorld.top;
            dy = -dy;  
        }
        if (y >= BallWorld.bottom-s) {
            y = BallWorld.bottom-s;
            dy = -dy;  
        }

    }

    public void draw(Graphics g) {
        move();
        g.setColor(c);
        g.fillOval(x, y, s, s);
    }
}
