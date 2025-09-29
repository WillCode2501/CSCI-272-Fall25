#include <iostream>
#include <string>
using namespace std;

class Person{
	public:
		string name {"John Doe"};
		int age {30};
		char gender {'M'};
		
	public:
		void introduce() {
			cout << "I'm " << name << ". Age: " << age; 
			if (gender == 'M') {
				cout << " I identify as a male" << endl;
			} else if (gender == 'F') {
				cout << " I identify as a female" << endl;
			} else {
				cout << " Gender not specified.";
			}
		}
};