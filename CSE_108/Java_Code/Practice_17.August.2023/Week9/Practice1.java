abstract class Figure {
    double d1, d2;

    Figure (double a, double b) {
        this.d1 = a;
        this.d2 = b;
    }

    public abstract double area();
}

// your code

public class Practice1 {
    public static void main(String[] args) {
        Rectangle r = new Rectangle(9, 5);
        Triangle t = new Triangle(10, 8);

        Figure ref;

        ref = r;
        System.out.println("Area: " + ref.area());

        ref = t;
        System.out.println("Area: " + ref.area());
    }
}

/* Write the necessary classes to achieve the following output of the main method.

Area: 45.0
Area: 40.0

*/