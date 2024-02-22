public class test {
    public static void main(String[] args) {
        livre a = new livre("art de la guerre","sun tzu",20);
        a.setTitre("art de la guerre");
        System.out.println("auteur est "+a.getAuteur());
        a.afficher();
        livre b = new livre();
        b.afficher();
        a.memeAuteur(b);
    }
}
