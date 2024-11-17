import java.util.Date;
import java.util.ArrayList;

public class Commande {
    private int numero;
    private Date date;
    private Client client;
    private ArrayList<Plat> plats = new ArrayList<>();

    public Commande(int numero, java.util.Date date2, Client client) {
        this.numero = numero;
        this.date = date2;
        this.client = client;
        plats = new ArrayList<Plat>();
    }

    public void ajouterPlat(Plat plat) {
        plats.add(plat);
    }

    public Float CalculTotal() {
        Float prixTotal = 0f;
        for (Plat plat : plats) {
            prixTotal += plat.getPrix();
        }
        return prixTotal;
    }

    public ArrayList<Plat> getPlats() {
        return plats;
    }


}
