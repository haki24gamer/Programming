public class test {
    public static void main(String[] args) {
        livre a = new livre("Blossom","sun tzu",20);
        a.setTitre("art de la guerre");
        System.out.println("auteur est "+a.getAuteur());
        a.afficher();
        livre b = new livre();
        b.afficher();

        livre c = new livre("the art of not giving a fuck", "Hello", 100000);
        c.memeAuteur(a);
    }
}
