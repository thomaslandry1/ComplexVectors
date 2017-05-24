#ifndef COMPLEXVECTORS_COMPLEX_H
#define COMPLEXVECTORS_COMPLEX_H

// ///////////////////////////////////////////////////////////
// @class Complex
// @brief Stores a complex number
//
// Description : This class mimics the arithemtic of rational
// of imaginary numbers in the form of a + bi
// a = real number
// b = imaginary number
// i = imaginary unit satisfying i^2 = -1
//
// ///////////////////////////////////////////////////////////

#include <string>
#include <ostream>

class Complex {

 public:
 //constructors

  /*
   * Overload constructor
   * constructs complex number in the format (a + bi)
   * @param a - real component (defaulted to 1.0)
   * @param b - imaginary component (1.0 if not provided)
   */
  explicit Complex(double a = 1.0, double b = 1.0);

  //Copy constructor
  Complex(const Complex& copy);

  //Destructor
  virtual ~Complex();

 protected:
  double Real_;
  double Imag_;
  const std::string ImaginaryUnit_ = "i";

  //overloaded operators

  /*
   * ostream operator for Complex numbers
   * overloads output stream for Complex in the format << a + bi
   */
  friend std::ostream& operator<<(std::ostream& os, const Complex& rhs);

  /*
   * overloads + operator to add 2 complex numbers
   */
  friend const Complex operator+(const Complex& lhs, const Complex& rhs);

  /*
   * overloads - operator to substract 2 complex numbers
   */
  friend const Complex operator-(const Complex& lhs, const Complex& rhs);

  /*
   * overloads * operator to multiply 2 complex numbers
   */
  friend const Complex operator*(const Complex& lhs, const Complex& rhs);

  /*
   * overloads / operator to divide 2 complex numbers
   */
  friend const Complex operator/(const Complex& lhs, const Complex& rhs);


};

#endif
