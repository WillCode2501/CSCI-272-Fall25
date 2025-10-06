#include "Car.h"
#include <iostream>

using namespace std;

int main() {
	// Create a car object
	Car car1; // default constructor
	
	// parametrized constructor
	Car car2("Honda", "Civic", 2024); 
	
	//copy Constructor
	Car car3(car2); 
	
	// Copy 2
	Car car4(car3);
	
	// Call member function
	car1.startEngine();
	car2.startEngine();
	car3.startEngine();
	car4.startEngine();
	
	car2.accelerate();
	car3.accelerate();
	
	// destructor is going to be called automatically
	return 0; 
}

// Output Result
//Start engine for Brand: Toyota | Model: Camry | Year: 2022
//Start engine for Brand: Honda | Model: Civic | Year: 2024
//Start engine for Brand: Honda | Model: Civic | Year: 2025
//Start engine for Brand: Honda | Model: Civic | Year: 2026
//Accelerate engine Brand: Honda | Model: Civic | Year: 2024
//Accelerate engine Brand: Honda | Model: Civic | Year: 2025
//Destoryed Destoryed Destoryed Destoryed

// Destructor is a stack, last in first out
// Destory the constructor, clean the mess and release memories after it is done.
