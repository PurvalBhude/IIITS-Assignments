/**
 * Name: Purval Madhukar Bhude
 * Roll No. S20230010193
 * Assignment 11 Question 1
 */

import java.util.*;

// Base Vehicle class
abstract class Vehicle {
    private String registrationNumber;
    private String brand;
    private double rentalPricePerDay;
    
    public Vehicle(String registrationNumber, String brand, double rentalPricePerDay) {
        this.registrationNumber = registrationNumber;
        this.brand = brand;
        this.rentalPricePerDay = rentalPricePerDay;
    }
    
    public String getRegistrationNumber() {
        return registrationNumber;
    }
    
    public String getBrand() {
        return brand;
    }
    
    public double getRentalPricePerDay() {
        return rentalPricePerDay;
    }
    
    public void setRentalPricePerDay(double newPrice) {
        this.rentalPricePerDay = newPrice;
    }
    
    @Override
    public String toString() {
        return String.format("Brand: %s, Registration: %s, Price per day: %.2f", 
            brand, registrationNumber, rentalPricePerDay);
    }
    
    // Abstract method to get vehicle specific details
    public abstract String getSpecificDetails();
}

// Car class
class Car extends Vehicle {
    private int seatingCapacity;
    
    public Car(String registrationNumber, String brand, double rentalPricePerDay, int seatingCapacity) {
        super(registrationNumber, brand, rentalPricePerDay);
        this.seatingCapacity = seatingCapacity;
    }
    
    public int getSeatingCapacity() {
        return seatingCapacity;
    }
    
    @Override
    public String getSpecificDetails() {
        return String.format("Car with %d seats", seatingCapacity);
    }
}

// Bike class
class Bike extends Vehicle {
    private boolean hasCarrier;
    
    public Bike(String registrationNumber, String brand, double rentalPricePerDay, boolean hasCarrier) {
        super(registrationNumber, brand, rentalPricePerDay);
        this.hasCarrier = hasCarrier;
    }
    
    public boolean hasCarrier() {
        return hasCarrier;
    }
    
    @Override
    public String getSpecificDetails() {
        return String.format("Bike with%s carrier", hasCarrier ? "" : "out");
    }
}

// Truck class
class Truck extends Vehicle {
    private double loadCapacity;
    
    public Truck(String registrationNumber, String brand, double rentalPricePerDay, double loadCapacity) {
        super(registrationNumber, brand, rentalPricePerDay);
        this.loadCapacity = loadCapacity;
    }
    
    public double getLoadCapacity() {
        return loadCapacity;
    }
    
    @Override
    public String getSpecificDetails() {
        return String.format("Truck with %.1f tons capacity", loadCapacity);
    }
}

// Generic RentalBox class
class RentalBox<T extends Vehicle> {
    private T vehicle;
    private boolean isRented;
    private String currentRenter;
    private int rentalDuration;
    
    public RentalBox(T vehicle) {
        this.vehicle = vehicle;
        this.isRented = false;
        this.currentRenter = null;
        this.rentalDuration = 0;
    }
    
    public T getVehicle() {
        return vehicle;
    }
    
    public boolean isRented() {
        return isRented;
    }
    
    public boolean rentVehicle(String renterName, int days) {
        if (!isRented) {
            isRented = true;
            currentRenter = renterName;
            rentalDuration = days;
            return true;
        }
        return false;
    }
    
    public void returnVehicle() {
        isRented = false;
        currentRenter = null;
        rentalDuration = 0;
    }
    
    public double getRentalPrice(int days) {
        return vehicle.getRentalPricePerDay() * days;
    }
    
    public String getRentalStatus() {
        if (isRented) {
            return String.format("Rented to %s for %d days", currentRenter, rentalDuration);
        }
        return "Available for rent";
    }
}

// Utility class
class RentalUtils {
    public static void printAvailableVehicles(List<? extends Vehicle> vehicles) {
        System.out.println("\n=== Available Vehicles ===");
        int availableCount = 0;
        
        for (Vehicle vehicle : vehicles) {
            if (vehicle != null) {
                System.out.printf("%s - %s%n", vehicle.toString(), vehicle.getSpecificDetails());
                availableCount++;
            }
        }
        
        System.out.printf("Total available vehicles: %d%n", availableCount);
    }
    
    public static void applyDiscountToTrucks(List<? super Truck> vehicles, double discountPercentage) {
        System.out.println("\n=== Applying Discount to Trucks ===");
        
        for (Object vehicleObj : vehicles) {
            if (vehicleObj instanceof Truck) {
                Truck truck = (Truck) vehicleObj;
                double originalPrice = truck.getRentalPricePerDay();
                double discountedPrice = originalPrice * (1 - discountPercentage / 100);
                truck.setRentalPricePerDay(discountedPrice);
                
                System.out.printf("Truck %s: Original price: %.2f, New price after %.1f%% discount: %.2f%n",
                    truck.getRegistrationNumber(), originalPrice, discountPercentage, discountedPrice);
            }
        }
    }
}

// Main class for testing
class Q3_S20230010193 {
    public static void main(String[] args) {
        // Create vehicle instances
        Car luxuryCar = new Car("CAR001", "Mercedes", 150.0, 5);
        Car familyCar = new Car("CAR002", "Toyota", 80.0, 7);
        Bike mountainBike = new Bike("BIKE001", "spilender", 25.0, true);
        Bike cityBike = new Bike("BIKE002", "activa", 20.0, false);
        Truck deliveryTruck = new Truck("TRUCK001", "tata", 200.0, 5.0);
        Truck heavyTruck = new Truck("TRUCK002", "mahindra", 300.0, 10.0);

        // Create RentalBox instances
        List<RentalBox<?>> rentalFleet = new ArrayList<>();
        rentalFleet.add(new RentalBox<>(luxuryCar));
        rentalFleet.add(new RentalBox<>(familyCar));
        rentalFleet.add(new RentalBox<>(mountainBike));
        rentalFleet.add(new RentalBox<>(cityBike));
        rentalFleet.add(new RentalBox<>(deliveryTruck));
        rentalFleet.add(new RentalBox<>(heavyTruck));

        // Simulate rental operations
        System.out.println("=== Testing Rental Operations ===");
        int rentalAttempts = 0;
        while (rentalAttempts < 3) {
            for (RentalBox<?> rentalBox : rentalFleet) {
                if (Math.random() < 0.5) {  // 50% chance of rental attempt
                    String randomRenter = "Customer" + (int)(Math.random() * 100);
                    int randomDays = (int)(Math.random() * 7) + 1;
                    
                    if (rentalBox.rentVehicle(randomRenter, randomDays)) {
                        System.out.printf("%s successfully rented to %s for %d days. Total cost: %.2f%n",
                            rentalBox.getVehicle().getRegistrationNumber(),
                            randomRenter,
                            randomDays,
                            rentalBox.getRentalPrice(randomDays));
                    }
                }
            }
            rentalAttempts++;
        }

        // Print rental status
        System.out.println("\n=== Current Rental Status ===");
        for (RentalBox<?> rentalBox : rentalFleet) {
            System.out.printf("%s: %s%n",
                rentalBox.getVehicle().getRegistrationNumber(),
                rentalBox.getRentalStatus());
        }

        // Create lists for utility methods
        List<Vehicle> allVehicles = new ArrayList<>();
        List<Vehicle> truckList = new ArrayList<>();
        
        for (RentalBox<?> rentalBox : rentalFleet) {
            allVehicles.add(rentalBox.getVehicle());
            if (rentalBox.getVehicle() instanceof Truck) {
                truckList.add(rentalBox.getVehicle());
            }
        }

        // Test utility methods
        RentalUtils.printAvailableVehicles(allVehicles);
        RentalUtils.applyDiscountToTrucks(truckList, 15.0);
    }
}


class BasicCalculator {
    public double add(double number1, double number2) {
        return number1 + number2;
    }
    public double subtract(double number1, double number2) {
        return number1 - number2;
    }
    public double multiply(double number1, double number2) {
        return number1 * number2;
    }
    public double divide(double number1, double number2) {
        if (number2 == 0) {
            System.out.println("Error: Division by zero is undefined.");
            return 0;
        }
        return number1 / number2;
    }
}