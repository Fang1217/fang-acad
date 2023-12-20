
import java.awt.*;
import java.applet.*;

public class BallWorld extends Applet {
    public static int left = 50, right = 350, top = 50, bottom = 350;
    Ball b = new Ball(Color.red, 100, 100, 30,20, 10);
    Ball b2 = new Ball(Color.orange, 10, 10, 30, 20, 10);

    Ball Balls[];
    Balls = new Ball[20];

    public void paint(Graphics g) {
        for (int i = 0; i < 20; i++) {
            Balls[i] = new Ball(Color.green, i*5, i*10, 30, i*10, i*15);
        }
        g.setColor(Color.blue);
        g.drawRect(left, top, right - left, bottom - top);

        b.draw(g); // draw ball
        b2.draw(g);

        slow(1); // slow the display
        repaint();
    }

    public void slow(int t) {
        try {
            Thread.sleep(t);
        } catch (Exception e) {
        }
    }
}
