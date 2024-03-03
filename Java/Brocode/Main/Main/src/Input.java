import java.util.Scanner;

public class Input {
    public static void main(String[] args) throws Exception {
        
        Scanner scanner = new Scanner(System.in);
        
        String name = scanner.nextLine();
        System.out.println("Your name is "+name);

        int age = scanner.nextInt();
        System.out.println("Your age is "+age);
    }
}
