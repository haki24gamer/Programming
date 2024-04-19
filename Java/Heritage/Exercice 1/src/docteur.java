public class docteur {
    private String nom, hopital;

    public docteur (String n, String m){
        nom = n;
        hopital = m;
    }

    public void affiche(){
        System.out.println("Nom: "+nom+" a l hopital "+hopital);
    }
}
