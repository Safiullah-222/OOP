#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>
#include <memory>

using namespace std;

class Garage {
    vector<Car*> cars;
public:
    void parkCar(Car* car) { cars.push_back(car); }
    void listCars() { cout << "Cars parked: " << cars.size() << endl; }
};

int main() {
    // Task 1: Car and Engine
    Car myCar;
    myCar.startCar();
    myCar.stopCar();
    
    // Task 2: Garage and Cars
    Car c1, c2;
    Garage garage;
    garage.parkCar(&c1);
    garage.parkCar(&c2);
    garage.listCars();

    return 0;
}