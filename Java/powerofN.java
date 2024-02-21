import java.util.*;
public class powerofN {
    public static void main(String[] args) {
        Scanner sc =new Scanner(System.in);
        System.out.print("Enter the value of X: ");
        int x=sc.nextInt();
        System.out.print("Enter the value of N: ");
        int n=sc.nextInt();
        double product=Math.pow(x, n);
        System.out.println("Result is: "+product);
        sc.close();
    }
}
