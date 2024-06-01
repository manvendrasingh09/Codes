import java.util.*;

public class CharHash {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter the String: ");
        String s=sc.nextLine();

        int hash[]=new int[26];
        for(int i=0; i<s.length(); i++){
            hash[s.charAt(i)-'a']++;
        }

        System.out.print("Enter the Number of Queries: ");
        int q=sc.nextInt();
        sc.nextLine();
        for(int i=1; i<=q; i++){
            char c=sc.nextLine().charAt(0);
            System.out.println(hash[c-'a']);
        }
    }
}