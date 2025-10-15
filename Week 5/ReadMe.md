What is Streams?
- It's the input and output of transferring bytes to memories and out of memories
<iostream> includes cout, cin, cerr, and clog
- cerr is unbuffer (immediately and shows the error) clog is buffer (delayed and show the log)

<iomanip> setw(int n), setprecision(int n), left, right, setfill

examples: 

cout << setw(10) << setfill('-') << "Coffee" << endl;

----Coffee

cout << setw(10) << setfill('-') << "Menu" << endl << setw(10) << left << "Coffee" << setw(10) << right << "Total" << endl;

------Menu

Coffee         Total

cout << fixed << setprecision(3) << 3.312421;    

3.312

cin.get();   input of the first character

cin.getline(); get the entire string

getline(cin, name);  get the entire input string and store it in name

typedef Card* CardPtr; // CardPtr is an alias of Card* 

typedef double DB; // DB is an alias of double

typedef int ROY; // Roy is an alias of int



Course.h, Student.h, and Transcript.cpp is an assignment for creating student transcript
