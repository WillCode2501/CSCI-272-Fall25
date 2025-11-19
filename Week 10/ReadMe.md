operator overloading

operator: + - / * == << >> <= >= !=
complex number: real and imaginary

define operator overloading by defining it before using it
allowing operator usage on objects instead of simply variables.

binary operator overloading
data members: 
  - real
  - imaginary
methods/member functions: 
  - double getReal()
  - double getImaginary()
  - complex(double re, double im)
  - complex operator i (complex other)

overloading with non-member functions 
  - non-member functions are defined outside the class
  - allow for converstions and operator without modifying the original classes
  - typically s1 + s2 is s1.operator+(s2), so operator overloading start from left to right
  - so what happens if left operand is not a class type? (ERROR!!!)
  - define operator overload as a non-member allows of symmetry so expression like 10.0 +s2 and s2 + 10.0 is the same

class Integer {
  private:
    int value;
  public:
    Integer(int val);
    int getValue() const;
    void setValue(int val);
    /// Non-member function for overloading the + operator
    friend Integer operator+(int left, const Integer& right);
    friend Integer operator-(const Integer& obj);
};
