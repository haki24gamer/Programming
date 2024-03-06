package TD;

public class Point {
    private double x,y;

    public double getterX(){
        return x;
    }
    public void setterX(double x){
        this.x=x;
    }

    public double getterY(){
        return y;
    }
    public void setterY(double y){
        this.y=y;
    }

    public Point (double x,double y){
        this.x=x;
        this.y=y;
    }

    public void Afficher() {
        System.out.println("x="+x+" y="+y);
    }
}