#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Book {
public:
    string name;

    Book(string name) : name(name) {}

    bool operator<(const Book& other) const {
        return name < other.name;
    }

    bool operator>(const Book& other) const {
        return name > other.name;
    }

    bool operator==(const Book& other) const {
        return name == other.name;
    }
};


class Library {

public :

    vector<Book> books;

    void addBook(const Book& book) {
        books.push_back(book);
    }

    void removeBook(const string& bookName) {

        for(int i=0;i<books.size();i++){
            if(books[i].name == bookName){
                books[i].name = books[books.size()-1].name ;
                books.pop_back();
                return ;
            }
        }

        cout << "Book not found." << endl;

    }

    void displayBooks() const {
        for (const auto& book : books) {
            cout << book.name << endl;
        }
    }

};

int main() {

    Library library1;
    library1.addBook(Book("Book 1"));
    library1.addBook(Book("Book 5"));
    library1.addBook(Book("Book 6"));
    library1.addBook(Book("Book 2"));
    library1.addBook(Book("Book 4"));
    library1.addBook(Book("Book 3"));

    cout << "Library 1 books:" << endl;
    library1.displayBooks();

    library1.removeBook("Book 1");

    sort(library1.books.begin(),library1.books.end()) ;

    library1.displayBooks();

    return 0;
}
