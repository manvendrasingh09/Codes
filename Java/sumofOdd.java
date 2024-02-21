import java.util.*;
public class sumofOdd {
    public static int oddsum(int n){
        int sum=0;
        for(int i=1;i<=n;i++){
            if (i%2!=0) {
                sum=sum+i;
            }
        }
        return sum;
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter the number: ");
        int n=sc.nextInt();
        int sum=oddsum(n);
        System.out.println(sum);
        sc.close();
    }
}
