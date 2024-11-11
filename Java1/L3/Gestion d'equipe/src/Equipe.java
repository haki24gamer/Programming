import java.util.ArrayList;

public class Equipe {
    private String nom;
    private ArrayList<Joueur> MesJoueurs;

    public Equipe(String nom) {
        this.nom = nom;
        MesJoueurs = new ArrayList<Joueur>();
    }

    public boolean AjouterJoueur(Joueur j) {
        if (MesJoueurs.size()>=30) {
            return false;
        }
        else {
            j.setMonEquipe(this);
            MesJoueurs.add(j);
            return true;
        }
    }
    
    public void Nationalite() {
        for (int i = 0; i < MesJoueurs.size(); i++) {
                System.out.println(MesJoueurs.get(i).getNationalite());
        }
    }

    public int Buts() {
        int res = 0;
        for (int i = 0; i < MesJoueurs.size(); i++) {
            res += MesJoueurs.get(i).getNbrButs();
        }
        return res;
    }

    public String getNom() {
        return nom;
    }

}
