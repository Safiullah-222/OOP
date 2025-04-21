#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Flight {
private:
    string flightNumber;
    string departure;
    string arrival;
    int capacity;
    int bookedSeats;

public:
    Flight(string fn, string d, string a, int c) {
        flightNumber = fn;
        departure = d;
        arrival = a;
        capacity = c;
        bookedSeats = 0;
    }

    bool bookSeat() {
        if (bookedSeats < capacity) {
            bookedSeats++;
            return true;
        }
        return false;
    }

    bool cancelSeat() {
        if (bookedSeats > 0) {
            bookedSeats--;
            return true;
        }
        return false;
    }

    bool upgradeSeat() {
        if (bookedSeats > 0) {
            return true;
        }
        return false;
    }

    void showStatus() {
        cout << "Flight: " << flightNumber << ", From: " << departure << ", To: " << arrival << ", Booked: " << bookedSeats << "/" << capacity << endl;
    }
};

class Passenger {
private:
    string name;
    string id;

public:
    Passenger(string n, string i) {
        name = n;
        id = i;
    }

    void requestBooking(Flight &f) {
        if (f.bookSeat()) {
            cout << name << " booked a seat." << endl;
        } else {
            cout << name << " failed to book a seat." << endl;
        }
    }

    void requestCancellation(Flight &f) {
        if (f.cancelSeat()) {
            cout << name << " canceled their seat." << endl;
        } else {
            cout << name << " had no seat to cancel." << endl;
        }
    }

    void requestUpgrade(Flight &f) {
        if (f.upgradeSeat()) {
            cout << name << " upgraded their seat." << endl;
        } else {
            cout << name << " can't upgrade without a booking." << endl;
        }
    }
};

int main() {
    Flight flight1("PK301", "Karachi", "Lahore", 2);

    Passenger p1("Ahmed", "P001");
    Passenger p2("Fatima", "P002");
    Passenger p3("Ali", "P003");

    p1.requestBooking(flight1);
    p2.requestBooking(flight1);
    p3.requestBooking(flight1);

    flight1.showStatus();

    p1.requestUpgrade(flight1);
    p3.requestUpgrade(flight1);

    p2.requestCancellation(flight1);
    flight1.showStatus();

    return 0;
}
