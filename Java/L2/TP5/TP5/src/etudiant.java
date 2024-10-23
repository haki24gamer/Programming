import java.util.ArrayList;

public class etudiant {
    private String nom, filiere;
    private int numero, annee;
    static private int nombre;
    private ArrayList<Float> notes;

    public etudiant(String nom, String filiere, int annee){
        this.nom = nom;
        this.filiere = filiere;
        this.annee = annee;
        nombre = nombre+1;
        numero = nombre;
        notes = new ArrayList<Float>();
    }

    public int getNumero(){
        return numero;
    }

    public ArrayList<Float> getNotes(){
        return notes;
    }

    public void ajouterNote(Float a){
        notes.add(a);
    }

    float calculer_moy(){
        float somme=0;
        for (int i = 0; i < notes.size(); i++) {
            somme+=notes.get(i);
        }
        return somme/notes.size();
    }

    public void affiche(){
        System.out.println("Etudiant nom="+nom+", filiere= "+filiere+", numero="+numero+", annee="+annee+", notes="+notes+", nombres d etudiant="+nombre);
    }

    public static int getNombre(){
        return nombre;
    }

    public static void main(String[] args) {
        etudiant e = new etudiant("ali", "Math", 2000);
        System.out.println("numero de l etudiant "+e.getNumero());
        System.out.println("nombre de l etudiant est "+etudiant.getNombre());
        e.ajouterNote((float) 15);
        e.ajouterNote((float) 13);
        System.out.println("note de l etudiant "+e.getNumero());
        System.out.println("moyenne de l etudiant "+e.calculer_moy());
        etudiant a = new etudiant("ali", "Math", 2000);
        System.out.println("numero de l etudiant "+a.getNumero());
        System.out.println("nombre d etudiant "+etudiant.getNombre());
        System.out.println("nombre d etudiant "+e.getNombre());
        System.out.println("nombre d etudiant "+a.getNombre());
        
    }

}
