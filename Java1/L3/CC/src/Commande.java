import java.util.Date;
import java.util.ArrayList;

public class Commande {
    private int numero;
    private Date date;
    private Client client;
    private ArrayList<Plat> plats;
    public static int count = 0;

    public Commande() {
        this.numero = count;
        count++;
        this.date = new Date();
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

    public void setClient(Client client) {
        this.client = client;
    }

}
