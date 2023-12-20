public class Square extends Rectangle {
    Square(double w, double h) {
        super(w,h);
    }

    void printError() {
        System.out.println("not a square");
    }

    double getArea() {
        return width * height;
    }    
    
    double getPerimeter() {
        return 2*(width+height);
    }
}
