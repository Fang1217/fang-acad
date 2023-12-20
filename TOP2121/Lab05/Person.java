// Source code is decompiled from a .class file using FernFlower decompiler.
import java.awt.Color;
import java.awt.Graphics;

public class Person {
   private int xp = 0;
   private static int count = 0;
   private String name;

   Person(String var1) {
      this.xp = count++ * 120;
      this.name = var1;
   }

   final void draw(Graphics var1) {
      int[] var2 = new int[]{0, 30, 30, 70, 70, 100, 100, 0};
      int[] var3 = new int[]{130, 120, 135, 135, 120, 130, 160, 160};
      var1.setColor(Color.black);
      var1.drawRect(this.xp, 10, 100, 150);
      var1.drawOval(this.xp + 5, 15, 90, 110);
      var1.drawOval(this.xp + 25, 40, 15, 15);
      var1.drawOval(this.xp + 60, 40, 15, 15);
      var1.drawLine(this.xp + 50, 55, this.xp + 50, 75);
      var1.drawArc(this.xp + 20, 50, 60, 40, 210, 120);
      var1.drawArc(this.xp + 25, 45, 50, 55, 200, 140);

      for(int var4 = 0; var4 < 8; ++var4) {
         var2[var4] += this.xp;
      }

      var1.setColor(this.dressColor());
      var1.fillPolygon(var2, var3, 8);
      var1.setColor(Color.black);
      var1.drawString(this.speak(), this.xp, 200);
      var1.drawString("My name is " + this.name, this.xp, 220);
      var1.drawString("I am a " + this.getClassName(), this.xp, 240);
   }

   Color dressColor() {
      return Color.green;
   }

   String getClassName() {
      String var1 = this.toString();
      int var2 = var1.indexOf(64);
      return var1.substring(0, var2);
   }

   String speak() {
      return "Hello";
   }
}
