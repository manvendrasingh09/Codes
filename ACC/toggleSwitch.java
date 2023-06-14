package ACC;
import java.util.*;
public class toggleSwitch {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Boolean[] b = new Boolean[n + 1];
        Arrays.fill(b, Boolean.FALSE);
        int i, j, c=0;
        for(i=2;i<=n;i++) {
            for(j=i;j<=n;j+=i) {
                if(b[j] == false)
                    b[j] = true;
                else
                    b[j] = false;
            }
        }
        for(i=1;i<=n;i++) {
            if(b[i] == false)
                c++;
        }
        System.out.println(c);
        sc.close();
    }
}