package ACC;
import java.util.*;
public class Palindrome {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the String:");
        int n = sc.nextInt();
        String str=Integer.toBinaryString(n);
        StringBuffer strrev = new StringBuffer(str);
        strrev.reverse();
        String str1 = strrev.toString();
        if (str.equals(str1)) {
            System.out.println("is Palindrome");
        } else
            System.out.println("Not Palindrome");
        sc.close();
    }
}