// Course.h
#include <string>

using namespace std;

class Course {
	private: 
		string courseName;
		int credits;
		string letter;
		double gradePts;
	public:
		// Parameterized Constructor
		Course(string n, int c, string l) {
			courseName = n;
			credits = c;
			letter = l;
			
			// Convert letter to grade
			if (l == "A") gradePts = 4.0;
        	else if (l == "A-") gradePts = 3.7;
        	else if (l == "B+") gradePts = 3.3;
        	else if (l == "B") gradePts = 3.0;
        	else if (l == "B-") gradePts = 2.7;
        	else if (l == "C+") gradePts = 2.3;
        	else if (l == "C") gradePts = 2.0;
        	else if (l == "C-") gradePts = 1.7;
        	else if (l == "D+") gradePts = 1.3;
        	else if (l == "D") gradePts = 1.0;
        	else if (l == "D-") gradePts = 0.7;
        	else gradePts = 0.0;
		}
		
		// Parameterized Destructor
		~Course() {
		}	
		

		// const getters, basically used to read private variables
		string getCourseName() const {
			return courseName;
		}
		int getCredits() const {
			return credits;
		}
		string getLetter() const {
			return letter;
		}
		double getGrade() const {
			return gradePts;
		}
		double getTotalPts() const {
			return credits*gradePts;
		}
};