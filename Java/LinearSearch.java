import java.util.*;
public class LinearSearch {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            System.out.print("Enter the Size of the Array: ");
            int size = sc.nextInt();
            int num[] = new int[size];
            System.out.println("Enter the Value in the Array");
            for (int i = 0; i < size; i++) {
                num[i] = sc.nextInt();
            }
            System.out.print("Enter the Number to be found in the array: ");
            int x = sc.nextInt();
            boolean found = false;
            for (int i = 0; i < size; i++) {
                if (num[i] == x) {
                    System.out.println("Number found at index:" + i);
                    found = true;
                }
            }
            if (found == false) {
                System.out.println("Number not present in array");
            }
        }
    }
}
