#include <iostream>
#include <string>
using namespace std;


class Book {
protected:
    string genre;
public:
    Book(string bookGenre) : genre(bookGenre) {}
    virtual void displayDetails() {
        cout << "Genre: " << genre << endl;
    }
};


class Novel : public Book {
private:
    string title;
    string author;
public:
    Novel(string bookTitle, string bookAuthor) : Book("Novel"), title(bookTitle), author(bookAuthor) {}
    void displayDetails() override {
        cout << "Genre: " << genre << ", Title: " << title << ", Author: " << author << endl;
    }
};


class Mystery : public Book {
private:
    string title;
    string author;
public:
    Mystery(string bookTitle, string bookAuthor) : Book("Mystery"), title(bookTitle), author(bookAuthor) {}
    void displayDetails() override {
        cout << "Genre: " << genre << ", Title: " << title << ", Author: " << author << endl;
    }
};

int main() {
    
    Novel n1("Pride and Prejudice", "Jane Austen");
    Mystery m1("Sherlock Holmes", "Arthur Conan Doyle");

    
    n1.displayDetails();
    m1.displayDetails();

    return 0;
}
