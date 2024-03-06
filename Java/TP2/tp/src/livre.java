import java.util.Scanner;

public class livre {
    //1
    private String titre,auteur;
    private int prix;

    //2
    public String getTitre(){
        return titre;
    }
    public void setTitre(String titre){
        this.titre=titre;
    }
    public String getAuteur(){
        return auteur;
    }
    public void setAuteur(String auteur){
        this.auteur=auteur;
    }
    public int getPrix(){
        return prix;
    }
    public void setPrix(int prix){
        this.prix=prix;
    }

    //3
    public livre(String titre,String auteur,int prix){
        this.titre=titre;
        this.auteur=auteur;
        this.prix=prix;
    }

    public livre() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Donner le titre");
        titre = sc.nextLine();
        System.out.println("Donner l'auteur");
        auteur = sc.nextLine();
        System.out.println("Donner le prix");
        prix = sc.nextInt();
    }

    public void afficher() {
        System.out.println("Livre: titre="+titre+", auteur="+auteur+", prix="+prix);
    }

    public void memeAuteur(livre a){
        if (auteur.equals(a.auteur)) {
            System.out.println("meme auteur");          
        }
        else {
            System.out.println("auteur different");
        }
    }

}
