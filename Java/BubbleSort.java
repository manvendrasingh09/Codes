import java.util.Scanner;

public class BubbleSort {

    public static void bubble(int arr[], int size){
        for(int i=size-1; i>=1; i--){
            int temp;
            int didSwap=0;
            for(int j=0; j<=i-1; j++){
                if(arr[j]>arr[j+1]){
                    temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                    didSwap=1;
                }
            }
            if(didSwap==0){
                break;
            }
        }
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter the Size of the Array: ");
        int size=sc.nextInt();

        int arr[]=new int[size];
        System.out.print("Enter the Elements in the Array: ");
        for(int i=0; i<size; i++){
            arr[i]=sc.nextInt();
        }
        bubble(arr,size);
        System.out.println("Array after Sorting: ");
        for(int i=0; i<size; i++){
            System.out.print(+arr[i]+" ");
        }
    }
}