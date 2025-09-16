#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Create a vector<string> called menu
    vector<string> menu;
    
    // Add 5 dishes using push_back
    menu.push_back("Chicken Sandwich");
    menu.push_back("Egg Sandwich");
    menu.push_back("Pork Sandwich");
    menu.push_back("Beef Sandwich");
    menu.push_back("Turkey Sandwich");
    // Order would be Chicken, Egg, Pork, Beef, Turkey
    
    // Insert a new dish at the 2nd position
    menu.insert(menu.begin() + 1, "Vegan Sandwich");
    // Order would be Chicken, Vegan, Egg, Pork, Beef, Turkey
    
    // Remove the 4th dish using .erase()
    menu.erase(menu.begin() + 3); 
    // Order would be Chicken, Vegan, Egg, Beef, Turkey
    
    // Print the final menu using a range-based for loop
    cout << "=========John Jay Cafeteria Menu=========" << endl;
    for (const string& item: menu) {
        cout << item << endl;
    }
    
    return 0;
}