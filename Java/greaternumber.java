import java.util.*;
public class greaternumber {
    public static void main(String[] args) {
        Scanner sc =new Scanner (System.in);
        System.out.print("Enter the First Number: ");
        int a=sc.nextInt();
        System.out.print("Enter the Second Number: ");
        int b=sc.nextInt();

        if (a==b) 
        {
            System.out.println("A and B are Equal");
        }
        else if(a>b)
        {
            System.out.println("A is greater than B");
        }
        else
        {
            System.out.println("B is greater than A");
        }
        sc.close();
    }
}
