public class etudiant {

    private String nom;
    private int age;
    private int numero;
    private static int n;

    private classe MaClasse;

    public etudiant(String nom, int age) {
        this.nom = nom;
        this.age = age;
        this.numero = n;
        n++;
    }


    // Getters
    public String getNom() {
        return nom;
    }

    public int getAge() {
        return age;
    }

    public int getNumero() {
        return numero;
    }

    public classe getMaClasse() {
        return MaClasse;
    }


    // Setters
    public void setNom(String nom) {
        this.nom = nom;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public void setNumero(int numero) {
        this.numero = numero;
    }

    public void setMaClasse(classe maClasse) {
        MaClasse = maClasse;
    }


    @Override
    public String toString() {
        return "etudiant [nom=" + nom + ", age=" + age + ", numero=" + numero + ", MaClasse=" + MaClasse + "]";
    }
    
}