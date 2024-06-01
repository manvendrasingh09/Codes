
import java.util.Scanner;

public class CharcterHashing {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        String s=sc.nextLine();
        int hash[]=new int[26];

        for(int i=0; i<s.length(); i++){
            hash[s.charAt(i)-'a']++;
        }

        int q=sc.nextInt();
        sc.nextLine();
        for(int i=1; i<=q; i++){
            char c=sc.nextLine().charAt(0);
            System.out.println(hash[c-'a']);
        }
    }
}
