#include <iostream>
#include <sstream>
#include <string>

using namespace std;

//int main() {
//	double pi = 3.14159265359;
//	char ch = 'X';
//	// Convert the double to a string
//	string strValue = to_string(pi);
//	// Obtain a pointer to the character data
//	const char* charPtr = strValue.c_str();
//	// Print the double and the char* representation
//	cout << "Double: " << pi << endl;
//	cout << "char* : "; 
//	cout.write(charPtr, 7) << endl;
//	//reinterpret_cast is a low-level cast operator
//	cout.write(reinterpret_cast<const char*>(&pi), sizeof(pi));
//	// Output of characters using the put member function
//	cout << "\nCharacter Output: "; cout.put(ch).put('\n');
//	
//	return 0; 
//}

//// Define a Person class
//class Person {
//	public:
//		string name;
//		int age;
//		string gender;
//};
//
//class Name {
//	public:
//		string first;
//		string middle;
//		string last;
//};
//
//
//int main() {
//	string inputString = "Alice 30 Female";
//	// istringstream is a class in C++ that represents an input stream associated
//	//with a string. It allows you to treat a string as a source of input, just like you
//	//would with cin for keyboard input or a file stream for file input.
//	istringstream input(inputString);
//	Person person;
//	// Read data from the stringstream and populate the person object
//	// Using >> to read formatted input while skipping whitespace
//	input >> person.name >> person.age >> person.gender;
//	cout << inputString << endl;
//	cout << "Name: " << person.name << endl;
//	cout << "Age: " << person.age << endl;
//	cout << "Gender: " << person.gender << endl << endl;
//	
//	// Self made example to separate full names into first, middle, and last
//	string fullName = "John Doe Smith";
//	istringstream anything(fullName); 
//	Name name;
//	anything >> name.first >> name.middle >> name.last;
//	cout << "Full Name: " << fullName << endl;
//	cout << "First Name: " << name.first << endl;
//	cout << "Middle Name: " << name.middle << endl;
//	cout << "Last Name: " << name.last << endl;
//	
//	return 0;
//}


// Unformatted I/O using read, gcount and write
int main() {
	const int SIZE = 80;
	char buffer[SIZE];
	
	// Use function read to input characters into buffer
	cout << "Enter a sentence: \n";
	cin.read(buffer, 20);
	
	// Use functions write and gcount to display buffer characters
	cout << "\nThe sentence entered was: \n";
	cout.write(buffer, cin.gcount()); // print out exactly 20 characters from string entered in read
	cout << endl;
	
	return 0;
}