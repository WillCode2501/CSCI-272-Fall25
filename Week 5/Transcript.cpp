#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "Student.h" // includes "Course.h"

using namespace std;

int main() {
	
	// Student Name
	string name;
	cout << "Enter student name: ";
	getline(cin, name);
	
	// create Student objects with names
	Student student(name);
	
	// How many courses taken
	int numCourses;
	do {
		cout << "Enter the number of courses (1-10): ";
		cin >> numCourses;
		if (cin.fail() || numCourses < 1 || numCourses > 10) {
			cin. clear(); 
			cin.ignore(1000, '\n'); 
		}
	} while (numCourses < 1 || numCourses > 10);
	
	// Get course information
	for (int i=0; i < numCourses; i++) {
		string cname, letter;
		int ccredits;
		cin.ignore(1000, '\n'); // had to have it here because it keep skipping cname
		
		cout << "Enter course " << i+1 << " name: ";
		getline(cin, cname); 
		
		// Credits earn per course
		do {
			cout << "Enter the credit for course " << i+1 << ": ";
			cin >> ccredits;
			if (cin.fail() || ccredits < 1 || ccredits > 10) {
			cin. clear(); // Reset fail state
			cin.ignore(1000, '\n'); // Discard up to 1000 characters or until new line
			}
		} while (ccredits < 1 || ccredits > 10);
		
		// Get letter grade, nothing else 
		do {
			cout << "Enter letter grade earned (A, A-, B+, B, B-, C+, C, C-, D+, D, D-, F): ";
			cin >> letter;
			if (letter != "A" && letter != "A-" && letter != "B+" && letter != "B" && 
			letter != "B-" && letter != "C+" && letter != "C" && letter != "C-" && 
			letter != "D+" && letter != "D" && letter != "D-" && letter != "F")
			cout << "Enter a valid grade";
			else break;
		} while (letter != "A" && letter != "A-" && letter != "B+" && letter != "B" && 
			letter != "B-" && letter != "C+" && letter != "C" && letter != "C-" && 
			letter != "D+" && letter != "D" && letter != "D-" && letter != "F");
			
		
		// Create Course Object for Student
		Course c(cname, ccredits, letter); 
		student.addCourse(c);
	}
	
	cout << endl;
	
	// Display Transcript
	student.displayTranscript();
	
	return 0;
}
