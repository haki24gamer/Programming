
import java.util.ArrayList;

class Plat {
    private String description;
    private Float prix;
    private ArrayList<Commande> commandes = new ArrayList<>();

    public Plat(String description, Float prix) {
        this.description = description;
        this.prix = prix;
        commandes = new ArrayList<Commande>();
    }

    public String getDescription() {
        return description;
    }

    public Float getPrix() {
        return prix;
    }

}
