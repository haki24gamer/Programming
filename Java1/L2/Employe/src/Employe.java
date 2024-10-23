public class Employe {
    private int Matricule;
    private String Nom;
    private String Prenom;
    private int DateAA;
    private int DateNaissance;
    private int DateEmbauche;
    private int Salaire;

    public static int NbrDeEmploye;

    public int getMatricule() {
        return Matricule;
    }
    public String getNom() {
        return Nom;
    }
    public String getPrenom() {
        return Prenom;
    }
    public int getDateAA() {
        return DateAA;
    }
    public int getDateNaissance() {
        return DateNaissance;
    }
    public int getDateEmbauche() {
        return DateEmbauche;
    }
    public int getSalaire() {
        return Salaire;
    }

    public Employe(int matricule, String nom, String prenom, int dateAA, int dateNaissance, int dateEmbauche, int salaire) {
        Matricule = matricule;
        Nom = nom;
        Prenom = prenom;
        DateAA = dateAA;
        DateNaissance = dateNaissance;
        DateEmbauche = dateEmbauche;
        Salaire = salaire;

        NbrDeEmploye++;
    }


    public int Age(){
        return DateAA-DateNaissance;
    }

    public int Anciennette(){
        return DateAA-DateEmbauche;
    }

    public void AugmentationDuSalaire(){
        if (Anciennette()<5){
            Salaire += Salaire*0.02;
        }
        else if (Anciennette()<5) {
            Salaire += Salaire*0.5;
        }
        else{
            Salaire += Salaire*0.1;
        }
    }


    // public void AfficherEmp() {
    //     System.out.println("Matricule=" + Matricule + ", Nom=" + Nom + ", Prenom=" + Prenom + ", DateAA=" + DateAA
    //     + ", DateNaissance=" + DateNaissance + ", DateEmbauche=" + DateEmbauche + ", Salaire=" + Salaire + "]");
    // }
    
    @Override
    public String toString() {
        String MyString = "Matricule=" + Matricule + ", Nom=" + Nom + ", Prenom=" + Prenom + ", DateAA=" + DateAA
         + ", DateNaissance=" + DateNaissance + ", DateEmbauche=" + DateEmbauche + ", Salaire=" + Salaire + "]";
        return MyString;
    }
    
}
