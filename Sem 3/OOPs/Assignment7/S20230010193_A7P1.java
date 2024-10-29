import java.util.*;
import java.lang.*;

abstract class Vehicle {
    abstract String getDescriptor();
    abstract void displayType();
}

class Car extends Vehicle {
    String model;
    int noOfDoors;

    @Override
    String getDescriptor() {
        return model + " Car with " + noOfDoors + " doors";
    }

    @Override
    void displayType() {
        System.out.println("This is a car.");
    }
}

class Truck extends Vehicle {
    String model;
    float loadCapacity;

    @Override
    String getDescriptor() {
        return model + " Truck with load capacity of " + loadCapacity + " tons";
    }

    @Override
    void displayType() {
        System.out.println("This is a truck.");
    }
}

public class S20230010193_A7P1 {
    public static void main(String[] args) {
        Car car = new Car();
        car.model = "NANO";
        car.noOfDoors = 4;
        car.displayType();
        System.out.println(car.getDescriptor() + "\n");

        Truck truck = new Truck();
        truck.model = "TATA";
        truck.loadCapacity = 10.5f;
        truck.displayType();
        System.out.println(truck.getDescriptor() + "\n");

        car = null;
        truck = null;

        System.gc();
        System.out.println("Garbage collection suggested");
    }
}
