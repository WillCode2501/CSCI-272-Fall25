#include <iostream> 
#include <string> // required for string
#include <cctype> //tolower() or toupper()

using namespace std;

	 // Case insensitive compare
	 // const keep the string fix so not to modify it
	 // string& pulls the reference of the string str1 and str2 instead of making a coping
bool caseInsensitiveCompare(const string& str1, const string& str2){
	if (str1.length() != str2.length()) { // compare the length of each string
		return false;
	}
	for (size_t i = 0; i < str1.length(); i++) {
		if(tolower(str1[i]) != tolower(str2[i])){  // compare each element in lower case 
			return false;
		} 
	}
	return true;
}

int main() {
	
//	// Create a string using std::string class
//	std::string greeting = "Hello, World!";
//
//	// Print the string
//	std::cout << "String: " << greeting << std::endl;
//
//	// Access and manipulate characters in the string
//	char firstChar = greeting[0];
//	greeting[7] = 'C';
//	// Replace W with C
//	 
//	// Print the modified string
//	std::cout << "Modified String: " << greeting << std::endl;



	// Cin string
//	std::string name;
//	std::cout << "Enter your name: "; 
//	std::cin >> name; // Only allows one word, ends when meet a space
//	std::cout << "Hello, " << name << "!" << std::endl;
	
	
	
	// How to read the entire sentence
//	std::string sentence;
//	std::cout << "Enter a sentence: ";
//	std::getline(std::cin, sentence); // getline is a function which get the entire sentence
//	std::cout << "You entered: " << sentence << std::endl;
	
	
	
	// String with + operator, allows multiple strings into a single string
//	string firstName = "John";
//	string lastName = "Doe";
//
////	string fullName = firstName + " " + lastName; 
//	cout << "First Name: " << endl;
//	
//	cout << "Last Name: " << endl;
//	string fullName = firstName + " " + lastName;
//	cout << "Full Name: " << fullName << endl;
//	
//	fullName += " Jr."; // Add Jr. at the end of fullName
//	cout << "Full Name with suffix: " << fullName << endl;
//	
////	fullName = "Dr. " + fullName;
//	// or
//	fullName.insert(0, "Dr. ");
//	cout << "Full Name with Prefix " << fullName << endl;

	
	
	// Size and Length
//	string message = "Hello, World!" ; // 13 char
//	
//	int messageLength = message.length();
//	int messageSize = message.size();
//	
//	// Both Length and Size is 13
//	cout << "Length: " << messageLength << endl;
//	cout << "Size: " << messageSize << endl;
//	
//	char firstChar = message[0];
//	char lastChar = message[message.length() - 1]; // 13-1=12
//	
//	cout << "First Char: " << firstChar << endl; // H
//	cout << "Last Char: " << lastChar << endl; // !
	
	
	
	// Comparing strings
//	string str1 = "apple";
//	string str2 = "banana";
//	// comparing string in lexicoraphic (dictionary) order
//	// number of string don't matter, it's the starting character of the string matter
//	if (str1 == str2) {
//		cout << "Both strings are equal." << endl;	
//	} else if (str1 < str2) {
//		cout << "str1 is lexicographically less than str2." << endl; 
//	} else {
//		cout << "str1 is lexicographically greather than str2." << endl;
//	}
	
	
	
	// Case insensitive compare
	string str1 = "Hello";
	string str2 = "hELLo";
	
	if(caseInsensitiveCompare(str1, str2)){
		cout << "String are case-insensitive equal" << endl;
	} else {
		cout << "String are not case-insensitive equal" << endl;
	}


}
