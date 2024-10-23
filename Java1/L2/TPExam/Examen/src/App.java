public class App {
    public static void main(String[] args) {

        //a
        Vehicule A = new Vehicule(4, "BB50");
        
        //b
        System.out.println(A.toString());
        
        //c
        Voiture B = new Voiture(4, "AC100", "Audi", "R6");

        //d
        System.out.println(B.NbrRoues);

        //e
        B.ajouterunepiece("Volant");

        //f
        B.afficherpieces();

        //g
        System.out.println(Vehicule.nombre);

    }
}
