#include <iostream>
#include <string>

using namespace std;
class Book {
public:
    string title;
    string author;
    int year;
    Book(string t = "", string a = "", int y = 0) {
        title = t;
        author = a;
        year = y;
    }
};
class Library {
private:
    static int bookCount; // Tổng số sách
    Book books[100];      // Mảng chứa tối đa 100 quyển sách
    int bookIndex;        // Chỉ số hiện tại trong mảng

public:
    Library() {
        bookIndex = 0;
    }
    void addBook(const string& title, const string& author, int year) {
        if (bookIndex < 100) {
            books[bookIndex++] = Book(title, author, year);
            bookCount++; // Tăng số lượng sách
        } else {
            cout << "Library is full!" << endl;
        }
    }
    void printBookInfo(int index) const {
        if (index >= 0 && index < bookIndex) {
            cout << "Title: " << books[index].title << endl;
            cout << "Author: " << books[index].author << endl;
            cout << "Year: " << books[index].year << endl;
        } else {
            cout << "Invalid book index!" << endl;
        }
    }
    static int getBookCount() {
        return bookCount;
    }
};
int Library::bookCount = 0;
int main() {
    Library myLibrary;
    myLibrary.addBook("C++", "DAU", 2025);
    myLibrary.addBook("OOP C++", "DAU", 2025);
    
    myLibrary.printBookInfo(0);
    myLibrary.printBookInfo(1);
    
    cout << "so sach dang co trong thu vien: " << Library::getBookCount() << endl;
    return 0;

}