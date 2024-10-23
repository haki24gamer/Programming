import java.util.ArrayList;

public class Vehicule {
    protected int NumImmat;
    protected int NbrRoues;
    protected String TypeDeMoteur;
    protected ArrayList<String> ListeDePieces;
    protected static int nombre;

    public Vehicule(int NbrRoues, String TypeDeMoteur) {
        this.NbrRoues = NbrRoues;
        this.TypeDeMoteur = TypeDeMoteur;
        ListeDePieces = new ArrayList<String>();
        NumImmat=nombre;
        nombre++;
    }

    //Getter
    public ArrayList<String> getListeDePieces() {
        return ListeDePieces;
    }
    public int getNbrRoues() {
        return NbrRoues;
    }
    public int getNumImmat() {
        return NumImmat;
    }
    public String getTypeDeMoteur() {
        return TypeDeMoteur;
    }

    //Setter
    public void setListeDePieces(ArrayList<String> listeDePieces) {
        ListeDePieces = listeDePieces;
    }
    public void setNbrRoues(int nbrRoues) {
        NbrRoues = nbrRoues;
    }
    public void setNumImmat(int numImmat) {
        NumImmat = numImmat;
    }
    public void setTypeDeMoteur(String typeDeMoteur) {
        TypeDeMoteur = typeDeMoteur;
    }  

    public void ajouterunepiece(String p){
        ListeDePieces.add(p);
    }

    public void afficherpieces(){
        for (int i = 0; i < ListeDePieces.size(); i++) {
            System.out.println(ListeDePieces.get(i));
        }
    }

    @Override
    public String toString()
    {
        return "Vehicule [NumImmat=" + NumImmat + 
        ", NbrRoues=" + NbrRoues + ", TypeDeMoteur=" + 
        TypeDeMoteur + ", ListeDePieces=" + ListeDePieces + "]";
    }

}
