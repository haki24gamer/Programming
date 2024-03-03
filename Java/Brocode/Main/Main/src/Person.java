public class Person {
    //Attributs
    String name = "name";
    boolean exist = true;
    private int age;
    //float length = 185f;
    double length = 185;
    char tag = 'A';

    //Method
    void Speak(){
        System.out.println("Wawa");
    }

    //setter
    void setAge(int age){
        this.age=age;
    }

    //getter
    int getAge(){
        return age;
    }

    //private et public
    

    //constructeur
    public Person(){

    }
    public Person(String name, int age, double length, char tag){
        this.name=name;
        this.age=age;
        this.length=length;
        this.tag=tag;
    }

    //static
    
}
