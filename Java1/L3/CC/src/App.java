
public class App {
    public static void main(String[] args) {
        // a. Créer un client
        Client client = new Client("Alice", 123456789);

        // b. Créer une commande
        Commande commande = new Commande();

        // c. Ajouter la commande aux commandes du client
        client.passerCommande(commande);

        // d. Créer deux plats
        Plat plat1 = new Plat("Pizza Margherita", 12.50f);
        Plat plat2 = new Plat("Salade César", 8.90f);

        // e. Ajouter les plats à la commande
        commande.ajouterPlat(plat1);
        commande.ajouterPlat(plat2);

        // f. Calculer le prix de la commande
        double prixTotal = commande.CalculTotal();
        System.out.println("Prix total de la commande : " + prixTotal);

        // g. Afficher les descriptions des plats de la commande
        System.out.println("Plats commandés :");
        for (Plat plat : commande.getPlats()) {
            plat.getDescription();
        }
    }
}
