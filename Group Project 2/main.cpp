// main.cpp
#include "Library.h"

int main() {
    Library myLibrary;
    int choice;
    
    cout << "=== LibraVault ===\n";
    
    // Login first
    while (!myLibrary.login()) {
        cout << "Please try again.\n";
    }
    
    do {
        cout << "\n=== Library Menu ===\n";
        cout << "1. Add Book\n";
        cout << "2. Add Member\n";
        cout << "3. Remove Book\n";
        cout << "4. Remove Member\n";
        cout << "5. View Member Accounts\n";
        cout << "6. View Book Catalog\n";
        cout << "7. View Transactions\n";
        cout << "8. Checkout Book\n";
        cout << "9. Return Book\n";
        cout << "10. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        if (choice == 1) {
            myLibrary.AddBook();
        } else if (choice == 2) {
            myLibrary.AddMember();
        } else if (choice == 3) {
            myLibrary.RemoveBook();
        } else if (choice == 4) {
            myLibrary.RemoveMember();
        } else if (choice == 5) {
            myLibrary.viewAccount();
        } else if (choice == 6) {
            myLibrary.ViewBook();
        } else if (choice == 7) {
            myLibrary.ViewTransaction();
        } else if (choice == 8) {
            myLibrary.CheckoutBook();
        } else if (choice == 9) {
            myLibrary.ReturnBook();
        // Adding an exception handling
        } else if (cin.fail() || choice < 1 || choice > 10) {
			cin.clear(); // Reset state bits
			cin.ignore(10000, '\n');  // Discard up to 1000 characters or until new line
		}

        
    } while (choice != 10);
    
    myLibrary.logout();
    cout << "\nThank you for using the Library System!\n";
    
    return 0;
}



