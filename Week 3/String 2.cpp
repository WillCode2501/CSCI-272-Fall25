#include <iostream>
#include <string>

using namespace std;

int main() {
//	string sentence = "The quick brown fox jumps over the lazy dog.";
//	string word = sentence.substr(4,5); // index 4 = q, 5 length: quick
//	cout << word << endl;
//	size_t found = sentence.find("lazy");
//	if (found != string::npos) {
//		cout << "'lazy' found at position " << found << endl; // lazy found at position 35 (first letter index)
//	} else {
//		cout << "'lazy' not found!" << endl;
//	}

	string message = "Hello, World!";
	// Changing case
	for (char& c: message) {
		c = toupper(c); // convert to uppercase
	}
	cout << "Uppercase Message: " << message << endl; // Uppercase Message: HELLO, WORLD!
	// Replacing substrings
	message.replace(7, 5, "C++"); // Index 7 is W, length 5 so World is being replaced with C++
	cout << "Replaced Message: " << message << endl; // Replaced Message: HELLO, C++!
	// Inserting substring
	message.insert (5, "Awesome "); // Index 5 is "," so inserting Awesome in front of ","
	cout << "Modified Message: " << message << endl; // Modified Message: HELLOAwesome , C++!
	
	return 0;
}

// for string comparison uses ASCII such that, A < a, Apple < apple, aPPle < apPle.
// 'P' is 80 while 'p' is 112 in ASCII, so P < p, similar cases with A and a.
// The uppercase letter are smaller than the lower case

