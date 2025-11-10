
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

Rule of Three (Constructors and Destructors)
- Destructor
- Copy Constructor
- Copy Assignment Operator
