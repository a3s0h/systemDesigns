#include <bits/stdc++.h>
using namespace std;



struct Book {
    string title;
    string author;
    int ISBN;
    int available_copies;
public:
 Book(string _title, string _author, int _ISBN, int _available_copies)
        : title(_title), author(_author), ISBN(_ISBN), available_copies(_available_copies) {
    }
};


// abstract library class
class Library {
    map<string,map<string,pair<int,int>>> collection;  // <name , <author , <isbn , available copies>>> 
    public:
    virtual ~Library(){};

    // Function to insert a book into the collection
    void InsertBook(Book &b) {
        collection[b.title][b.author] = make_pair(b.ISBN, b.available_copies);
    }

    virtual void BorrowBooks(Book &b) = 0;
    virtual void ReturnBooks(Book &b) = 0;
    // virtual void 
};

class LibFunctions : public Library{
public:

    void BorrowBooks(Book &b) {
        // b.available(b.available_copies-1);
        cout<<"You borrowed : "<<b.title<<" "<<" Isbn no. : "<<b.ISBN<<endl;
    }

    void ReturnBooks(Book &b) {
        // b.available(b.available_copies+1);
        cout<<"You returned : "<<b.title<<" "<<" Isbn no. : "<<b.ISBN<<endl;
    }
};

int main() {
    
    LibFunctions library; // Create an instance of LibFunctions

    // Create and insert books into the collection
    Book book1("Harry Potter", "J.K. Rowling", 123456, 5);
    Book book2("Lord of the Rings", "J.R.R. Tolkien", 789012, 3);
    Book book3("To Kill a Mockingbird", "Harper Lee", 567890, 2);

    Library &lib = library;
    lib.InsertBook(book1);
    lib.InsertBook(book2);
    lib.InsertBook(book3);

    // Borrow and return books
    lib.BorrowBooks(book1);
    lib.ReturnBooks(book2);

    return 0;

}
