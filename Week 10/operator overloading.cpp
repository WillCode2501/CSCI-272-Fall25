//// Unary overloading operator
//#include <iostream>
//
//using namespace std;
//
//// .h file
//
//class MyNumber {
//	private:
//		int value; // Internal storing int
//	public:
//		// constructor
//		MyNumber(int val = 0) {
//			value = val;
//		}
//		
//		// getter to read the stored value
//		int getValue() const {
//			return value;
//		}
//		
//		// overload the minus operator: -num
//		// this will not change the original object
//		MyNumber operator-() const {
//			return MyNumber(-value);
//		}
//		
//		// overload the prefix ++: ++num
//		// this will change the current object (increments value)
//		MyNumber operator++() {
//			++value; // increase the stored value by 1
//			return MyNumber(value);
//		}
//
//};
//
//// main.cpp
//int main() {
//	MyNumber num(10);
//	cout << "Original Value: " << num.getValue() << endl;
//	// Original Value: 10
//	
//	// using the overloading minus operator
//	MyNumber negative = -num; // call the MyNumber::operator-()
//	cout << "After applying -num: " << negative.getValue() << endl;
//	// After applying -num: -10
//	
//	// use overloaded prefix ++ operator
//	MyNumber incremented = ++num;
//	cout << "After applying ++num: " << num.getValue() << endl;
//	// After applying ++num: 11
//	
//	// checking the original value
//	cout << "Value returned by the ++num: " << incremented.getValue() << endl; 
//	// Value returned by the ++num: 11
//}



// Binary overloading operator
#include <iostream>
using namespace std;

class Integer{
	private:
		int value; // data member
	public:
		// constructor
		Integer(int val = 0) {
			value = val;
		}
		
		// getter to read the stored value
		int getValue() const {
			return value;
		}
		
		// overloading the binary + operator to add two integer objects
		// ex. Integer c = a + b
		Integer operator+(const Integer& other) const {
			return Integer(this->value + other.value);
		}
};

int main() {
	Integer num1(19);
	Integer num2(20);
	// Call num1.operator+(num2)
	// need Intger operator+ overloading
	Integer sum = num1 + num2;
	cout << "The sum of " << num1.getValue() << " and " << num2.getValue() << " is " << sum.getValue() << endl;
	// The sum of 19 and 20 is 39
}