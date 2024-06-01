import java.util.*;
public class printNames {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter the Size of Array: ");
        int size=sc.nextInt();
        String names[]=new String[size]; 
        System.out.print("Enter the Names: ");
        for(int i=0;i<size;i++){
            names[i]=sc.next();
        }
        for(int i=0;i<size;i++){
            System.out.println("Name "+(i+1)+ " is "+ names[i]);
        }
    }
}