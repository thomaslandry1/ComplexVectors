#ifndef COMPLEXVECTORS_COMPLEXVECTOR_H
#define COMPLEXVECTORS_COMPLEXVECTOR_H

// ///////////////////////////////////////////////////////////
// @class ComplexVector
// @brief Stores a complex number vector
//
// Description : This class mimics a complex number vector in
// the form:
// V(n, n+1...)
// n being complex numbers
// This class inherits from the Complex class and
// from which is creates the complex numbers and stores them
// in the container VectorParts
// ///////////////////////////////////////////////////////////

#include "Complex.h"
#include <vector>
#include <ostream>

class ComplexVector : public Complex {

 public:

  // Constructors

  ComplexVector();

  ComplexVector(Complex& num);

  /*
   * Overloaded constructor
   * Creates a vector of imaginary numbers
   * @param a, c, e, g - Real Numbers
   * @param b, d, f, h - Imaginary
   */
  ComplexVector(double a, double b, double c, double d, double e, double f,
                double g, double h);

  /*
   * Copy Constructor
   */
  ComplexVector(const ComplexVector& copy);

  virtual ~ComplexVector();

  void print() const;

  void computeSequence(int n);

 private:

 protected:
  std::vector<Complex> VectorParts_;

  friend const ComplexVector operator+(const ComplexVector& lhs, const ComplexVector& rhs);
  friend const ComplexVector operator-(const ComplexVector& lhs, const ComplexVector& rhs);
  friend const ComplexVector operator*(const ComplexVector& lhs, const ComplexVector& rhs);
  friend const ComplexVector operator/(const ComplexVector& lhs, const ComplexVector& rhs);

};




#endif