#include <iostream>
using namespace std;

class Book {
private:
    string title, author, publisher;
    double price;
    int stock;

public:
    Book(string t, string a, string p, double pr, int s) : title(t), author(a), publisher(p), price(pr), stock(s) {}

    bool isAvailable(string t, string a) {
        return (title == t && author == a);
    }

    void display() {
        cout << "Title: " << title << "\nAuthor: " << author << "\nPublisher: " << publisher 
             << "\nPrice: " << price << "\nStock: " << stock << endl;
    }

    void purchase(int quantity) {
        if (quantity <= stock) {
            cout << "Total Cost: " << price * quantity << endl;
            stock -= quantity;
        } else {
            cout << "Required copies not in stock." << endl;
        }
    }
};

int main() {
    Book book1("C++ Basics", "John Doe", "Tech Press", 50.0, 10);
    
    string title, author;
    int quantity;
    
    cout << "Enter book title: ";
    cin >> title;
    cout << "Enter author name: ";
    cin >> author;

    if (book1.isAvailable(title, author)) {
        book1.display();
        cout << "Enter quantity: ";
        cin >> quantity;
        book1.purchase(quantity);
    } else {
        cout << "Book not available." << endl;
    }

    return 0;
}
