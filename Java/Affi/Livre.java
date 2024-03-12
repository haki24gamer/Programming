import java.util.Scanner;

public class Livre {
    private String Titre;
    private String Auteur;
    private int Prix;

    // Contructeur
    public Livre(String Titre, String Auteur, int Prix) {
        this.Titre = Titre;
        this.Auteur = Auteur;
        this.Prix = Prix;
    }

    // mehtode d'acces
    public String getTitre() {
        return Titre;
    }

    public String getAuteur() {
        return Auteur;
    }

    public String getPrix() {
        return Prix;
    }

    // Methode de modification
    public void setTitre(String x) {
        Titre = x;
    }

    public void setAuteur(String y) {
        Auteur = y;
    }

    public void setPrix(/int z) {
        Prix = z;
    }

    // constructeur avec saisi
    public Livre() {
        Scanner sc = new Scanner(system.in);
        System.out.println("Donner le titre");
        Titre = sc.nextLine();
        System.out.println("Donner l'auteur");
        Auteur = sc.nextLine();
        System.out.println("Donner le prix");
        Prix = sc.nextInt();
    }

    // Methode Afficher
    public void Afficher() {
        system.out.println(Titre);
        system.out.println(Auteur);
        system.out.println(Prix);
    }

    // Methode MemeAuteur
    public String MemeAuteur(Livre L2) {
        if (this.Auteur.equal(L2.getAuteur()))
            return ("Meme auteur");
        else
            return ("Auteur different");
    }

}

public static void main(String arg[]){
    //Creation d'un objet
    Livre L2=new Livre(comment devenir riche, Affi, 20000);
    //Modification Du titre
    L2.setTitre(comment devenir pauvre)
    //Afficher le nom de l'auteur
    L2.getAuteur();
    //Afficher tous les attribut
    L2.Afficher();
    //creation d'un autre objet
    Livre L3=new Livre(L'amour, Souhaib, 10000);
    //comparer deux auteur
    L2.MemeAuteur(L3); 
}
