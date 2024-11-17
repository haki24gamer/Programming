
import java.util.ArrayList;

class Plat {
    private String nom;
    private Float prix;
    private ArrayList<Commande> commandes;

    public Plat(String nom, Float prix) {
        this.nom = nom;
        this.prix = prix;
        commandes = new ArrayList<Commande>();
    }

    public void getDescription() {
        System.out.println("Plat [ nom: "+nom+", prix: "+prix+" ]"); 
    }

    public Float getPrix() {
        return prix;
    }

}
