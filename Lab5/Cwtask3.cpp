#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>
#include <memory>

using namespace std;


class Catalog {
public:
    Catalog() { cout << "Catalog created" << endl; }
};

class Book {
    string title;
public:
    Book(string t) : title(t) {}
    string getTitle() { return title; }
};

class Library {
    Catalog catalog;
    vector<shared_ptr<Book>> books;
public:
    void addBook(shared_ptr<Book> book) { books.push_back(book); }
    void listBooks() { for (auto b : books) cout << b->getTitle() << endl; }
};


int main() {
 
    Library lib;
    shared_ptr<Book> b1 = make_shared<Book>("C++ Guide");
    shared_ptr<Book> b2 = make_shared<Book>("Data Structures");
    lib.addBook(b1);
    lib.addBook(b2);
    lib.listBooks();
    
    return 0;
}
