import java.util.*;
public class gcd {
    public static void main(String[] args) {
        Scanner sc =new Scanner(System.in);
        System.out.print("Enter the First Number: ");
        int a=sc.nextInt();
        System.out.print("Enter the Second Number: ");
        int b=sc.nextInt();
        int count=1;
        int result=0;
        while (count<=a&&count<=b) {
            if (a%count==0&&b%count==0) {
                result=count;
            }
            count++;
        }
        System.out.println("GCD: "+result);
    }
}
