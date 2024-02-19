import java.util.*;
public class greetings {
    public static void main(String[] args) {
        Scanner sc =new Scanner (System.in);
        System.out.print("Enter the Number:");
        int n=sc.nextInt();
        switch (n) {
            case 1:
                System.out.println("Hello");
                break;
            case 2:
                System.out.println("Namaste");
                break;
            case 3:
                System.out.println("Hola");
                break;
            default:
                System.out.println("Invaild Entry");
                break;
        }
        sc.close();
    }
}
