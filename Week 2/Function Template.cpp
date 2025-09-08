// Function Template
#include <iostream>

using namespace std;

// To find the maximum of two values of any type
template <typename T>
T maxNum(T a, T b) {
	return (a > b) ? a : b;
}

int main () {
	int intMax = maxNum(5, 10); // we're using INTEGER and calling maxNum()
	double doubleMax = maxNum(2.5, 11.6); // using DOUBLE and calling maxNum()

	cout << "Integer Max: " << intMax << endl;
	cout << "Double Max: " << doubleMax << endl;
}