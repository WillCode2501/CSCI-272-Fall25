#include <iostream>
#include <string>
using namespace std;

class Car {
	private:
		string brand{"Honda"};
		string model="Civic";
		int year {2025};
	public:
		Car(){ // default constructor
		}
		Car(string b, string m, int y) { // Parameterized Constructor
		brand =b; 
		model = m; 
		year = y;
		}

		Car(const Car& other){
			brand = other.brand;
			model = other.model;
			year = other.year;
		}
		
		void startEngine() {
			cout << "Start engine for " << year << " " << brand << " " << model << endl;
		}
		void accelerate() {
			cout << "Accelerate car " << model << endl;
		}
};
