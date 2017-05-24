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
// This class inherits from the Complex class
// Creates complex numbers and stores them
// in the container VectorParts
// ///////////////////////////////////////////////////////////

#include "Complex.h"
#include <vector>
#include <ostream>

class ComplexVector : public Complex {

 public:

  // Constructors

  /*
   * Default constructor
   */
  ComplexVector();

  /*
   * Overloaded constructor
   * Creates a vector of imaginary numbers
   * @param a, c, e, g - Real Numbers
   * @param b, d, f, h - Imaginary
   */
  ComplexVector(double a, double b, double c, double d,
                double e, double f, double g, double h);

  /*
   * Copy Constructor
   */
  ComplexVector(const ComplexVector& copy);

  /*
   * Destructor
   */
  virtual ~ComplexVector();

  /*
   * print()
   * Prints formatted ComplexVector
   */
  void print() const;

  /*
   * customize parameters for the recursive sequence function
   *
   */
  enum sequenceComponents {
    Areal_ = 2,
    Bimag_ = 3,
    Creal_ = 7,
    Dimag_ = 5,
  };

  /*
   * Recusive function that computes first 6 terms of sequence:
   *         (Areal_ + Bimag i ) n
   * fn+1 = -----------------------    * fn
   *         Creal_ + Dimag_ * n^2 i
   */
  void computeSequence(int n);

 private:

 protected:
  std::vector<Complex> VectorParts_;

  friend const ComplexVector operator+(const ComplexVector& lhs, const ComplexVector& rhs);
  friend const ComplexVector operator-(const ComplexVector& lhs, const ComplexVector& rhs);
  friend const ComplexVector operator*(const ComplexVector& lhs, const ComplexVector& rhs);
  friend const ComplexVector operator/(const ComplexVector& lhs, const ComplexVector& rhs);
  friend std::ostream& operator<<(std::ostream& os, const ComplexVector& rhs);
};




#endif
