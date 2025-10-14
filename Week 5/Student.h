// Student.h
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "Course.h"

using namespace std;

class Student {
	private:
		string studentName;
		vector<Course> courses; // Create a dynamic list of Course objects
	public:
		
		// Parameterized constructor
		Student(string n) {
			studentName = n;
		}	
	
		// Destructor
		~Student() {
		}

		
		// Add course informations into the course list
		void addCourse(Course c) {
			courses.push_back(c);
		}
		
		// Calculate GPA
		double GPA() const {
			int totalCredits = 0;
			double totalPoints = 0.00;
			
			for(int i=0; i < courses.size(); i++) {
				totalPoints += courses[i].getTotalPts(); // Add all the points of each courses
				totalCredits += courses[i].getCredits(); // Add all the credits of each courses
			}
			
			return totalPoints/totalCredits; // return GPA
		}
		
		// Standing
		string standing() const {
			double gpa = GPA();
			if (gpa >= 3.7)
				return "Dean's List";
			else if (gpa >= 2.0) 
				return "Good Standing";
			else 
				return "Probation";
		}
		
		void displayTranscript() const{
			cout << fixed << setprecision(2);
			cout << "=================== Student Transcript ===================" << endl;
			cout << "Student: " << studentName << endl << endl;
			cout << left << setw(25) << "Course"
				 << right << setw(10) << "Credits"
				 << right << setw(10) << "GradePts" 
				 << right << setw(10) << "TotalPts" << endl;
			cout << string(58,'-') << endl;
			
			int totalCredits=0;
			double totalPoints=0.0;
			// Loop for course information
			for (int i=0; i < courses.size(); i++) {
				cout << left << setw(25) << courses[i].getCourseName()
					 << right << setw(10) << courses[i].getCredits()
					 << right << setw(10) << courses[i].getGrade()
					 << right << setw(10) << courses[i].getTotalPts() << endl;
				totalCredits += courses[i].getCredits();
				totalPoints += courses[i].getTotalPts();
			}
			
			cout << string(58,'-') << endl;
			
			// Summary
			
			double semesterGPA = GPA();
			cout << left << setw(25) << "Total Credits: " 
				 << right << setw(10) << totalCredits << endl;
			cout << left << setw(25) << "Total Points: " 
				 << right << setw(10) << totalPoints << endl;
			cout << left << setw(25) << "Semester GPA: " 
				 << right << setw(10) << GPA() << endl;
			cout << left << setw(25) << "Standing: " 
				 << right << setw(10) << standing() << endl;			
		}
};