package TD;

public class TD4 {

    public static void main(String[] args) {
        //1
        Point p = new Point(5, 6);
        
        //2
        p.Afficher();

        //3
        Cercle c = new Cercle(5, p);

        //4
        c.getPerimetre();

        //5
        c.Afficher();

        //6
        c.getCentre();

        //7
        Point hehe = new Point(9, 8);

        //8
        c.Appartient(hehe);

    }
}
