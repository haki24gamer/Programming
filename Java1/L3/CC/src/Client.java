import java.util.ArrayList;
import java.util.List;

// Classe Client
class Client {
    private String nom;
    private int phone;
    private List<Commande> commandes = new ArrayList<>();

    public Client(String nom, int phone) {
        this.nom = nom;
        this.phone = phone;
    }

    public void passerCommande(Commande commande) {
        commandes.add(commande);
        
    }



}

