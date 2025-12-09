// Transaction.h 
// Stores Transaction data: loan date, due date, and member who loaned
#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Transaction {
private:
    string bookTitle;
    string member;        // Member who loaned
    string loanDate;      // Date the book was loaned
    string dueDate;       // Due date for return
    string returnDate;    // Actual return date
    string status;        // Status: "checked out" or "returned"

public:
    // Constructors
    Transaction(const string& bookTitle, const string& member, const string& loanDate, const string& dueDate, const string& returnDate, const string& status);
    Transaction(const string& bookTitle, const string& member, const string& loanDate, const string& dueDate);
    Transaction();
    
    // Getters (no modification)
    string getBookTitle() const;
    string getMember() const;
    string getLoanDate() const;
    string getDueDate() const;
    string getReturnDate() const;
    string getStatus() const;
    
    // Setters (controlled modification)
    void setBookTitle(const string& bookTitle);
    void setMember(const string& member);
    void setLoanDate(const string& loanDate);
    void setDueDate(const string& dueDate);
    void setReturnDate(const string& returnDate);
    void setStatus(const string& status);
    
    // Display methods
    string toString() const;
    string toFileFormat() const;
    void display() const;
    
    // File I/O (Staff only functions)
    static void saveToFile(const vector<Transaction>& transactions, const string& filename);
    static vector<Transaction> loadFromFile(const string& filename);
    static void logTransaction(const Transaction& t, const string& filename);
};

#endif



