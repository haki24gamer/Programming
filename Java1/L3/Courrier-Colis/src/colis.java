public class colis extends courrier {
    private float volume;

    public void imrpime() {
        super.imprime();
        System.out.println("colis [volume =]" + volume + "]");
    }

    public colis(float poids, String adresse, String nom, boolean express, float volume) {
        super(poids, adresse, nom, express);
        this.volume = volume;
    }

    public colis() {
        super(0, "inconnu", "", false);
    }
}
