public class incident {
    private String type;
    private String gravite;
    private String description;

    private vol MonVol;

    public incident(String type, String gravite, String description) {
        this.type = type;
        this.gravite = gravite;
        this.description = description;
    }

    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }

    public String getGravite() {
        return gravite;
    }

    public void setGravite(String gravite) {
        this.gravite = gravite;
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public vol getMonVol() {
        return MonVol;
    }

    public void setMonVol(vol monVol) {
        MonVol = monVol;
    }


}
