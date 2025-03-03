#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>
#include <memory>

using namespace std;

class Engine {
    bool isRunning;
public:
    Engine() : isRunning(false) {}
    void start() { isRunning = true; cout << "Engine started" << endl; }
    void stop() { isRunning = false; cout << "Engine stopped" << endl; }
};

class Car {
    Engine engine;
public:
    void startCar() { engine.start(); }
    void stopCar() { engine.stop(); }
};

int main() {
    // Task 1: Car and Engine
    Car myCar;
    myCar.startCar();
    myCar.stopCar();
}