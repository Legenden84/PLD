class Car {}
class Audi : Car {}

public class Task2a {
    public static void Main (string[] args) {
        Audi[] audi = new Audi[1];
        Car[] car = audi;
        car[0] = new Car();
    }
}