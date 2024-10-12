interface Animal {
    void walk();
    void eat();
    }
    class Horse implements Animal {
    @Override
    public void walk() {
        System.out.println("walks on 4 legs");
    }
    
    @Override
    public void eat(){}
    }
    public class OOPS{
    public static void main (String args []) {
    Horse horse = new Horse();
    horse.walk();
    }
}