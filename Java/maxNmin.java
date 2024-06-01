import java.util.*;
public class maxNmin {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter the Size of Array: ");
        int size=sc.nextInt();
        int num[]=new int[size];
        System.out.print("Enter the Elements in Array: ");
        for(int i=0;i<size;i++){
            num[i]=sc.nextInt();
        }

        int max=num[0];
        int min=num[0];

        for(int i=1;i<size;i++){
            if(num[i]>max){
                max=num[i];
            }
            if(min>num[i]){
                min=num[i];
            }
        }
        System.out.println("Maximum Element is: "+max);
        System.out.println("Minimum Element is: "+min);
    }
}
