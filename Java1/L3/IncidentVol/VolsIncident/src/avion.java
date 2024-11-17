import java.util.ArrayList;

public class avion {
    private int numero;
    private String fabricant;
    private String serie;
    private ArrayList<vol> MesVols;


    public avion(int numero, String fabricant, String serie) {
        this.numero = numero;
        this.fabricant = fabricant;
        this.serie = serie;
        MesVols = new ArrayList<vol>();
    }


    public int getNumero() {
        return numero;
    }


    public void setNumero(int numero) {
        this.numero = numero;
    }


    public String getFabricant() {
        return fabricant;
    }


    public void setFabricant(String fabricant) {
        this.fabricant = fabricant;
    }


    public String getSerie() {
        return serie;
    }


    public void setSerie(String serie) {
        this.serie = serie;
    }


    public ArrayList<vol> getMesVols() {
        return MesVols;
    }

    public void ajouterVol(vol V) {
        if (!MesVols.contains(V)) {
            if (V.getMonAvion()!=null) {
                V.getMonAvion().getMesVols().remove(V);
            }
            V.setMonAvion(this);
            MesVols.add(V);
        }
    }

}
