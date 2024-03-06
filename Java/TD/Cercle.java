package TD;

public class Cercle {
    private double rayon;
    private Point centre;

    public double getRayon(){
        return rayon;
    }
    public void setRayon(double rayon){
        this.rayon=rayon;
    }

    public Point getCentre(){
        return centre;
    }
    public void setCentre(Point centre){
        this.centre=centre;
    }

    public double getPerimetre(){
        return 2*3.14*rayon;
    }

    public Cercle(double rayon, Point centre){
        this.rayon=rayon;
        this.centre=centre;
    }

    public double getSurface(){
        return 3.14*(rayon*rayon);
    }

    public void Appartient(Point p){
        if (centre.equals(p)) {
            System.out.println("Appartient");
        } else {
            System.out.println("Pas appartient");
        }
    }

    public void Afficher(){
        System.out.println("Rayon= "+rayon+"Le x du centre est" +centre.getterX()+"Le y de centre est "+centre.getterY());
    }
}
