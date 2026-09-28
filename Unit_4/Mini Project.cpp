#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Book {
private:
    string isbn;
    string title;
    string author;
    string category;
    bool available;

public:
    Book(string i, string t, string a, string c, bool status = true)
        : isbn(i), title(t), author(a), category(c), available(status) {}

    void display() const {
        cout << "ISBN: " << isbn
             << " | Title: " << title
             << " | Author: " << author
             << " | Category: " << category
             << " | Availability: "
             << (available ? "Available" : "Issued") << endl;
    }

    bool search(const string& keyword) const {
        return isbn == keyword ||
               title == keyword ||
               author == keyword;
    }

    void issueBook() {
        if (available) {
            available = false;
            cout << "Book issued successfully." << endl;
        } else {
            cout << "Book is already issued." << endl;
        }
    }

    void returnBook() {
        if (!available) {
            available = true;
            cout << "Book returned successfully." << endl;
        } else {
            cout << "Book is already available." << endl;
        }
    }

    void saveToFile(ofstream& out) const {
        out << isbn << ','
            << title << ','
            << author << ','
            << category << ','
            << available << '\n';
    }
};

int main() {
    vector<Book> books;

    books.emplace_back(
        "978001",
        "C++ Programming",
        "Bjarne",
        "Programming"
    );

    books.emplace_back(
        "978002",
        "Data Structures",
        "Mark",
        "Computer Science"
    );

    books.emplace_back(
        "978003",
        "Object Oriented Programming",
        "Robert",
        "Programming"
    );

    cout << "=== Library Book Management System ===" << endl;

    cout << "\n=== Available Books ===" << endl;

    for (const auto& book : books) {
        book.display();
    }

    cout << "\n=== Issuing Book ===" << endl;

    books[0].issueBook();

    cout << "\n=== Updated Book Status ===" << endl;

    books[0].display();

    cout << "\n=== Returning Book ===" << endl;

    books[0].returnBook();

    cout << "\n=== Final Book Status ===" << endl;

    books[0].display();

    ofstream file("library_books.txt");

    if (!file) {
        cerr << "Unable to open file." << endl;
        return 1;
    }

    for (const auto& book : books) {
        book.saveToFile(file);
    }

    file.close();

    cout << "\nBook records saved to library_books.txt" << endl;

    return 0;
}
