//
// Created by Thomas Landry on 5/17/17.
//

#include "Complex.h"
#include <math.h>        // fabs used in ostream operator
#include <iostream>
#include <iomanip>

using std::setw;
using std::cout;
const int PRECISION = 1;
const int width = 5;

Complex::Complex(double a, double b) : Real_(a), Imag_(b) {
}

Complex::~Complex() {
}

Complex::Complex(const Complex& copy)
    : Real_(copy.Real_), Imag_(copy.Imag_) {
}

std::ostream& operator<<(std::ostream& os, const Complex& rhs) {
  cout.setf(std::ios::fixed);
  cout.precision(PRECISION);

  os << setw(width) << rhs.Real_;

  //checks to see if number is positive or neg

  if (rhs.Imag_ > 0) {
    os << " + ";
  } else {
    os << " - ";
  }

  // outputs imaginary part along with unit -> "14i"
  os << setw(width) << fabs(rhs.Imag_) << rhs.ImaginaryUnit_;

  return os;
}

const Complex operator+(const Complex& lhs, const Complex& rhs) {
  return Complex(lhs.Real_ + rhs.Real_,
                 lhs.Imag_ + rhs.Imag_);
}

const Complex operator-(const Complex& lhs, const Complex& rhs) {
  return Complex(lhs.Real_ - rhs.Real_,
                 lhs.Imag_ - rhs.Imag_);
}

const Complex operator*(const Complex& lhs, const Complex& rhs) {
  double ac = lhs.Real_ * rhs.Real_;
  double bd = lhs.Imag_ * rhs.Imag_;
  double bc = lhs.Imag_ * rhs.Real_;
  double ad = lhs.Real_ * rhs.Imag_;

  return Complex ( (ac-bd), (bc+ad));
}

const Complex operator/(const Complex& lhs, const Complex& rhs) {
  double ac = lhs.Real_ * rhs.Real_;
  double bd = lhs.Imag_ * rhs.Imag_;
  double bc = lhs.Imag_ * rhs.Real_;
  double ad = lhs.Real_ * rhs.Imag_;
  double c2 = rhs.Real_ * rhs.Real_;
  double d2 = rhs.Imag_ * rhs.Imag_;

  return Complex((ac+bd)/(c2+d2), (bc-ad)/(c2+d2));
}


