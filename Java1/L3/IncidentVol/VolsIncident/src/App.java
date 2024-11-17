
public class App {
    public static void main(String[] args) throws Exception {

        // A
        avion Av1 = new avion(25, "Dubai", "FSSF546");

        // B
        vol Vol1 = new vol("01-12-2005", "12:00", 6, "Djibouti", "Paris");
        vol Vol2 = new vol("01-10-2009", "09:00", 5, "Djibouti", "Addis-Abeba");

        // C
        Av1.ajouterVol(Vol1);
        Av1.ajouterVol(Vol2);

        // D
        System.out.println("Le numero d'avion du deuxieme vol est "+Vol2.getMonAvion().getNumero());

        // E
        incident Inc1 = new incident("humain", "faible", "Problemes technique");
        incident Inc2 = new incident("materiel", "moyen", "Materiaux en panne");
        Vol1.ajouterIncident(Inc1);
        Vol1.ajouterIncident(Inc2);

        // F
        System.out.println("\nDescriptions des incidents du premier vol:");
        for (incident inc: Vol1.getMesIncidents()) {
            System.out.println(inc.getDescription());
        }

        // G
        System.out.println("\nLa duree de chacun des vols de l'avion:");
        for (vol V : Av1.getMesVols()) {
            System.out.println(V.getDuree());
        }

        // H
        incident Inc3 = new incident("humain", "moyen", "Absence des personnels");
        Vol2.ajouterIncident(Inc3);

        // I
        System.out.println("\nDescriptions des incidents de l'avion:");
        for (vol v: Av1.getMesVols()) {
            for (incident i : v.getMesIncidents()) {
                System.out.println(i.getDescription());
            }
        }

        // J
        int n = 0;
        for (vol v: Av1.getMesVols()) {
            for (incident i : v.getMesIncidents()) {
                n++;
            }
        }
        System.out.println("\nNombre d'incident de l'avion:"+n);
    }
}
