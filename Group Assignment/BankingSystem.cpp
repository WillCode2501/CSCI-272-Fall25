// Names: Jathan, Wei, Baldimir
// Date: 11/1/25
// BankingSystem.cpp

#include <iostream> // cin and cout
#include <vector> // vector to store transactions history
#include <string> // OwnerName and other types of strings
#include <limits> // for cin.ignore(numberic_limits<streamsize>::max(), ‘\n’)
#include <iomanip> // for fixed << setprecision(2)
#include <sstream> // using ostringstream for history and fixed setprecision doubles
#include "BankAccount.h"

using namespace std;

// Creating an account and initial deposit
BankAccount::BankAccount(const string& name, int num, double initdeposit) {
	OwnerName = name;
	AccountNumber = num;
	Balance = initdeposit;

	// First transaction history message, use to_string to turn double into string
	// Using ostringstream to combine string and double including formatting
	// Also it makes it easier to combine everything and add to history vector
	ostringstream oss;
	oss << " - Account created with initial deposit: $"  << fixed << setprecision(2) << initdeposit;
	history.push_back(oss.str());
}

// Depositing into balance (must be positive)
// Using the function to access private data to modify Balance and history.
void BankAccount::deposit(double amount) {
	ostringstream oss;
	if (amount > 0) {
		oss << " - Deposited $" << fixed << setprecision(2) << amount;
		Balance += amount;
		history.push_back(oss.str());
		cout << oss.str() << endl;
	} else
		cout << "Deposited amount cannot be zero or negative." << endl;
}

// Withdraw, since it’s bool it must return true or false.
// Using the function to access private data to modify Balance and history vector.
bool BankAccount::withdraw(double amount){
	ostringstream oss;
	// withdrew amount is between 0 < amount < balance
	if (amount <= Balance && amount > 0) {
		Balance -= amount;
		oss << " - Withdrew $" << fixed << setprecision(2) << amount;
		history.push_back(oss.str());
		cout << oss.str() << endl; 
		// withdrew amount is exactly equal to balance
		if (Balance == 0)
			cout << "Balance is now zero" << endl;
		return true;
	// withdrew amount is greater than balance
	} else if (amount > Balance) {
		cout << "Insufficient funds." << endl;
		return false;
	}
	// withdrew amount is equal to or less than 0
	else {
		cout << "Amount cannot be zero or negative, try again." << endl;
		return false;
	}
}	

// Check Balance from private
double BankAccount::getBalance() const{
	return Balance;
}

// Displays Account information from private, without balance because getBalance() has it.
void BankAccount::display() const{
	cout << "Account Info" << endl;
	cout << "Owner name: " << OwnerName << endl;
	cout << "Account number: " << AccountNumber << endl;
}

// Display transaction history, using history.size() to check the amount of history recorded.
void BankAccount::showHistory() const {
	cout << "Transaction History " << "(" << history.size() << "):" << endl;
	// for range loop, to print each history individually
	for (string line: history) {
		cout << line << endl;
	}
}

// Replace all the cin.fail(), cin.clear(), cin.ignore(), and cout “Invalid Input”, organize codes
// Using template so it works for both int and double input
// Keep the loop going until cin.fail() is false, then it would break out of this while loop
template <typename T>
void InputValidation(T& input) {
	while (true) {
		cin >> input;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input, try again!" << endl;
		} else 
			break;
	}
}

int main() {
	cout << " === Banking System === " << endl;

	// Ask for owner name
	string ownername;
	cout <<  "Enter owner name: " ;
	getline(cin, ownername);

	// Ask for account number, check if the input is really integer
	int accountnumber;
	cout << "Enter account number: ";
	InputValidation(accountnumber);
	// Just put it here because the account number shouldn't be 0 or negative.
	while (accountnumber <=0) {
		cout << "Account number cannot be zero or negative.";
		InputValidation(accountnumber);
	}
	
	// Ask for initial deposit (positive number), check if the input is really double
	double initialdeposit;
	cout << "Enter initial deposit (>0): ";
	InputValidation(initialdeposit);
	// Loop until the input is greater than 0
	while (initialdeposit <=0) {
		cout << "Deposit cannot be zero or negative.";
		InputValidation(initialdeposit);
	}

	// Create object for BankAccount
	// Convert the previous input to constructor and set account
	BankAccount account(ownername, accountnumber, initialdeposit);

	// Menu and choice selection
	int choice;
	double deposited, withdrew;
	
	// Loop the menu after every selected option until user exit
	do {
		cout << endl;
		cout << "Menu: " << endl;
		cout << "1) Deposit" << endl;
		cout << "2) Withdraw" << endl;
		cout << "3) Show Balance" << endl;
		cout << "4) Show Account Info" << endl;
		cout << "5) Show Transaction History" << endl;
		cout << "6) Exit" << endl;

		// Check if choice is valid
		cout << "Choose option: ";
		InputValidation(choice);
	
		// Using switch for smoother response than if-else statement
		switch (choice){
    		case 1: 
    			// Checks deposited is valid, then go through the deposit function
				cout << "Amount to deposit: ";
				InputValidation(deposited);
				account.deposit(deposited);
				break;
			case 2:
				// Checks withdrew is valid, then go through the withdraw function
        		cout << "Amount to Withdraw: ";
        		InputValidation(withdrew);
        		account.withdraw(withdrew);
        		break;
    		case 3:
    			// Print current balance
				cout << "Current Balance: $" << fixed << setprecision(2) << account.getBalance() << endl;
        		break;
    		case 4:
    			// Display only name and account number
				account.display();
        		break;
    		case 5:
    			// Show successful transaction history
				account.showHistory();
				break;
    		case 6:
        		cout << "Goodbye!" << endl;
        		break;
    		default:
        		cout << "Invalid choice, try again." << endl;
        		break;
    	}
	} while (choice != 6); // Loop until user exit

	return 0;
}

// Individual Reflection:

// Wei - Since BankAccount.h could only contain class definition, it took a while and some research to figure 
// out how to call the prototype from BankAccount.h to BankingSystem.cpp. It was also annoying because each function 
// has a different return type and the only way to modify Balance and history is via those prototypes, so I’ve learned 
// that while bool only returns true or false I could still write modifications inside this type of function. Lastly is 
// the ostringstream, I tried to use string to store the string and amount but it wasn’t in two decimal points so I tried 
// including setprecision but since it’s a string not an cout I couldn’t use it. So in the end I had to use ostringstream 
// to convert everything to string and it allowed me to use fixed << setprecision(2) << amount and easily store everything 
// for history vector to push_back().

// Jathan - When revising the menu choice I developed for the user, I was having trouble figuring out why the code wasn’t 
// functioning. I believe this error took me about 10 minutes to realize that instead of inputting “==” to address a = for 
// a statement I only inputted a sign equal symbol. From what I learned in this project is how to develop a code in a small 
// amount of time. I also learned how to accurately use “<sstream>” data_types. Most importantly by analysing my teammates 
// work I learned different ways to deliver a code for this specific task.

// Bladimir - The most difficult part was figuring out why the menu output would show the same thing regardless of what choice 
// the user put. If you typed in 1, 2 ,or 4 etc then the program would ask the user to choose the menu options again. I figured 
// out that the issue was the “void InputValidation(T& input)” part, it wasn’t passing the variable by reference and any changes 
// made wouldn’t affect variables outside the function. It was a challenge to figure out at the beginning because there were a 
// lot of other small issues like “” not working properly, variables were misspelled or had multiple variations, and there wasn’t 
// any endl; after some sentences. Although it didn’t take much time to fix, I learned that small mistakes like those could lead 
// you to missing out on crucial details which would impede your program from running properly. 
