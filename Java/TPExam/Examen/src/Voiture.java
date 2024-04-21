public class Voiture extends Vehicule{
    private String Marque;
    private String Module;

    public Voiture(int NbrRoues, String TypeDeMoteur, String Marque, String Module) {
        super(NbrRoues, TypeDeMoteur);
        this.Marque = Marque;
        this.Module = Module;
    }

    @Override
    public String toString() {
        return "Voiture [NumImmat=" + super.NumImmat + 
        ", NbrRoues=" + super.NbrRoues + ", TypeDeMoteur=" + 
        super.TypeDeMoteur + ", ListeDePieces=" + super.ListeDePieces + 
        ", Marque=" + Marque + 
        ", Module=" + Module + "]";
    }
    
    
}
