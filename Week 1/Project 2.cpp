#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Constants
const int pick = 5;

// Array data
string productNames[pick] = {"BLT", "Burger", "Fries", "Soda", "Water"};
double productPrices[pick] = {4.00, 5.50, 2.00, 1.50, 1.00};
int inventory[pick] = {30, 55, 60, 100, 100};
int sales[pick] = {0};
int demand[pick] = {0};

// Function prototypes
void displayMenu();
void displayStatus();
void displayPurchases(int choice, int quantity);
void displayReceipt(int customerSales[], double customerTotal);

int main() {
    char continueShopping, anotherCustomer;
    int quantity, choice;
    double totalSales = 0.0;
    
    cout << "===========================================" << endl;
    cout << "     Welcome to the American Food Truck!    " << endl;
    cout << "===========================================" << endl;

    // New customer loop
    do {
        double customerTotal = 0.0;
        int customerSales[pick] = {0};

        cout << "\n----- New Customer -----\n";
        displayMenu();
        
        // New purchase loop
        do {
            displayStatus();
            
            // Pick option loop
            while (true) {
                cout << "Please select an option (1-5): ";
                cin >> choice;

                if (choice < 1 || choice > 5) {
                    cout << "Invalid option, please pick between 1 and 5." << endl;
                    continue;
                }
                choice--;
                break;
            }

            cout << "Enter quantity of " << productNames[choice] << " you want to buy: ";
            cin >> quantity;

            // In case user input 0 or negative quantity
            if (quantity <= 0) {
                cout << "Invalid quantity. Please enter a positive number." << endl;
                continue;
            }
            
            // Updates status list
            demand[choice] += quantity;

            if (quantity <= inventory[choice]) {
                sales[choice] += quantity;              // Overall sales
                customerSales[choice] += quantity;       // Customer tracking
                inventory[choice] -= quantity;          // Decrease quantity
                displayPurchases(choice, quantity);
                customerTotal += quantity * productPrices[choice];
            } else {
                cout << "Sorry, only " << inventory[choice] << " in stock." << endl;
            }

            cout << "Enter 'y' to continue shopping, anything else to checkout: ";
            cin >> continueShopping;

        } while (tolower(continueShopping) == 'y');

        cout << "\nCustomer Receipt:\n";
        displayReceipt(customerSales, customerTotal);

        totalSales += customerTotal;

        cout << "\nServe another customer? (y/n): ";
        cin >> anotherCustomer;

    } while (tolower(anotherCustomer) == 'y');

    cout << "\n======= End of Day Report =======\n";
    displayStatus();
    cout << "Total Sales for the Day: $" << fixed << setprecision(2) << totalSales << endl;

    return 0;
}

void displayMenu() {
    cout << "\n===== American Food Truck Menu =====\n";
    for (int i = 0; i < pick; i++) {
        cout << (i + 1) << ". " << productNames[i] << " - $" << fixed << setprecision(2) << productPrices[i] << endl;
    }
}

void displayStatus() {
    cout << "\n===== Food Status =====\n";
    cout << left << setw(10) << "Product" << setw(10) << "Sales" << setw(10) << "Inventory" << setw(10) << "Demand" << endl;
    for (int i = 0; i < pick; i++) {
        cout << left << setw(10) << productNames[i] << setw(10) << sales[i] << setw(10) << inventory[i] << setw(10) << demand[i] << endl;
    }
    cout << endl;
}

void displayPurchases(int choice, int quantity) {
    double total = quantity * productPrices[choice];
    cout << "\n===== Purchases =====\n";
    cout << quantity << " x " << productNames[choice] << " at $" << fixed << setprecision(2)
         << productPrices[choice] << " each = $" << total << endl;
}

void displayReceipt(int customerSales[], double customerTotal) {
    cout << "\n===== Receipt =====\n";
    for (int i = 0; i < pick; i++) {
        if (customerSales[i] > 0) {
            double total = customerSales[i] * productPrices[i];
            cout << customerSales[i] << " x " << productNames[i] << " at $" << fixed << setprecision(2) << productPrices[i] << " each = $" << total << endl;
        }
    }
    cout << "Customer Total: $" << fixed << setprecision(2) << customerTotal << endl;
}
