#include <iostream> // Include the necessary library for input/output operations.
#include <vector> // Include the necessary library for vector.

using namespace std;

int main() {
	
	// Vector initialization
	vector<double> prices = {1,2,3,4,5};
	
	// add values to the end of the 'Prices' vector
	prices.push_back(10);
	prices.push_back(50);
	prices.push_back(11);
	// array would be {1,2,3,4,5,10,50,11} total of 8 elements now
	
	// accessing and modifying
	double total = prices[0] + prices [1] + prices [2]; // 1+2+3 = 6
	
	cout << "Total = $" << total << endl;
	
	// vector does not have direct function to add to the front
	// this is a dynamic array and adding to the end is more efficient
	// to add to the front, you will use insert function and then find the 
	// beginning of the vector and then add the value
	prices.insert(prices.begin(), 20); // insert 20 at the beginning of the vector
	
	cout << "First item: " << prices.front() << endl; // 20
	cout << "Last item: " << prices.back() << endl; // 11
	cout << "Total size of my vector (prices): " << prices.size() << endl; // 9
	
	// accessing and modifying
	double total2 = prices[0] + prices[1] + prices[2]; // 20+1+2 = 23
	cout << "Total = $" << total2 << endl; 
	
	return 0;
}