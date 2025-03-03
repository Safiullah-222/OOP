#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>
#include <memory>

using namespace std;

class CoffeeShop {
    string name;
    vector<pair<string, double>> menu;
    vector<string> orders;
public:
    CoffeeShop(string n, vector<pair<string, double>> m) : name(n), menu(m) {}
    void addOrder(string item) {
        for (auto& m : menu) if (m.first == item) { orders.push_back(item); return; }
        cout << "This item is currently unavailable!" << endl;
    }
    void fulfillOrder() {
        if (!orders.empty()) { cout << "The " << orders[0] << " is ready!" << endl; orders.erase(orders.begin()); }
        else cout << "All orders have been fulfilled" << endl;
    }
};



int main() {

    CoffeeShop shop("Cafe", {{"Coffee", 2.5}, {"Tea", 1.5}});
    shop.addOrder("Coffee");
    shop.fulfillOrder();
    

    
    return 0;
}