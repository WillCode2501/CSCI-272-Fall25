#include "Car.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
	Car car1; // create object, default constructor
	Car car2("Tesla","X", 2022); // parametrized constructor
	Car car3(car2); //copy Constructor
	
	Car* pCar1 = new Car; // pointer for default car
	Car* pCar2 = new Car("Tesla","Model Y", 2025); // pointer for parametrized car
	Car car[20]; // default constructor
	
	car1.startEngine(); // Start engine for 2025 Honda Civic
	car2.startEngine(); // Start engine for 2022 Tesla X
	car3.startEngine(); // Start engine for 2022 Tesla X
	
	pCar1->startEngine(); // Start engine for 2025 Honda Civic
	pCar2->startEngine(); // Start engine for 2025 Tesla Model Y
	
	car[0].startEngine(); // Start engine for 2025 Honda Civic
	
	return 0; 

}

