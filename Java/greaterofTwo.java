import java.util.*;
public class greaterofTwo {
    public static int greater(int a,int b){
        if (a>b) {
            return a;
        }
        else if(a<b){
            return b;
        }
        else{
            return a;
        }
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter the First Number: ");
        int a=sc.nextInt();
        System.out.print("Enter the Second Number: ");
        int b=sc.nextInt();
        int greater=greater(a, b);
        System.out.println(greater);
        sc.close();
    }
}
