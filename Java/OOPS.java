class Student{
    String name;
    static String school;
    public static void changeSchool() {
        school = "newschool";
    }
}
public class OOPS {
    public static void main (String args []){
        Student.school = "ABC";
        Student student1 = new Student ();
        student1.name = "tony";
        Student student2 = new Student ();
        student2.name = "tony";
        System.out.println(student1.name);
        System.out.println(student2.name);
        System.out.println(Student.school);
        System.out.println (Student.school);
    }
}