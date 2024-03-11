class Car {
    public string name = "I am a Car";
};
class Audi : Car {
    public new string name = "I am an Audi";
};

class Program {
    public static void GetArrayLength(Car[] cars) {
        Console.WriteLine($"\nArray processed. Length: {cars.Length}. \n object is of type: {cars.GetType()}");
    }
    public static void Main (string[] args) {

        // Method that can handle any object

        Action<Car[]> actCar = GetArrayLength;
        Action<Audi[]> actAudi = actCar;

        Audi[] audi = new Audi[4];
        Car[] car = new Car[7];

        actCar(car);
        actAudi(audi);

    }
}