// Person.h
#ifndef PERSON_H
#define PERSON_H

#include <iostream>
using namespace std;

class Person {
	protected:
		string name;
	public:
		Person (string n) : name (n) {
			cout << "Person constructor\n";
		}
		
		~Person(){
			cout << "Person destructor\n";
		}
		
		void showName() const {
			cout << "Name: " << name << endl;
	}	
};

#endif