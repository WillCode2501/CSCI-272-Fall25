// MemberAccount.h
// Stores member account information for the library system
#ifndef MEMBERACCOUNT_H
#define MEMBERACCOUNT_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class MemberAccount {
private:
    string username;
    string password;
    string name;
    string email;
    string memberID;
    string role;  // "staff" or "user"

public:
    // Constructors
    MemberAccount(const string& username, const string& password, const string& name, const string& email, const string& memberID, const string& role);
    MemberAccount(const string& username, const string& password);
    MemberAccount();
    
    // Getters
    string getUsername() const;
    string getPassword() const;
    string getName() const;
    string getEmail() const;
    string getMemberID() const;
    string getRole() const;
    
    // Setters
    void setUsername(const string& username);
    void setPassword(const string& password);
    void setName(const string& name);
    void setEmail(const string& email);
    void setMemberID(const string& memberID);
    void setRole(const string& role);
    
    // Authentication, checks login credentials
	bool login(const string& username, const string& password) const;
	
	// Polymorphism, allows StaffAccount and UserAccount to override behaviors
    virtual bool isStaff() const;
    virtual string roleLabel() const;
    
    // Display methods, derived classes have separate display
    string toString() const;
    string toFileFormat() const;
    void display() const;
    
    // destructor 
    virtual ~MemberAccount() = default;
    
    // File I/O
	static void saveToFile(const vector<MemberAccount*>& members, const string& filename);
    static vector<MemberAccount*> loadFromFile(const string& filename);
};

// Inheritance and Polymorphism
// Derived class for staff accounts
class StaffAccount : public MemberAccount {
public:
	// inherit constructors
	using MemberAccount::MemberAccount; 
		
	bool isStaff() const override;
	string roleLabel() const override;
};

// Derived class for regular user accounts
class UserAccount : public MemberAccount {
public:
	using MemberAccount::MemberAccount; 
		
	bool isStaff() const override;
	string roleLabel() const override;
};
#endif



