import java.util.*;;
public class circle {
    public static double circumference(int r){
        double result=2*3.14*r;
        return result;
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter the Radius: ");
        int r=sc.nextInt();
        double result = circumference(r);
        System.out.println("The Circumference of Circle with radius "+r+" is "+ result);
        sc.close();
    }
}
