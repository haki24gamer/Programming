
public class CompteBancaire {
    private String nom;
    private int Numc;
    private String type;
    private int solde;

    // constructeur
    public CompteBancaire(String nom, int Numc, String type, int solde) {
        this.nom = nom;
        this.Numc = Numc;
        this.type = type;
        this.solde = solde;
    }

    // methode setteur depot
    public int depot(int montant) {
        solde = montant + solde;
    }

    // methode setteur retrait
    public boolean retrait(int montant){
        if(mantant<=solde){
            solde=solde-mantant;
            return true;
        else return false;
    }
}

    // methode getteur
    public int getsolde() {
        return solde;
    }

    // methode de transfert
    public boolean transfert(CompteBancaire D, int mantant) {
        if (retrait(mantant) == true) {
            D.depot(mantant);
            return true;
        } else
            return false;
    }

    // methode de comparaison
    public void compare(CompteBancaire A) {
        if (solde == A.getsolde())
            System.out.println("meme solde");
        else
            System.out.println("solde differente");
    }

    // Methode affichage
    public void affichage() {
        System.out.println(nom);
        System.out.println(Numc);
        System.out.println(type);
        System.out.println(solde);
    }
}