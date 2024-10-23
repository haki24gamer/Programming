public class courrier {
    protected float poids;
    protected String adresse, nom;
    protected boolean express;
    protected static int nombre;

    public courrier(float poids, String adresse, String nom, boolean express) {
        this.poids = poids;
        this.adresse = adresse;
        this.nom = nom;
        this.express = express;
        if (express) nombre++;
    }

    public String getAdresse() {
        return adresse;
    }

    public static int getNombre() {
        return nombre;
    }

    public void setNom(String nom) {
        this.nom = nom;
    }

    public void augmentePoids(float poids) {
        this.poids = poids;
    }

    public void imprime() {
        System.out.println("Courrier [poids=" + poids + ", adresse=" + adresse + ", nom=" + nom + ", express=" + express + "]");
    }
    
}
