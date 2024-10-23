import java.util.ArrayList;

public class GestionEcole {
    public static void main(String[] args) throws Exception {
        etudiant et1 = new etudiant("Houmed", 20);
        etudiant et2 = new etudiant("Amir", 21);

        classe c1 = new classe("Informatique", 3);

        c1.inscrire(et1);
        c1.inscrire(et2);

        System.out.println("Amir a "+et2.getAge()+" ans.");
        System.out.println("Amir est dans la filiere " + et2.getMaClasse().getFiliere());

        ArrayList<etudiant> ListeEtu = et2.getMaClasse().getMesEtudiants();

        for (etudiant etudiant : ListeEtu) {
            System.out.println(etudiant.getNom());
        }

    }
}
