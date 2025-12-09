// BookInfo.cpp
// Stores book information for the library system
#include "BookInfo.h"
#include <iomanip> // for formatting in display()
#include <sstream> // for istringstream and ostringstream
#include <fstream> // ifstream and ofstream for file I/O
#include <cstdlib> // for exit()


// Full constructor, fills everything
BookInfo::BookInfo(const string& title, const string& author, const string& isbn, const string& genre, int totalCopies) {
    this->title = title;
    this->author = author;
    this->isbn = isbn;
    this->genre = genre;
    this->totalCopies = totalCopies;
    this->availableCopies = totalCopies; // new book, all available
}

// Simple constructor, only know title and author (rest as default)
BookInfo::BookInfo(const string& title, const string& author) {
    this->title = title;
    this->author = author;
    this->isbn = "";
    this->genre = "";
    this->totalCopies = 1;
    this->availableCopies = 1;
}

// Default constructor, 
BookInfo::BookInfo() {
    this->title = "";
    this->author = "";
    this->isbn = "";
    this->genre = "";
    this->totalCopies = 0;
    this->availableCopies = 0;
}

// Getters (read without modifying data)
string BookInfo::getTitle() const { return title;}
string BookInfo::getAuthor() const { return author;}
string BookInfo::getIsbn() const { return isbn;}
string BookInfo::getGenre() const { return genre;}
int BookInfo::getTotalCopies() const { return totalCopies;}
int BookInfo::getAvailableCopies() const { return availableCopies;}
bool BookInfo::isAvailable() const { return availableCopies > 0;}

// Setters (update info)
void BookInfo::setTitle(const string& title) {this->title = title;}
void BookInfo::setAuthor(const string& author) {this->author = author;}
void BookInfo::setIsbn(const string& isbn) {this->isbn = isbn;}
void BookInfo::setGenre(const string& genre) {this->genre = genre;}
void BookInfo::setTotalCopies(int copies) {this->totalCopies = copies;}
void BookInfo::setAvailableCopies(int copies) {this->availableCopies = copies;}

// Check out a book (decrease available copies)
bool BookInfo::checkOut() {
    if (availableCopies > 0) {
        availableCopies--;
        return true;
    }
    return false;
}

// Return a book (increase available copies)
bool BookInfo::returnBook() {
    if (availableCopies < totalCopies) {
        availableCopies++;
        return true;
    }
    return false;
}

// Returns book info as readable string
string BookInfo::toString() const {
    return title + " by " + author + " | ISBN: " + isbn + " | Genre: " + genre + 
           " | Available: " + to_string(availableCopies) + "/" + to_string(totalCopies);
}

// Returns book info in file format (pipe-separated)
string BookInfo::toFileFormat() const {
    return title + "|" + author + "|" + isbn + "|" + genre + "|" + 
           to_string(totalCopies) + "|" + to_string(availableCopies);
}

// Defers to operator << 
void BookInfo::display() const {
    cout << *this << endl;
}

// Display book info in formatted columns
ostream& operator<<(ostream& os, const BookInfo& book) {
    os << setw(25) << left << book.getTitle()
       << setw(20) << left << book.getAuthor()
       << setw(15) << left << book.getIsbn()
       << setw(12) << left << book.getGenre()
       << setw(10) << left << (to_string(book.getAvailableCopies()) + "/" + to_string(book.getTotalCopies()));
    return os;
}


// Save all books to file
void BookInfo::saveToFile(const vector<BookInfo>& books, const string& filename) {
    ofstream outFile(filename);
    if (outFile.is_open()) {
    	// for range loop, all bookinfo in the vector
        for (const BookInfo& book : books) {
            outFile << book.toFileFormat() << endl;
        }
        outFile.close();
        cout << "Books saved to " << filename << endl;
    } else {
        cerr << "Error: " << filename << " could not open file for writing." << endl;
        exit(EXIT_FAILURE); // Terminate the program with a failure status
    }
}

// Load all books from file
vector<BookInfo> BookInfo::loadFromFile(const string& filename) {
    vector<BookInfo> books;
    ifstream inFile(filename);
    
    // Check if file exist, if not terminate program
    if (!inFile) {
    	cerr << filename << " could not be opened!" << endl;
    	exit(EXIT_FAILURE); // Terminate the program with a failure status
	} else if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            istringstream iss(line);
            string title, author, isbn, genre;
            int totalCopies, availableCopies;
            
            // extract book info and read until '|'
            getline(iss, title, '|');
            getline(iss, author, '|');
            getline(iss, isbn, '|');
            getline(iss, genre, '|');
            
            // get totalCopies and availableCopies
            string totalStr, availStr;
            getline(iss, totalStr, '|');
            getline(iss, availStr, '|');
            
            // convert string to int
            totalCopies = stoi(totalStr);
            availableCopies = stoi(availStr);
            
            // create object book and add it to vector books
            BookInfo book(title, author, isbn, genre, totalCopies);
            book.setAvailableCopies(availableCopies);
            books.push_back(book);
        }
        inFile.close();
    }
    
    return books;
}



