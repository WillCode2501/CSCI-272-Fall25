// Library.cpp
#include "Library.h"
#include <limits>
#include <sstream>

// check correct date format
bool isValidDateFormat(const string& date) {
    istringstream iss(date);
    int year, month, day;
    char dash1, dash2;

    if (iss >> year >> dash1 >> month >> dash2 >> day) {
        if (dash1 == '-' && dash2 == '-' &&
            year >= 1900 && year <= 2100 &&
            month >= 1 && month <= 12 &&
            day >= 1 && day <= 31) {
            return true;
        }
    }
    return false;
}
template <typename T>
void InputValidation(T& input) { 
while (true) {
cin>> input;
if (cin.fail()) {
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');
cout <<"Invalid input, try again!"<<endl;
} else 
break; }
}

Library::Library() {
loggedInMember = nullptr;
    loadData();
}

void Library::loadData() {
books = BookInfo::loadFromFile("bookinfo.txt");
    members = MemberAccount::loadFromFile("members.txt");    
transactions = Transaction::loadFromFile("transactions.txt");
}

void Library::saveData() {  
BookInfo::saveToFile(books,"bookinfo.txt");
  MemberAccount::saveToFile(members,"members.txt");
Transaction::saveToFile(transactions,"transactions.txt");}

bool Library::login() {
string username,   password;
cout<<"\n=== Login ===\n";
cout<<"Username: ";
cin>>username;
cout<<"Password: "; cin>>password;

for (MemberAccount* member: members) {
if (member->login(username,password)) {
loggedInMember= member;
cout<<"\nWelcome, "<< loggedInMember->getName()<<"!\n";
return true; }
}
cout<<"\nLogin failed! Invalid username or password.\n";
return false;
}

void Library::logout() {
if (loggedInMember != nullptr){
cout<<"Goodbye, "<<loggedInMember->getName()<<"!\n";
loggedInMember=nullptr;
}}

bool Library::isLoggedIn() const {
return loggedInMember!=nullptr;
}

bool Library::isStaff() const {
return loggedInMember!=nullptr && loggedInMember->isStaff();}

void Library::AddBook() {
if(!isStaff()) {
cout<<"\n[Access denied - Staff only]\n";
    return; }

string title,author,isbn, genre;
      int copies;

while(true) {
cin.ignore();
cout<<"\n=== Add New Book ===\n";
cout<<"Title: "; getline(cin,title);
cout<<"Author: "; getline(cin,author);
cout<<"ISBN: ";getline(cin,isbn);
cout<<"Genre:"; getline(cin,genre);
cout<<"Number of copies: ";
InputValidation(copies);
if(copies <=0) {
cout<<"Invalid number of copies, try again ";
} else break;
}

BookInfo newBook(title,author,isbn,genre,copies);
books.push_back(newBook);
saveData();
cout<<"\nBook added successfully!\n";
}

void Library::RemoveBook(){
if(!isStaff()){
cout<<"\n[Access denied - Staff only]\n";
return; }

string isbn ;
cout<<"\n=== Remove Book ===\n";
cout<<"Enter ISBN of book to remove: ";
cin>>isbn;

for (auto it = books.begin(); it!= books.end(); ++it) {
if (it->getIsbn()==isbn){
cout<<"Removing: "<< it->getTitle()<<endl;
books.erase(it);
saveData();
cout<<"Book removed successfully!\n";
return;
}}
cout<<"Book not found.\n";
}

void Library::ViewBook() {
cout<<"\n=== Book Catalog ===\n";
cout<<setw(25)<<left<<"Title"<<setw(20)<<left<<"Author"
<<setw(15)<<left<<"ISBN"<<setw(12)<<left<<"Genre"<<setw(10)<<left<<"Available"<<endl;
cout<< string(82,'-')<< endl;

for(const BookInfo& book: books) {
book.display();
}
cout<<"\nTotal books: "<<books.size()<<endl;
}

string Library::generateMemberID() {
int maxID=0;
for(const MemberAccount* m: members){
string id = m->getMemberID();
if(id[0]=='M') {
int num = stoi(id.substr(1));
maxID = max(maxID,num);
}}
int next = maxID +1;
return "M" + string(3- to_string(next).length(), '0') + to_string(next);
}

void Library::AddMember() {
if(!isStaff()) {
cout<<"\n[Access denied - Staff only]\n";
return; }

string username,password,name,email,memberID,role;

cin.ignore();
cout<<"\n=== Add New Member ===\n";
cout<<"Username: "; getline(cin,username);
cout<<"Password: "; getline(cin,password);
cout<<"Full Name: ";getline(cin,name);
cout<<"Email: "; getline(cin,email);
memberID = generateMemberID();
cout<<"Assigned Member ID: "<< memberID <<endl;

while(true){
cout<<"Role (staff/user): ";
getline(cin,role);
if(role=="staff" || role=="user") break;
cout<<"Invalid role. Please enter 'staff' or 'user'\n";
}

if(role=="staff") {
members.push_back(new StaffAccount(username,password,name,email,memberID,"staff"));
} else {
members.push_back(new UserAccount(username,password,name,email,memberID,"user"));
}

saveData();
cout<<"\nMember added successfully!\n";
}

void Library::RemoveMember() {
if(!isStaff()){
cout<<"\n[Access denied - Staff only]\n";
return; }

string memberID;
cout<<"\n=== Remove Member ===\n";
cout<<"Enter Member ID to remove: ";
cin>>memberID;

for(auto it = members.begin(); it!= members.end(); ++it){
MemberAccount* acc = *it;
if(acc->getMemberID()==memberID){
cout<<"Removing: "<<acc->getName()<<endl;
delete acc;
members.erase(it);
saveData();
cout<<"Member removed successfully!\n";
return;
}}
cout<<"Member not found.\n";
}

void Library::viewAccount() {
if(!isStaff()) {
cout<<"\n[Access denied - Staff only]\n"; return; }

cout<<"\n=== Member Accounts ===\n";
cout<<setw(15)<<left<<"Username"<<setw(20)<<left<<"Name"<<setw(25)<<left<<"Email"
<<setw(10)<<left<<"Member ID"<<setw(10)<<left<<"Role"<<endl;
cout<<string(80,'-')<<endl;

for(const MemberAccount* member: members){
member->display();
}
cout<<"\nTotal members: "<< members.size()<<endl;
}

void Library::ViewTransaction(){
if(!isStaff()){
cout<<"\n[Access denied - Staff only]\n"; return; }

cout<<"\n=== Transaction Log ===\n";
cout<<setw(25)<<left<<"Book Title"<<setw(15)<<left<<"Member"
<<setw(12)<<left<<"Loan Date"<<setw(12)<<left<<"Due Date"
<<setw(12)<<left<<"Return Date"<<setw(12)<<left<<"Status"<<endl;

cout<< string(88,'-')<< endl;

for(const Transaction& t: transactions){
t.display();
}
cout<<"\nTotal transactions: "<<transactions.size()<<endl;
}

void Library::CheckoutBook(){
    if(!isLoggedIn()) {
        cout << "\n[Please login first]\n";
        return;
    }

    string isbn;
    cout << "\n=== Checkout Book ===\n";
    cout << "Enter ISBN of book to checkout: ";
    cin >> isbn;

    for (BookInfo& book : books) {
        if (book.getIsbn() == isbn) {
            if (book.checkOut()) {
                string loanDate;
                string dueDate;

                cin.ignore();  // clear leftover newline

                // loan date
                do {
                    cout << "Enter loan date (YYYY-MM-DD): ";
                    getline(cin, loanDate);
                    if (!isValidDateFormat(loanDate)) {
                        cout << "Invalid date format, try again.\n";
                    }
                } while (!isValidDateFormat(loanDate));

                // due date
                do {
                    cout << "Enter due date (YYYY-MM-DD): ";
                    getline(cin, dueDate);
                    if (!isValidDateFormat(dueDate)) {
                        cout << "Invalid date format, try again.\n";
                    }
                } while (!isValidDateFormat(dueDate));

                Transaction newLoan(book.getTitle(),
                                    loggedInMember->getUsername(),
                                    loanDate,
                                    dueDate);
                transactions.push_back(newLoan);
                saveData();
                cout << "Book checked out successfully!\n";
            } else {
                cout << "Sorry, no copies available.\n";
            }
            return;
        }
    }

    cout << "Book not found.\n";
}

void Library::ReturnBook(){
    if(!isLoggedIn()){
        cout<<"\n[Please login first]\n"; 
        return; 
    }

    string isbn;
    cout<<"\n=== Return Book ===\n";
    cout<<"Enter ISBN of book to return: ";
    cin>>isbn;
    cin.ignore();

    bool bookfound = false;

    for(BookInfo& book: books){
        if(book.getIsbn()==isbn){
            bookfound=true;

            bool openloan=false;
            string currentUser = loggedInMember->getUsername();

            for(Transaction& t: transactions){
                if(t.getBookTitle()==book.getTitle() &&
                   t.getMember()== currentUser &&
                   t.getStatus()=="checked out"){

                    book.returnBook();
                    string returnDate;

                    do {
                    	cout << "Enter return date (YYYY-MM-DD): ";
                    	getline(cin, returnDate);
                    	if (!isValidDateFormat(returnDate)) {
                        	cout << "Invalid date format, try again.\n";
                    	}
                	} while (!isValidDateFormat(returnDate));

                    t.setReturnDate(returnDate);
                    t.setStatus("returned");
                    saveData();
                    cout<<"Book returned successfully!"<<endl;
                    openloan=true;
                    return;
                }
            }

            if(!openloan) cout<<"You do not have this book checked out."<<endl;
            return;
        }
    }
    if(!bookfound) cout<<"Book not found.\n";
}




