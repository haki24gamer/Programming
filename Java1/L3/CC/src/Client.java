import java.util.ArrayList;
import java.util.List;

class Client {
    private String nom;
    private int phone;
    private List<Commande> commandes;

    public Client(String nom, int phone) {
        this.nom = nom;
        this.phone = phone;
        commandes = new ArrayList<Commande>();
    }

    public void passerCommande(Commande commande) {
        commandes.add(commande);
        commande.setClient(this);
    }



}

