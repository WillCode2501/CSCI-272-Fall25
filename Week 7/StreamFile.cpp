#include <iostream>
#include <fstream> // for fstream
#include <cstdlib> // for exit()
#include <string>

using namespace std;

int main() {
	
	// Create an ofstream object named outClientFile, file name is client.txt
	ofstream outClientFile("clients.txt", ios::out);
	
	
	// check if file exist
	// if not, show a warning
	if (!outClientFile) { 
		cerr << "File could not be opened" << endl;
		exit(EXIT_FAILURE); // Terminate the program with a failure status
	}	
	
	// User input
	cout << "Enter the account number, name, and balance. [Space Separated]" << endl;
	cout << "Sample: 1001 Avijit 100.20" << endl;
	cout << "Enter EOF (Ctrl+Z in Windows, / Ctrl+D in Mac/Linux to end." << endl;
	
	// Setup the variables and take the input
	int account;
	string name; // no need for #include <string> because we only declaring string, not manipulating it
	double balance;
	
	// Input
	while (true) {
		if (cin >> account >> name >> balance) {
			outClientFile << account << ' ' << name << ' ' << balance << endl;
			cout << "? ";
		} else if (cin.eof()) {
			// end of file input marker
			cout << "\n End of file reached. Data Saved.\n";
			break; 
		} else {
			// input error (missing or invalid errors)
			cerr << "Invalid input format, please, re-enter (e.g., 100 Alex 50.28): \n";
			cin.clear(); // clear failbit
			cin.ignore(1000, '\n'); // discards the invalid input
		}
	}
	
	outClientFile.close(); // Close the file, saved
	
	return 0;
}