#include <iostream>
#include <vector>
using namespace std;

// Write a function double get Average(const vector<int>&) that returns the average
double getAverage(const vector<int>& ids) { // const so it's fixed and won't modify the vector. & by reference so not to copy the entire vector.
    double sum = 0;
    for (double num: ids) { // range-based loop over each IDs
        sum += num;
    }
    return sum / ids.size();
}
   
// Write another function int getHighest(const vector<int>&) that returns the highest
int getHighest(const vector<int>& ids) {
    int highest = ids[0];
    for (int high : ids) { 
        if (high > highest) {
            highest = high;
        }
    }
    return highest;
}

int main() {
    
    // Use a vector<int> to store student IDS
    vector<int> ids;
    
    // Add 10 students IDs
    int input;
    cout << "Enter 10 John Jay Student IDs: " << endl;
    for (int i = 0; i < 10; i++) { // index-based loop
        cin >> input;
        ids.push_back(input);
    }
    
    // In main(), call both functions with your vector and print the result
    double average = getAverage(ids);
    int highest = getHighest(ids);
    
    cout << "=========John Jay Student Club Event Result=========" << endl;
    cout << "The ID average is " << average << endl;
    cout << "The highest ID is " << highest << endl;
    
    return 0;
}
