// BookInfo.h
// Stores book information for the library system

#ifndef BOOKINFO_H
#define BOOKINFO_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class BookInfo {
private:
    string title;
    string author;
    string isbn;
    string genre;
    int totalCopies; // copies library own
    int availableCopies; // copies not checked out

public:
    // Constructors
    BookInfo(const string& title, const string& author, const string& isbn, const string& genre, int totalCopies);
    BookInfo(const string& title, const string& author);
    BookInfo();
    
    // Getters
    string getTitle() const;
    string getAuthor() const;
    string getIsbn() const;
    string getGenre() const;
    int getTotalCopies() const;
    int getAvailableCopies() const;
    bool isAvailable() const; // check if copies > 0
    
    // Setters
    void setTitle(const string& title);
    void setAuthor(const string& author);
    void setIsbn(const string& isbn);
    void setGenre(const string& genre);
    void setTotalCopies(int copies);
    void setAvailableCopies(int copies);
    
    // Book operations
    bool checkOut();      // Returns true if checkout successful
    bool returnBook();    // Returns true if return successful
    
    // Display methods
    string toString() const;
    string toFileFormat() const;
    void display() const;
    
    // Operator overloading for formatted output
    friend ostream& operator <<(ostream& os, const BookInfo& book);
    
    // File I/O
    static void saveToFile(const vector<BookInfo>& books, const string& filename);
    static vector<BookInfo> loadFromFile(const string& filename);
};

#endif



