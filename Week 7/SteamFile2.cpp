#include <iostream> 
#include <fstream> // read and write from files
#include <cstdlib> // exit()
#include <iomanip> // make read data nice

using namespace std;

// using const string& is a right habit to prevent accidental modification or loss of string
void outputline(int account, const string& name, double balance) {
	cout << left << setw(10) << account 
		 << setw(15) << name 
		 << setw(10) << fixed << setprecision(2) << right << balance << endl;
}

int main(){
	// ifstream constructor opens the file
	ifstream inClientFile("clients.txt", ios::in);
	
	if (!inClientFile) {
		cerr << "File could not be opened" << endl;
		exit(EXIT_FAILURE);
	}
	
	cout << left << setw(10) << "Account" 
		 << setw(15) << "Name"
		 << setw(10) << right << "Balance" << endl;
		 
	int account;
	string name;
	double balance;
	
	while(inClientFile >> account >> name >> balance) {
		outputline(account, name, balance);
	}
	
	inClientFile.close();
	
	return 0;
}