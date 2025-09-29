#include "Car.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
	Car car1; // default constructor
	Car car2("Tesla","X", 2022); // parametrized constructor
	Car car3(car2); //copy Constructor
	Car* pCar1 = new Car; // default constructor
	Car* pCar2 = new Car("Tesla","X", 2022); // parametrized constructor
	Car car[20]; // default constructor
	car1.startEngine();
	car2.startEngine();
	car3.startEngine();
	pCar1->startEngine();
	pCar2->startEngine();
	car[0].startEngine();
	
	return 0; 
}