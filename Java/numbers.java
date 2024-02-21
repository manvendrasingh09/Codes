import java.util.*;
public class numbers {
    public static void main(String[] args) {
        int positive = 0, negative = 0, zeros = 0;
        Scanner sc=new Scanner(System.in);
        System.out.print("Press 1 to continue & 0 to stop: ");
        int input = sc.nextInt();
        while (input==1) {
            System.out.print("Enter the numbers: ");
            int n=sc.nextInt();
            if (n>0){
                positive++;
            }
            else if(n<0){
                negative++;
            }
            else{
                zeros++;
            }
            System.out.print("Press 1 to continue & 0 to stop: ");
            input = sc.nextInt();
        }
        System.out.println("Postive Numbers: "+positive);
        System.out.println("Negative Numbers: "+negative);
        System.out.println("Zeros: "+zeros);
        sc.close();
    }
}
