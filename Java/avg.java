import java.util.*;
public class avg{
    public static float average(int a, int b, int c){
        int sum=a+b+c;
        int avg=sum/3;
        return avg;
    }
    public static void main(String[] args) {
        Scanner sc =new Scanner(System.in);
        System.out.print("Entyer the First Number: ");
        int a=sc.nextInt();
        System.out.print("Entyer the Second Number: ");
        int b=sc.nextInt();
        System.out.print("Entyer the Third Number: ");
        int c=sc.nextInt();
        float answer=average(a, b, c);
        System.out.print("Average of Three Numbers: ");
        System.out.println(answer);
        sc.close();
    }
}