import java.util.*;
public class ascendingOrNot {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            System.out.print("Enter The Size of the Array: ");
            int size = sc.nextInt();
            int arr[] = new int[size];
            System.out.print("Enter The Elements of the Array: ");
            for (int i = 0; i < size; i++) {
                arr[i] = sc.nextInt();
            }
            boolean isAscending = true;

            for (int i = 0; i < size - 1; i++) {
                if (arr[i] > arr[i + 1]) {
                    isAscending = false;
                    break;
                }

            }
            if (isAscending == true) {
                System.out.println("Array is in Ascending Order");
            } else {
                System.out.println("Array is not in Ascending Order");
            }
        }
    }
}
