#include <iostream>
#include <string>
using namespace std;


class Vehicle {
protected:
    double price;
public:
    Vehicle(double p) : price(p) {}
    virtual void displayDetails() {
        cout << "Price: $" << price << endl;
    }
};


class Car : public Vehicle {
protected:
    int seatingCapacity, numDoors;
    string fuelType;
public:
    Car(double p, int seats, int doors, string fuel) 
        : Vehicle(p), seatingCapacity(seats), numDoors(doors), fuelType(fuel) {}
    void displayDetails() override {
        cout << "Car - Price: $" << price << ", Seats: " << seatingCapacity 
             << ", Doors: " << numDoors << ", Fuel: " << fuelType << endl;
    }
};


class Motorcycle : public Vehicle {
protected:
    int cylinders, gears, wheels;
public:
    Motorcycle(double p, int cyl, int gear, int wheel) 
        : Vehicle(p), cylinders(cyl), gears(gear), wheels(wheel) {}
    void displayDetails() override {
        cout << "Motorcycle - Price: $" << price << ", Cylinders: " << cylinders 
             << ", Gears: " << gears << ", Wheels: " << wheels << endl;
    }
};


class Audi : public Car {
private:
    string modelType;
public:
    Audi(double p, int seats, int doors, string fuel, string model) 
        : Car(p, seats, doors, fuel), modelType(model) {}
    void displayDetails() override {
        cout << "Audi - Price: $" << price << ", Seats: " << seatingCapacity 
             << ", Doors: " << numDoors << ", Fuel: " << fuelType 
             << ", Model: " << modelType << endl;
    }
};


class Yamaha : public Motorcycle {
private:
    string makeType;
public:
    Yamaha(double p, int cyl, int gear, int wheel, string make) 
        : Motorcycle(p, cyl, gear, wheel), makeType(make) {}
    void displayDetails() override {
        cout << "Yamaha - Price: $" << price << ", Cylinders: " << cylinders 
             << ", Gears: " << gears << ", Wheels: " << wheels 
             << ", Make: " << makeType << endl;
    }
};

int main() {
    Audi audiCar(40000, 5, 4, "Petrol", "A6");
    Yamaha yamahaBike(15000, 2, 6, 2, "R1");

    
    audiCar.displayDetails();
    yamahaBike.displayDetails();

    return 0;
}
