#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>
#include <memory>

using namespace std;

class Vehicle {
public:
    int horsepower, seating_capacity, no_of_speakers;
    void setValues(int hp, int seat, int speakers) const {
        ((Vehicle*)this)->horsepower = hp;
        ((Vehicle*)this)->seating_capacity = seat;
        ((Vehicle*)this)->no_of_speakers = speakers;
    }
};



int main() {

    Vehicle car;
    car.setValues(150, 5, 4);
    

    
    return 0;
}