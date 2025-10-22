#include <iostream>>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

int main() {
//	ostringstream oss; // Output tring stream object oss
//	string name = "Alice";
//	int score = 95;
//	double gpa = 3.876;
//	
//	// Build a message using oss
//	oss << "Student: " << name 
//		<< " | Score: " << score
//		<< " | GPA: " << fixed << setprecision(2) << gpa;
//	
//	// convert the stream into a string
//	string message = oss.str();
//	
//	ostringstream oss1; // Created a new object
//	oss1 << "test data" << endl; // new stream
//	
//	cout << message << endl;
//	cout << oss1.str() << endl; // print the string of oss1
//	
//	return 0;
//
//
//	// Student: Alice | Score: 95 | GPA: 3.88
//	// test data
	
	

//	ostringstream outputString; // Create ostringstream object
//	string string1{"Output of several data types "};
//	string string2{"to an ostringstream object:"};
//	string string3{"\n 		  double: "};
//	string string4{"\n 			 int: "};
//	string string5{"\naddress of int: "};
//
//	double doubleValue{123.4567};
//	int intValue{22};
//
//	// Output strings, double, and int to ostringstream outputString
//	outputString << string1 << string2 << string3 << doubleValue
//	<< string4 << intValue << string5 << &intValue;
//
//	// Call str to obtain string contents of the ostringstream
//	cout << "outputString contains:\n" << outputString.str();
//
//	// Add additional characters and call str to output the updated string
//	outputString << "\nmore characters added";
//	cout << "\n\nafter additional stream insertions,\n"
//	<< "outputString contains:\n" << outputString.str() << endl;
//
//	return 0;



//	//String Stream
//	string input{"Input test 123 4.7 A"};
//	istringstream inputString{input};
//
//	string extractedString1;
//	string extractedString2;
//	int extractedInteger;
//	double extractedDouble;
//	char extractedChar;
//
//	inputString >> extractedString1 >> extractedString2 >> extractedInteger >>
//	extractedDouble >> extractedChar;
//
//	cout << "The following items were extracted from the istringstream object:"
//	<< "\nstring: " << extractedString1 << "\nstring: " << extractedString2
//	<< "\n int: " << extractedInteger << "\ndouble: " << extractedDouble
//	<< "\n char: " << extractedChar << endl;
//
//	// Attempt to read from an empty stream
//	long value;
//	inputString >> value;
//
//	// Test stream results
//	if (inputString.good()) { 
//		cout << "\nlong value is: " << value << endl; }
//	else { 
//		cout << "\ninputString is empty" << endl; }
//
//	// The following items were extracted from the istringstream object:
//	// string: Input
//	// string: test
//	//  int: 123
//	//  double: 4.7
// 	// char: A
//
//	//inputString is empty



//	string whatever = "100 3.5";
//	istringstream iss(whatever); // stream containing 100 & 3.5
//	
//	int quantity; // integer 0
//	double price; // double 0.0
//	
//	iss >> quantity >> price; 
//
//	cout << "Total cost: " << (quantity * price) << endl;
//	cout << "Quantity: " << quantity << endl;
//	cout << "Price: " << price << endl;
//
//	// Total cost: 350
//	// Quantity: 100
//	// Price: 3.5
//
//	return 0;



//	// fail() and clear() 
//	string data = "7 ate 9"; // int string int
//	istringstream iss(data); // creating input string stream object named iss
//
//	int value; // 7, 9
//	while(iss >> value){
//		cout << "Read int: " << value << endl;
//	}
//
//	// when a bad token stops the extraction
//	if (iss.fail()){
//		cout << "Stream failed. Skipping bad token... " << endl;
//		iss.clear(); // clearing the fail state
//		string bad;
//		iss >> bad;
//		cout << bad << endl;
//	}
//	
//	// resume reading the next values
//	while (iss >> value) {
//		cout << "Read int cont: " << value << endl;
//	}
//
//	// Read int: 7
//	// Stream failed. Skipping bad token...
//	// ate
//	// Read int cont: 9
//	return 0;



	string data{"Input Test 123 4.7 A"}; // string string int double char
	
	istringstream iss(data);
	
	string exString1;
	string exString2;
	int exInt;
	double exDouble;
	char exChar;
	
	iss >> exString1 >> exString2 >> exInt >> exDouble >> exChar;
	
	cout << "The following items were extracted from istringstream object: "
		 << "\nString: " << exString1
		 << "\nString: " << exString2
		 << "\n   Int: " << exInt
		 << "\nDouble: " << exDouble
		 << "\n  Char: " << exChar << endl;
	long value; 
	iss >> value;
	
	if (iss.good()){
		cout << "Value is: " << value << endl;
	} else {
		cout << "\nISS exploded. It's empty. EOF." << endl;
	}
	
	return 0;
}