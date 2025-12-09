// Library.h
// Main library class that manages books, members, and transactions
#ifndef LIBRARY_H
#define LIBRARY_H

#include "BookInfo.h"
#include "MemberAccount.h"
#include "Transaction.h"
#include <iomanip>

class Library {
private:
    vector<BookInfo> books;
    vector<MemberAccount*> members;
    vector<Transaction> transactions;
    MemberAccount* loggedInMember;

public:
    Library();
    
    // Data loading/saving
    void loadData();
    void saveData();
    
    // Authentication
    bool login();
    void logout();
    bool isLoggedIn() const;
    bool isStaff() const;
    
    // Book operations
    void AddBook();
    void RemoveBook();
    void ViewBook();
    
    // Member operations
    string generateMemberID();
    void AddMember();
    void RemoveMember();
    void viewAccount();
    
    // Transaction operations
    void ViewTransaction();
    void CheckoutBook();
    void ReturnBook();
};

#endif



