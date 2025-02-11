#include <iostream>
using namespace std;

class Book {
private:
    string bookName, isbn, author, publisher;

public:
    Book() {} 

    void setBookDetails(string name, string id, string writer, string pub) {
        this->bookName = name;
        this->isbn = id;
        this->author = writer;
        this->publisher = pub;
    }

    void showBookInfo() {
        cout << "Title: " << bookName << "\nISBN: " << isbn
             << "\nAuthor: " << author << "\nPublisher: " << publisher << "\n";
    }
};

int main() {
    Book books[5];
    string name, id, writer, pub;

    cout << "Enter details for 5 books (Title, ISBN, Author, Publisher):\n";
    for (int i = 0; i < 5; i++) {
        cout << "\nBook " << i + 1 << ":\n";
        cin >> ws; 
        getline(cin, name);
        getline(cin, id);
        getline(cin, writer);
        getline(cin, pub);
        books[i].setBookDetails(name, id, writer, pub);
    }

    cout << "\nBook List:\n";
    for (int i = 0; i < 5; i++) {
        cout << "\nBook " << i + 1 << ":\n";
        books[i].showBookInfo();
    }

    return 0;
}
