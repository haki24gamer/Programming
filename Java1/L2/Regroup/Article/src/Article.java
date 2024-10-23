package Regroup.Article.src;

public class Article {
    private int PrixHT;
    private String Designation;
    private String Reference;
    private static int TauxTVA=10;


    public int getPrixHt(){
        return PrixHT;
    }
    public void setPrixHT(int PrixHT){
        this.PrixHT=PrixHT;
    }

    public String getDesignation(){
        return Designation;
    }
    public void setDesignation(String Designation){
        this.Designation=Designation;
    }
    public String getReference(){
        return Reference;
    }
    public void setReference(String Reference){
        this.Reference=Reference;
    }

    public Article(){

    }
    public Article(int PrixHT, String Designation, String Reference){
        this.PrixHT=PrixHT;
        this.Designation=Designation;
        this.Reference=Reference;
    }
    public Article(String Designation, String Reference){
        this.Designation=Designation;
        this.Reference=Reference;
    }

    public int setTTC(){
        return PrixHT+(PrixHT*TauxTVA/100);
    }

    public void afficher(){
        System.out.println("reference="+Reference+"\ndesignation="+Designation+"\nprix="+PrixHT+"\nprixTTC"+setTTC());
    
    }
}
