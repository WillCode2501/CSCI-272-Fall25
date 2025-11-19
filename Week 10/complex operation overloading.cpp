// .h file
#include <iostream>
using namespace std;

class Complex {
	private:
		double real;
		double imaginary;
	public:
		// Constructor
		Complex(double re = 0.0, double im = 0.0)
			: real(re), imaginary(im) {} // real = re; imaginary = im
			
		// getter for real and imaginary part
		double getReal() const {
			return real;
		}
		double getImaginary() const {
			return imaginary;
		}
		
		// ab = a*b
		// overloading the - operator to subtract two complex numbers:
		// (a1 + b1 i) - (a2 + b2 i) = (a1 - a2) + (b1 - b2) i
		Complex operator-(const Complex& other) const {
			double newReal = this -> real - other.real;
			double newImag = this -> imaginary - other.imaginary;
			return Complex (newReal, newImag);
		}
};

// .cpp file
#include <iostream>
#include "Complex.h"
using namespace std;

int main() {
	Complex num1(12.0, 3.1);
	Complex num2(7.77, 36.2);
	
	// calls num1.operator-(num2)
	Complex difference = num1 - num2;
	
	cout << "num1 = " << num1.getReal() << " + " 
		<< num1.getImaginary() << "i" << endl;
	cout << "num2 = " << num2.getReal() << " + " 
		<< num2.getImaginary() << "i" << endl;
	cout << "num1 - num2 = " << difference.getReal() << " + " 
		<< difference.getImaginary() << "i" << endl;
	
	return 0;
}