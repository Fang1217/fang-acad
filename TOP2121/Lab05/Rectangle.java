public class Rectangle {
    double width, height;

    Rectangle(double w, double h) {
        width = w;
        height = h;
    }

    double getArea() {
        return height * width;
    }

    double getPerimeter() {
        return 2*(width + height);
    }

    void print() {
        System.out.println("Area: " + getArea());
        System.out.println("Perimeter: " + getPerimeter());
    }
}
