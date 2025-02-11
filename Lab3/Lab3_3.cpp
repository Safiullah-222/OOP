#include <iostream>
using namespace std;

class Glass {
public:
    int LiquidLevel;

    Glass() { 
        LiquidLevel = 200;
    }

    void Drink(int milliliters) {
        if (milliliters > LiquidLevel) {
            cout << "Not enough left!" << endl;
        } else {
            LiquidLevel -= milliliters;
            cout << "You drank " << milliliters << " ml." << endl;
        }

        if (LiquidLevel < 100) { 
            cout << "Refilling glass..." << endl;
            Refill();
        }
    }

    void Refill() {
        LiquidLevel = 200;
        cout << "Glass refilled." << endl;
    }
};

int main() {
    Glass glass;
    int amount;

    cout << "Glass is full (200 ml). Enter how much you drink (-1 to stop)." << endl;

    while (true) {
        cout << "Drink amount (-1 to stop): ";
        cin >> amount;

        if (amount == -1) {
            cout << "Goodbye!" << endl;
            break;
        }

        if (amount < 0) {
            cout << "Enter a positive number!" << endl;
            continue;
        }

        glass.Drink(amount);
        cout << "Left: " << glass.LiquidLevel << " ml" << endl;
    }

    return 0;
}



