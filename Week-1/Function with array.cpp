#include <iostream>
using namespace std;

// function to calculate average
double average(int arr[], int size )  
{
	int sum = 0;
	for (int i =0; i < size; i++) {
		sum += arr[i];
	}
	return (double)sum/size; // return avearge	
}

int main() {
	int userInput = 0;
	cout << "Enter the size of an array: ";
	cin >> userInput;
	
	int scores[userInput] = {90, 85, 70, 95, 100};
	
	cout << "Average = " << average(scores, userInput) << endl;
	return 0;
}
