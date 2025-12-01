// Student.h
#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"

class Student : public Person {
	private:
		int studentID;
	public:
		Student(string n, int id) : Person(n), studentID(id) {
			cout << "Student constructor\n";
		}
		
		~Student() {
			cout << "Student destructor\n";
		}
		
		void showInfo() const {
			showName();
			cout << "ID: " << studentID << endl;
		}
};

#endif