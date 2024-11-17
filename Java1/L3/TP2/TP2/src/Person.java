public class Person {

    private String nom;
    private House maison;

    public Person(String nom, House maison) {
        this.nom = nom;
        this.maison = maison;
    }

    public void Display(){
        System.out.println("Nom: "+nom+"\nSurface de la maison: "+maison.getSurface()+" m2\nCouleur de la porte: "+maison.getP().getColor());
    }

}
