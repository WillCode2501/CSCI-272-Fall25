// MemberAccount.cpp
// Stores member account information for the library system

#include "MemberAccount.h"
#include <iomanip>
#include <sstream>
#include <fstream>

// Full constructor, fills everything
MemberAccount::MemberAccount(const string& username, const string& password, const string& name, const string& email, const string& memberID, const string& role) {
    this->username = username;
    this->password = password;
    this->name = name;
    this->email = email;
    this->memberID = memberID;
    this->role = role;
}

// Simple constructor, fill only username and password, everything else default
MemberAccount::MemberAccount(const string& username, const string& password) {
    this->username = username;
    this->password = password;
    this->name = "";
    this->email = "";
    this->memberID = "";
    this->role = "user";
}

// Default constructor
MemberAccount::MemberAccount() {
    this->username = "";
    this->password = "";
    this->name = "";
    this->email = "";
    this->memberID = "";
    this->role = "user";
}

// Getters (read without modifying data)
string MemberAccount::getUsername() const {return username;}
string MemberAccount::getPassword() const {return password;}
string MemberAccount::getName() const {return name;}
string MemberAccount::getEmail() const {return email;}
string MemberAccount::getMemberID() const {return memberID;}
string MemberAccount::getRole() const {return role;}

// Setters (update data)
void MemberAccount::setUsername(const string& username) {this->username = username;}
void MemberAccount::setPassword(const string& password) {this->password = password;}
void MemberAccount::setName(const string& name) {this->name = name;}
void MemberAccount::setEmail(const string& email) {this->email = email;}
void MemberAccount::setMemberID(const string& memberID) {this->memberID = memberID;}
void MemberAccount::setRole(const string& role) {this->role = role;}

// Check if login credentials match
bool MemberAccount::login(const string& username, const string& password) const {
    return (this->username == username && this->password == password);
}

// Check if member is staff
bool MemberAccount::isStaff() const {
    return (role == "staff");
}

// check if member is user
string MemberAccount::roleLabel() const {
	return role;
}

// Returns member info as readable string
string MemberAccount::toString() const {
    return "Username: " + username + 
		   " | Name: " + name + 
		   " | Email: " + email + 
           " | ID: " + memberID + 
		   " | Role: " + roleLabel();
}

// Returns member info in file format (pipe-separated)
string MemberAccount::toFileFormat() const {
    return username + "|" + password + "|" + name + "|" + email + "|" + memberID + "|" + role;
}

// Display member info in formatted columns
void MemberAccount::display() const {
    cout << setw(15) << left << username
         << setw(20) << left << name
         << setw(25) << left << email
         << setw(10) << left << memberID
         << setw(10) << left << roleLabel() << endl;
}

// Read line load from file
vector<MemberAccount*> MemberAccount::loadFromFile(const string& filename) {
    vector<MemberAccount*> members;
    ifstream inFile(filename);

    if (!inFile) {
        cerr << filename << " could not be opened!" << endl;
        exit(EXIT_FAILURE);
    }

    string line;
    while (getline(inFile, line)) {
        istringstream iss(line);
        string username, password, name, email, memberID, role;

        getline(iss, username, '|');
        getline(iss, password, '|');
        getline(iss, name, '|');
        getline(iss, email, '|');
        getline(iss, memberID, '|');
        getline(iss, role, '|');

        MemberAccount* acc = nullptr;
        if (role == "staff") {
            acc = new StaffAccount(username, password, name, email, memberID, "staff");
        } else {
            acc = new UserAccount(username, password, name, email, memberID, "user");
        }
        members.push_back(acc);
    }

    return members;
}



// Save data to file
void MemberAccount::saveToFile(const vector<MemberAccount*>& members, const string& filename) {
    ofstream outFile(filename);
    if (outFile.is_open()) {
        for (const MemberAccount* member : members) {
            outFile << member->toFileFormat() << endl;
        }
        outFile.close();
        cout << "Members saved to " << filename << endl;
    } else {
        cerr << "Error: " << filename << " could not open file for writing." << endl;
        exit(EXIT_FAILURE); // Terminate the program with a failure status
    }
}

// StaffAccout override
bool StaffAccount::isStaff() const { return true;}
string StaffAccount::roleLabel() const { return "staff";}


// UserAccount override
bool UserAccount::isStaff() const { return false;}
string UserAccount::roleLabel() const { return "user";}



