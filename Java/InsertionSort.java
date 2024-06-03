import java.util.Scanner;

public class InsertionSort {

    public static void insertion(int arr[], int size){
        for(int i=0; i<size; i++){
            int j=i;
            int temp;
            while(j>0 && arr[j-1]>arr[j]){
                temp=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
                j--;
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
        insertion(arr, size);
        System.out.println("Array after Sorting: ");
        for(int i=0; i<size; i++){
            System.out.print(+arr[i]+" ");
        }
    }
}