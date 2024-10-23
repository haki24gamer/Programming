import java.util.ArrayList;

public class classe {

    private String filiere;
    public int niveau;

    private ArrayList<etudiant> MesEtudiants;

    public classe(String filiere, int niveau) {
        this.filiere = filiere;
        this.niveau = niveau;

        MesEtudiants = new ArrayList<etudiant>();
    }


    // Getters
    public String getFiliere() {
        return filiere;
    }

    public ArrayList<etudiant> getMesEtudiants() {
        return MesEtudiants;
    }

    public void enlever(etudiant a) {
        MesEtudiants.remove(a);
    }

    public void inscrire(etudiant a) {
        if (!MesEtudiants.contains(a)) {
            if (a.getMaClasse()!=null) {
                a.getMaClasse().enlever(a);
            }
            a.setMaClasse(this);
            MesEtudiants.add(a);
        }
    }

}
