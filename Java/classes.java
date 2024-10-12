class Shape{
    public void area(){
        System.out.println("Display area");
    }
}

class  Triangle extends Shape{
    public void area(int b, int h){
        System.out.println("Area of triangle: "+0.5*b*h);
    }
}

public class classes{
    public static void main(String[] args) {
        Triangle t = new Triangle();
        t.area(10, 20);
    }
}