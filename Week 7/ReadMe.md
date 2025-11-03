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

when created a file like ofstream outClientFile("clients.txt", ios::out), can't use it again or else it replace the old one
can add to the existing file using ios::app to eppend to the end of file, like ofstream outClientFile("clients.txt", ios::app);
