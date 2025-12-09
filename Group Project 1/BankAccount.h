// Names: Jathan, Wei, Baldimir
// Date: 11/1/25
// BankAccount.h

#include <string>
#include <vector>

using namespace std;

class BankAccount {
	
// Data member hidden, can only access from data member
private: 
	string OwnerName;
	int AccountNumber;
	double Balance;
	vector<string> history;
public: 

	// Constructor
	BankAccount(const string& name, int num, double initdeposit);

	
	// member function, used to modify or display data from private
	void deposit(double amount);
	bool withdraw(double amount);
	double getBalance() const;
	void display() const;
	void showHistory() const;

};
