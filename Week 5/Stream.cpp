//// Streams
//
//#include <iostream> // cout, cin, cerr, clog
//#include <iomanip> //setw(int n), setprecision(int n), left, right, setfill
//using namespace std;
//
//
//int main() {
//	int number;
//	
//	cout << "Enter a number: " << endl;
//	cin >> number;
//	cout << "You entered: " << number << endl;
//	
//	cerr << "This is an error message\n";
//	clog << "This is a log message\n";
//	return 0;
//	
//}


//#include <iostream>
//#include <iomanip>
//
//using namespace std;
//
//int main() {
//	string item = "Coffee";
//	double price = 2.50;
//	double tax = 0.201;
//	double total = price + tax;
//	
//	cout << setw(10) << left << "Item" << 
//		setw(10) << right << "Price" << endl;
//	cout << setw(10) << left << item <<
//		setw(10) << right << fixed << setprecision(3) << total << endl;
//	cout << setw(10) << setfill('-') << "Menu" << endl << 
//		setw(10) << left << item << setw(10) << right << total << endl;
	

# include <iostream>
# include <string>
using namespace std;

class Card {
	public:
		int cardNumber;
		string cardHolder;
};

// typeof alias CardPtr to for Card*
typedef Card* CardPtr; // CardPtr is an alias of Card* 

// Fun part
typedef double DB; // DB is an alias of double
typedef int ROY; // Roy is an alias of int

int main() {
	Card myCard; 
	myCard.cardNumber = 12345;
	myCard.cardHolder = "Alice";
	
	CardPtr ptrToCard = &myCard;
	
	// Access the card information using the pointer
	cout << "Card Number: " << ptrToCard->cardNumber << endl;
	cout << "Card Holder: " << ptrToCard->cardHolder << endl;
	
	return 0;
}