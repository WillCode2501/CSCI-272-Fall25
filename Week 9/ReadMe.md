
Classes: header (.h) and implementation files (.cpp) 
  header for interface and implementation file for actual code

header:
  declare class: data members and function
  prototype for header file
  ex. class MyClass { 
      private:
        int my Variable;
      public:
        MyClass();
        void myFunction():
      }  

implementation file:
  #include "header.h" 
  implement the function
  ex.   #include "MyClass.h"
        MyClass::MyClass() {
          myVariable = 0;
        }
        void MyClass::myFunction() {
          myVariable++;
        }

When using constructor, also use destructor to deallocate memory used by data members (free the memory)



class DynamicArray {
private:
  int* arr; // Pointer to dynamic integer array
  int size; // Size of the array
public:
  // Constructor to initialize the dynamic array
  DynamicArray(int n);
  // Destructor to release dynamic memory
  ~DynamicArray();
  // Function to display the array elements
  void display();
};



#include "DynamicArray.h"
#include <iostream>
DynamicArray::DynamicArray(int n) {// Constructor implementation
  size = n;
  arr = new int[size];
}
DynamicArray::~DynamicArray() {// Destructor implementation
  delete[] arr; // Deallocate the memory pointed to by arr
}
void DynamicArray::display() {// Function to display the array elements
  for (int i = 0; i < size; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

Rule of Three (Constructors and Destructors) is guideline to deal with resource management for classes
- Destructor
    ~Car()
- Copy Constructor
    Car2(Car1)
- Copy Assignment Operator
    Car2 = Car1

  
// Copy constructor implementation
DynamicArray::DynamicArray(const DynamicArray& other) {
  size = other.size;
  arr = new int[size];
  for (int i = 0; i < size; i++) {
    arr[i] = other.arr[i];
  }
}

// Copy assignment operator implementation
DynamicArray& DynamicArray::operator=(const DynamicArray& other) {
  if (this != &other) {
  // Deallocate the current dynamic memory
    delete[] arr;
    size = other.size;
    arr = new int[size];
    for (int i = 0; i < size; i++) {
      arr[i] = other.arr[i];
    }
  }
  return *this;
}



Rule of Five (C++11 and Later) To prevent memory leak and double deletion
- 3 from Rule of Three
- Move Constructor
    Create a new constructor by taking data from old constructor
- Move assignment operator
    Move ownership along with the assignment to them, only the assigned has ownership



rvalue reference: &&
reference temporary while & reference permanent 
Move constructor provided an efficient way to transfer these resources without unnecessary duplication
  - Move the constructor to new place and use it, while releasing the old place.
    
  MyObject target = std::move(source); // Transfer resources to target using the move constructor.

// Move Constructor
DynamicArray::DynamicArray(DynamicArray&& other){
  size = other.size;
  arr = other.arr;

  // releasing the previous object
  other.size = 0;
  other.arr = nullptr;
}


Move assignment operator: when a function returns an object by value, move assignment can be
used to avoid creating temporary object.
  - Assigning someone to move the object, e.g. Having a moving company move everything 

  MyObject target; // Create the target object.
  target = std::move(source); // Transfer resources to target using the move assignment operator.

// Move Assignment Operator
DynamicArray& DynamicArray::operator=(DynamicArray&& other) {
  if (this == &other) {
    return *this; // Self-assignment, no action needed
  }
  
  delete[] arr;
  size = other.size;
  arr = other.arr;
  other.size = 0;
  other.arr = nullptr;
  
  return *this;
}


CONSTRUCTOR AND DESTRUCTOR rule of 5 examples:

#include "DynamicArray.h"
#include <utility> //to access the std::move function
int main() {
  DynamicArray myArray(5); // Create an array of size 5
  
  DynamicArray arr2 = myArray; // Copy Constructor (Rule of Five)
  
  DynamicArray arr3(3); // Create an array of size 3
  arr3 = myArray; // Copy Assignment Operator (Rule of Five)
  
  DynamicArray arr4 = std::move(myArray); // Move Constructor (Rule of Five)
    // MyArray moved to arr4, so myArray is empty
    
  DynamicArray arr5(4); // Create an array of size 4
  arr5 = std::move(arr2); // Move Assignment Operator (Rule of Five)
    // arr5 is assigned arr2 so arr5 would have the same data as arr2, arr2 now becomes empty
  
  // When myArray goes out of scope, its destructor is automatically called,
  // which releases the dynamically allocated memory.
  // This prevents memory leaks.
  
  return 0;
}



Creating Complex Object:
  - Combining simpler objects
  - Use objects from other classes to build the class
  - Example: "Date" class inside "Person" class.

#include <iostream>
#include "Date.h"

class Person {
private:
  std::string name; // composition: member object
  // Declare object Date from Date class
  Date birthdate; // composition: member object
public:
  Person();
  Person(std::string name, Date birthdate);
  std::string getName();
  Date getBirthdate();
  void display();
};


Dot vs Arrow
  - using the dot to acess the member from an object
  - e.g. myobject.memberFunction()
  - using tehe arrow to access the object's member
  - e.g. ptr->memberFunction()

"this"
  - 'this' pointer is a pointer to the current object
  - provides a way to access an object's members within the class

Solving Name Conflict
  - 'this' helps resolve problem when parameter shares the same name as a member variable

#ifndef MYCLASS_H
#define MYCLASS_H
class MyClass {
private:
  int x;
public:
  MyClass(int x);
  void printX();
};

#endif
#include "MyClass.h"
#include <iostream>
MyClass::MyClass(int x) {
  this->x = x; // 'this' is used to access the member variable.
}
void MyClass::printX() {
  std::cout << "Value of x: " << x << std::endl;
}




Friendship in C++
  - friend allows to access private and protected members
  - special access to another class for operations like data manipulation or I/O
#include <iostream>
class MyClass {
private:
  int secretValue;
public:
  MyClass(int val){
    secretValue = val;
  }
  void displaySecretValue(){
    std::cout<< "Secret Value: "<< secretValue<<std::endl;
  }
  friend class FriendClass; // Declaration of the friend class
};

Pro and Cons of Friends
  Pro
  - Improve encapsulation by keeping related functionality together
  - flexibility
  - avoid complex workaround
  Cons
  - can break encapsulation
  - tie the code closely together, make it more difficult to maintain (data leak)
  - Should only be used only when needed
