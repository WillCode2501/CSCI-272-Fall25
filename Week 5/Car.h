// Destructor

#include <iostream>
#include <string>

using namespace std;

class Car {
	private:
		string brand = "Toyota";
		string model = "Camry";
		int year = 2022;
	public:
		
		// default constructor
		Car(){ 
		
		}
		
		//Destructor
		~Car() { 
		 cout << "Destoryed ";
		}
		
		// Parameterized constructor
		Car(string b, string m, int y) { 
			brand = b; 
			model = m; 
			year = y;
		}
		
		// Copy constructor
		Car(const Car& other){
			brand = other.brand;
			model = other.model;
			year = other.year + 1;
			
			
		// Member Function
		}
		void startEngine() {
			cout << "Start engine for " 
			<< "Brand: " << brand 
			<< " | Model: " << model 
			<< " | Year: " << year << endl;
		}
		
		// Member Function
		void accelerate() {
			cout << "Accelerate engine "
			<< "Brand: " << brand 
			<< " | Model: " << model 
			<< " | Year: " << year << endl;
		}
};
