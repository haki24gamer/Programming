public class Joueur {
    private String nom;
    private String nationalite;
    private int nbrButs;
    private Equipe MonEquipe;

    public Joueur(String nom, String nationalite, int nbrButs) {
        this.nom = nom;
        this.nationalite = nationalite;
        this.nbrButs = nbrButs;
    }

    public void incrimente(int i) {
        this.nbrButs += i;
    }

    @Override
    public String toString() {
        return "Joueur [nom=" + nom + ", nationalite=" + nationalite + ", nbrButs=" + nbrButs + ", MonEquipe="
                + MonEquipe + "]";
    }

    public String getNationalite() {
        return nationalite;
    }

    public int getNbrButs() {
        return nbrButs;
    }

    public void setMonEquipe (Equipe e) {
        this.MonEquipe = e;
    }
}
