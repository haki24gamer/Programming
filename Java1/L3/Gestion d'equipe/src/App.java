public class App {
    public static void main(String[] args) throws Exception {
        Joueur j1 = new Joueur("Sami", "Francais", 4);
        j1.incrimente(6);
        Joueur j2 = new Joueur("Fami", "Marrocain", 5);
        j2.incrimente(6);
        Joueur j3 = new Joueur("Lami", "Ethiopien", 3);
        j3.incrimente(9);

        Equipe e1 = new Equipe("Equipe nationale");

        e1.AjouterJoueur(j1);
        e1.AjouterJoueur(j2);
        e1.AjouterJoueur(j3);

        e1.Nationalite();

        System.out.println(e1.Buts());
    }
}
