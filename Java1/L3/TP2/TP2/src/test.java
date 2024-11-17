public class test {
    public static void main(String[] args) throws Exception {

        // Classe porte
        Porte porte = new Porte();
        porte.setColor("rouge");
        // System.out.println(porte.getColor());
        porte.setColor("bleu");
        porte.Display();

        // Classe House
        House house = new House(10, porte);

        /* Partie inutile */
        // System.out.println(house.getSurface());
        // System.out.println(house.getP().getColor());
        // house.getP().Display();
        house.Display();

        /* Partie inutile */
        // Porte porte2 = new Porte();
        // porte2.setColor("violet");
        // house.setP(porte2);
        // house.setSurface(20);
        // house.Display();

        // Classse Person
        Person person = new Person("Sami", house);
        person.Display();

    }
}


