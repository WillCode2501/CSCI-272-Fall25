Notes for week 8 Stream-Files

sstream: istringstream, ostringstream, stringstream, they write and read data from memory
Once the program is close, the memory disappeared, how do we save the data?

Solution: using fstream, create a file to write and read data from saved file in secondary storage devices such as hard disks,
CDs, DVDs, flash drives and tapes.

Bytes are saved starting from 0 (like array and vector), end of file marker = n - 1 for n = total bytes.

Header : <iostream> and <fstream> 
<fstream> : 
  basic_ifstream - file input 
  basic_ofstream - file output
  basic_fstream - file input and output
alias in code: ifstream, ofstream, fstream

File are saved in the same directory as the program as default
create file example:
  ofstream outClientFile("clients.txt", ios::out);
  
exit() from #include <cstdlib>
thing to use: cerr and exit();
Check if file exist, some cases: file notexistent, file not in directory available, no space left in disk
example:
	if (!outClientFile) { 
		cerr << "File could not be opened" << endl;
		exit(EXIT_FAILURE); // Terminate the program with a failure status
	}	

make sure to close the file using.close()
example: 
  outClientFile.close();

when created a file like ofstream outClientFile("clients.txt", ios::out), can't use it again or else it replace the old one,
can add to the existing file using ios::app to eppend to the end of file, like ofstream outClientFile("clients.txt", ios::app);

ifstream: input file, allow to read data from file
ofstream: how to create a file

use ios::in for reading data from file without modifying what's inside

we can use seekg to read or seekp to write bytes into file into specific index in the file
example:
	inClientFile.seekg(0, ios::beg); // means read from the beginning

	position to the nth byte of fileObject (assumes ios::beg)
	inClientFile.seekg(n);
	
	// position n bytes in fileObject
	inClientFile.seekg(n, ios::cur);
	
	// position n bytes back from end of fileObject
	inClientFile.seekg(n, ios::end);
	
	// position at end of fileObject
	inClientFile.seekg(0, ios::end);








