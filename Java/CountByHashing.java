import java.util.*;
public class CountByHashing{
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter the Size of Array: ");
        int size=sc.nextInt();

        System.out.print("Enter the Elements in the Array: ");
        int arr[]=new int[size];
        for(int i=0; i<size; i++){
            arr[i]=sc.nextInt();
        }

        int hash[]=new int[13];
        for(int i=0; i<size; i++){
            hash[arr[i]]+=1;
        }

        System.out.print("Enter the Number of Queries: ");
        int q=sc.nextInt();
        for(int i=1; i<=q; i++){
            System.out.print("Enter the Number: ");
            int num=sc.nextInt();
            System.out.println(num+" came "+hash[num]+" times");
        }
    }
}