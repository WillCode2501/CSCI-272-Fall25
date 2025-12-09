// Transaction.cpp
// Stores Transaction data: loan date, due date, and member who loaned
#include "Transaction.h"
#include <iomanip>
#include <sstream>
#include <fstream>

// Full constructor
Transaction::Transaction(const string& bookTitle, const string& member, const string& loanDate, const string& dueDate, const string& returnDate, const string& status) {
    this->bookTitle = bookTitle;
    this->member = member;
    this->loanDate = loanDate;
    this->dueDate = dueDate;
    this->returnDate = returnDate;
    this->status = status;
}
// Constructor for new loan (no return date yet)
Transaction::Transaction(const string& bookTitle, const string& member, const string& loanDate, const string& dueDate) {
    this->bookTitle = bookTitle;
    this->member = member;
    this->loanDate = loanDate;
    this->dueDate = dueDate;
    this->returnDate = "";
    this->status = "checked out";
}

// Default constructor
Transaction::Transaction() {
    this->bookTitle = "";
    this->member = "";
    this->loanDate = "";
    this->dueDate = "";
    this->returnDate = "";
    this->status = "";
}

// Getters
string Transaction::getBookTitle() const { return bookTitle; }
string Transaction::getMember() const { return member; }
string Transaction::getLoanDate() const { return loanDate; }
string Transaction::getDueDate() const { return dueDate; }
string Transaction::getReturnDate() const { return returnDate; }
string Transaction::getStatus() const { return status; }

// Setters
void Transaction::setBookTitle(const string& bookTitle) { this->bookTitle = bookTitle; }
void Transaction::setMember(const string& member) { this->member = member; }
void Transaction::setLoanDate(const string& loanDate) { this->loanDate = loanDate; }
void Transaction::setDueDate(const string& dueDate) { this->dueDate = dueDate; }
void Transaction::setReturnDate(const string& returnDate) { this->returnDate = returnDate; }
void Transaction::setStatus(const string& status) { this->status = status; }

// Returns transaction data as a readable string
string Transaction::toString() const {
    return bookTitle + " | " + member + " | " + loanDate + " | " + dueDate + " | " + returnDate + " | " + status;
}

// Returns transaction data in file format (pipe-separated)
string Transaction::toFileFormat() const {
    return bookTitle + "|" + member + "|" + loanDate + "|" + dueDate + "|" + returnDate + "|" + status;
}

// Displays transaction data in formatted columns
void Transaction::display() const {
    cout << setw(25) << left << bookTitle
         << setw(15) << left << member
         << setw(12) << left << loanDate
         << setw(12) << left << dueDate
         << setw(12) << left << returnDate
         << setw(12) << left << status << endl;
}

// STAFF ONLY: Save all transactions to file
void Transaction::saveToFile(const vector<Transaction>& transactions, const string& filename) {
    ofstream outFile(filename);
    if (outFile.is_open()) {
        for (const Transaction& t : transactions) {
            outFile << t.toFileFormat() << endl;
        }
        outFile.close();
        cout << "Transactions saved to " << filename << endl;
    } else {
        cout << "Error: Could not open file for writing." << endl;
    }
}

// STAFF ONLY: Load all transactions from file
vector<Transaction> Transaction::loadFromFile(const string& filename) {
    vector<Transaction> transactions;
    ifstream inFile(filename);
    
    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            istringstream iss(line);
            string bookTitle, member, loanDate, dueDate, returnDate, status;
            
            getline(iss, bookTitle, '|');
            getline(iss, member, '|');
            getline(iss, loanDate, '|');
            getline(iss, dueDate, '|');
            getline(iss, returnDate, '|');
            getline(iss, status, '|');
            
            Transaction t(bookTitle, member, loanDate, dueDate, returnDate, status);
            transactions.push_back(t);
        }
        inFile.close();
    } else {
        cout << "Error: Could not open file for reading." << endl;
    }
    
    return transactions;
}

// STAFF ONLY: Log a single transaction to file (append)
void Transaction::logTransaction(const Transaction& t, const string& filename) {
    

	ofstream outFile(filename, ios::app);
	// check if file exist, if not, show a warning
	if (!outFile) { 
		cerr << filename << " could not be opened!" << endl;
    	exit(EXIT_FAILURE); // Terminate the program with a failure status
	} else if (outFile.is_open()) {
        outFile << t.toFileFormat() << endl;
        outFile.close();
    }
}




