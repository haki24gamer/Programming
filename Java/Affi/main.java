public class Point {
    private double x;
    private double y;

    public void point(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public double getX() {
        return x;
    }

    public double getY() {
        return y;
    }

    public void setX(float a) {
        x = a;
    }

    public void setY(float b) {
        y = b;
    }

    public void afficher() {
        System.out.println(x);
        System.out.println(y);
    }

}

public class Cercle {
    private double rayon;
    private Point centre;

    public Cercle(double rayon, Point centre) {
        this.rayon = rayon;
        this.centre = centre;
    }

    public double getrayon() {
        return rayon;
    }

    public Point getcentre() {
        return centre;
    }

    public void setrayon(double a) {
        rayon = a;
    }

    public void setcentre(Point b) {
        centre = b;
    }

    public double getPerimetre() {
        return (2 * Math.PI * rayon);
    }

    public double getSurface() {
        return Math.PI * (rayon * rayon);
    }

    public void appartient(Point P) {
        if (this.centre.equals(P)) {
            System.out.println("appartient");
        } else {
            System.out.println("appartient pas");
        }
    }

    public void afficher() {
        System.out.println(getrayon());
        System.out.println(centre.getX());
        System.out.println(centre.getY());
    }
}

public static void main(String arg[]) {
    Point p1 = new Point(3.5, 4.2);
    p1.afficher();
    Cercle c1 = new Cercle(3.6, p1);
    system.out.println(c1.getPerimetre());
    c1.afficher();
    c1.getcentre();
    Point p2 = new Point(5.3, 2.8);
    appartient(p2);

}