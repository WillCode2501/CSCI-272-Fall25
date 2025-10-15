#include <iostream>
#include <sstream>
#include <istream>
#include <string>

using namespace std;

//int main() {
//	string input;
//	int number; 
//
//	cout << "Enter an integer between 0 and 100: ";
//	cin >> input;
//
//	istringstream iss(input); // Created a stream from a string (input)
//
//	if (iss >> number) {  // basically stoi(), turning the input from a string to integer
//		if(number >= 0 && number <= 100) 
//			cout << "Valid Input: " << number << endl;
//		else 
//			cout << number << " out of range!\n";
//	} else {
//		cout << "Invalid input (not an integer)\n";
//	}
//
//	return 0;
//}

// Function declaration
// Const: don't change the data
// string&: get the reference of the variable instead of making a whole copy of it
bool isValidPhoneNumber(const string& input);

int main(){
	string input;
	
	do {
		cout << "Enter a U.S. Phone number (e.g., (800)222-4455): ";
		getline(cin, input); 
		
		if(!isValidPhoneNumber(input)){
			cout << "Invalid Input, try again\n";
		}
	} while (!isValidPhoneNumber(input));
	
	cout << "Valid Input \n";
	
//	// call a validation function for phone number formatting
//	if (isValidPhoneNumber(input)){
//		cout << "VALID Phone Number!";
//	} else {
//		cout << "INVALID Phone Number, follow the format!";
//	}
	
	return 0;
}

// Declare the function
bool isValidPhoneNumber(const string& input) {
	istringstream iss(input);
	
	char openParen, closeParen, dash;
	int areaCode, firstPart, secondPart;
	
	if(iss >> openParen >> areaCode >> closeParen >> firstPart >> dash >> secondPart) {
		if(openParen == '(' && closeParen == ')' && dash == '-' && 
			areaCode >= 100 && areaCode <= 999 && firstPart >= 000 && firstPart <= 999 &&
			secondPart >= 0000 && secondPart <= 9999) {
				return true;
		}
		
	}
	return false;
}