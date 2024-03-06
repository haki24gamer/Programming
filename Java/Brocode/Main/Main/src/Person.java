public class Person {
    /**Attributs**/
    private String name = "name";
    private boolean exist = true;
    private int age;
    //private float length = 185f;
    private double length = 185;
    private char tag = 'A';

    static int population;

    /**Method**/
    public void Speak(){
        System.out.println("Wawa");
    }

    /**setter**/
    public void setAge(int age){
        this.age=age;
    }
    /**getter**/
    public int getAge(){
        return age;
    }

    //private et public
    

    /****/
    /**constructeur**/
    public Person(){
        population++;
    }
    public Person(String name, int age, double length, char tag){
        this.name=name;
        this.age=age;
        this.length=length;
        this.tag=tag;

        population++;
    }

    //static

    /**Afficher**/
    public void Introduce(){
        if (exist) {
            System.out.printf("Hi, I am %s, %d years old, %d cm and %c tagged \n", name, age, length, tag);
        } else {
            System.out.println("Sorry g. I ain't alive");
        }
    }

}
