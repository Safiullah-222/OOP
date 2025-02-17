#include <iostream>
#include <vector>
using namespace std;

class MenuItem {
public:
    string name, type;
    double price;

    MenuItem(string n, string t, double p) : name(n), type(t), price(p) {}
};

class CoffeeShop {
private:
    string name;
    vector<MenuItem> menu;
    vector<string> orders;

public:
    CoffeeShop(string n) : name(n) {}

    void addMenuItem(string n, string t, double p) {
        menu.push_back(MenuItem(n, t, p));
    }

    string addOrder(string item) {
        for (auto& menuItem : menu) {
            if (menuItem.name == item) {
                orders.push_back(item);
                return "Order added!";
            }
        }
        return "This item is currently unavailable";
    }

    string fulfillOrder() {
        if (!orders.empty()) {
            string order = orders[0];
            orders.erase(orders.begin());
            return "The " + order + " is ready";
        }
        return "All orders have been fulfilled";
    }

    vector<string> listOrders() { return orders; }

    double dueAmount() {
        double total = 0;
        for (auto& order : orders) {
            for (auto& menuItem : menu) {
                if (menuItem.name == order) {
                    total += menuItem.price;
                }
            }
        }
        return total;
    }

    string cheapestItem() {
        if (menu.empty()) return "Menu is empty";
        MenuItem* cheapest = &menu[0];
        for (auto& menuItem : menu) {
            if (menuItem.price < cheapest->price) {
                cheapest = &menuItem;
            }
        }
        return cheapest->name;
    }

    vector<string> drinksOnly() {
        vector<string> drinks;
        for (auto& menuItem : menu) {
            if (menuItem.type == "drink") {
                drinks.push_back(menuItem.name);
            }
        }
        return drinks;
    }

    vector<string> foodOnly() {
        vector<string> food;
        for (auto& menuItem : menu) {
            if (menuItem.type == "food") {
                food.push_back(menuItem.name);
            }
        }
        return food;
    }
};

int main() {
    CoffeeShop shop("Java Beans");
    
    shop.addMenuItem("Espresso", "drink", 3.5);
    shop.addMenuItem("Latte", "drink", 4.0);
    shop.addMenuItem("Sandwich", "food", 5.0);

    cout << shop.addOrder("Latte") << endl;
    cout << shop.addOrder("Sandwich") << endl;
    cout << shop.addOrder("Cake") << endl;

    cout << "Due Amount: $" << shop.dueAmount() << endl;
    cout << shop.fulfillOrder() << endl;
    cout << shop.fulfillOrder() << endl;
    cout << shop.fulfillOrder() << endl;

    return 0;
}
