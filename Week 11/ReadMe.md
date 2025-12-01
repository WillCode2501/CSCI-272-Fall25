Inheritance

New class can be created based on existing classes
New class can be modified, add new functions, and etc after inherited from parent class

Base class = parent class
Derived class = child class

Student -> GraduateStudent, UndergraduateStudent

#include "Animal.h"
class Dog : public Animal{
public:
  void bark();
);

Inheritance: The process by which a class inheirts properties and behaviors from another class.
Hierarchy: The organization of classes into a tree-like structor, representing relationship between base and derived classes.

Type of Inheritance:
  Single Inheritance: from one parent
  Multiple Inheritance: from more than one parents
  Multilevel Inheritance: from parent but the parent also inherited from grandparent, so child get parent and grandparent
  Hierarchical Inheritance: multiple child inherit from a single parent
  Hybrid Inheritance: a combination of different types of inheritance
