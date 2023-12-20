   import java.awt.*;
   import java.applet.*;
   import java.util.*;
   public class Welcome extends Applet{
      public void paint(Graphics g){
        Font f=new Font("Times Roman",Font.BOLD,20);
        g.setColor(Color.cyan);
        g.fillRect(0,0,800,600);
        g.setFont(f);
        g.setColor(Color.yellow);
        g.fillRect(10,10,400,60);
        g.setColor(Color.pink);
        g.fillRect(10,90,400,60);
        g.setColor(Color.blue);
        g.drawString("Welcome to the world of Java Applets",20,40);
        g.drawString("Today is "+ new Date(),20,120);
      }
   }
