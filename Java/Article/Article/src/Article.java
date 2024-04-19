public class Article {
    
    protected static int numero;
    protected int code;
    protected String Designation;
    protected Float Prix;
    protected String Categorie;

    public Article(int code,String Des,float prix,String cat){
        this.code=code;
        this.Designation=Des;
        this.Prix=prix;
        numero++;
    }
    public String getCategorie() {
        return Categorie;
    }
    public Article(){
        numero++;
    }
    public Float getPrix() {
        return Prix;
    }
    public void setPrix(Float Prix) {
        this.Prix = Prix;
    }
    public void tostring(){
        System.out.println(code+";"+Designation+";"+Prix+";"+Categorie);
    }

    public boolean Equals(Article a){
        if (a.code==this.code && a.Designation==this.Designation && a.Prix == this.Prix && a.Categorie==this.Categorie) {
            return true;
        }
        else return false;
    }


}
