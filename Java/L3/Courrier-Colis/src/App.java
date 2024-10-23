public class App {
    public static void main(String[] args) throws Exception {
        float poids = 200;
        String adresse = "rue tokyo 22";
        String nom= "Ali";
        boolean express = true;

        courrier a = new courrier(poids, adresse, nom, express);

        a.setNom("aicha");

        System.out.println(a.getAdresse());

        colis b = new colis(340, "heron", "ifrah", false, 66);

        b.imprime();

        System.out.println("nombre de courrier express est "+courrier.getNombre());
    }
}
