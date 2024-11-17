public class House {
    
    private int surface;
    private Porte p;

    public House(int surface, Porte p) {
        this.surface = surface;
        this.p = p;
    }

    public void Display(){
        System.out.println("Je suis une maison, ma surface est de "+surface+" m2");
    }

    public int getSurface() {
        return surface;
    }

    public void setSurface(int surface) {
        this.surface = surface;
    }

    public Porte getP() {
        return p;
    }

    public void setP(Porte p) {
        this.p = p;
    }

    

}
