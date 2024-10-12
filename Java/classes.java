class Student{
    String name;
    int age;
    
    public void info(){
        System.out.println(this.name);
        System.out.println(this.age);
    }
    Student(){
        System.out.println("Constructor called");
    } 
}

public class classes{
    public static void main(String[] args) {
        Student s1 = new Student();
        s1.name = "John";
        s1.age = 20;
        s1.info();
    }
}