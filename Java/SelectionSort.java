
import java.util.Scanner;


public class SelectionSort {

    public static void selection(int arr[], int size){
        for(int i=0; i<=size-2; i++){
            int min=i;
            int temp;
            for(int j=i; j<=size-1; j++){
                if(arr[j]<arr[min]){
                    min=j;
                }
            }
            temp=arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
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
        selection(arr,size);
        System.out.println("Array after Sorting: ");
        for(int i=0; i<size; i++){
            System.out.print(+arr[i]+" ");
        }
    }
}