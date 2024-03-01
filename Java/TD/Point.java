package TD;

public class Point {
    private double x,y;

    public double getterX(){
        return this.x;
    }
    public void setterX(double ValX){
        this.x=ValX;
    }

    public double getterY(){
        return this.y;
    }
    public void setterY(double ValY){
        this.y=ValY;
    }
    public Point (double X,double Y){
        this.x=X;
        this.y=Y;
    }

    public void Afficher() {
        System.out.println("x="+x+"\ny="+y);
    }
}