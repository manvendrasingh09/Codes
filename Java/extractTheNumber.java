import java.util.*;
class extractTheNumber 
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter the Numbers: ");
        int n=sc.nextInt();
        while(n!=0){
            int lastDigit=n%10;
            n=n/10;
            System.out.println(lastDigit);
        }
        sc.close();
    }
}