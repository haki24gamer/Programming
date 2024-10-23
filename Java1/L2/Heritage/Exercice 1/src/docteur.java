public class docteur {
    protected String nom = "defaut";
    protected String hopital = "defaut";

    docteur (String nom, String hopital){
        this.nom = nom;
        this.hopital = hopital;
    }



    public void affiche(){
        System.out.println("Nom: "+nom+" a l hopital "+hopital);
    }

}
