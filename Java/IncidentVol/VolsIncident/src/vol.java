
import java.util.ArrayList;

public class vol {
    private String date;
    private String heure;
    private int duree; 
    private String aeroportDepart;
    private String aeroportArrivee;

    private ArrayList<incident> MesIncidents;
    private avion MonAvion;


    public vol(String date, String heure, int duree, String aeroportDepart, String aeroportArrivee) {
        this.date = date;
        this.heure = heure;
        this.duree = duree;
        this.aeroportDepart = aeroportDepart;
        this.aeroportArrivee = aeroportArrivee;
        MesIncidents = new ArrayList<incident>();
    }


    public String getDate() {
        return date;
    }

    public void setDate(String date) {
        this.date = date;
    }

    public String getHeure() {
        return heure;
    }

    public void setHeure(String heure) {
        this.heure = heure;
    }

    public int getDuree() {
        return duree;
    }

    public void setDuree(int duree) {
        this.duree = duree;
    }

    public String getAeroportDepart() {
        return aeroportDepart;
    }

    public void setAeroportDepart(String aeroportDepart) {
        this.aeroportDepart = aeroportDepart;
    }

    public String getAeroportArrivee() {
        return aeroportArrivee;
    }

    public void setAeroportArrivee(String aeroportArrivee) {
        this.aeroportArrivee = aeroportArrivee;
    }


    public avion getMonAvion() {
        return MonAvion;
    }

    public void setMonAvion(avion monAvion) {
        if (monAvion.getMesVols().contains(this)) {
            monAvion.getMesVols().remove(this);
        }
        this.MonAvion = monAvion;
    }
    
    
    public void ajouterIncident(incident i) {
        if (!MesIncidents.contains(i)) {
            if (i.getMonVol()!=null) {
                i.getMonVol().MesIncidents.remove(i);
                i.setMonVol(this);
            }
            MesIncidents.add(i);

        }
    }


    public ArrayList<incident> getMesIncidents() {
        return MesIncidents;
    }
    

}
