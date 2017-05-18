//
// Created by Thomas Landry on 5/17/17.
//

#include "Complex.h"
#include <math.h>
#include <iostream>
#include <iomanip>

using std::setw;
const int width = 5;

Complex::Complex(double a, double b) : RealPart_(a), ImaginaryPart_(b) {
}

Complex::~Complex() {
}

Complex::Complex(const Complex& copy)
    : RealPart_(copy.RealPart_), ImaginaryPart_(copy.ImaginaryPart_) {
}

std::ostream& operator<<(std::ostream& os, const Complex& rhs) {
  os << setw(width) << rhs.RealPart_;
  if (rhs.ImaginaryPart_ > 0) {
    os << " + ";
  } else {
    os << " - ";
  }
  os << setw(width) << fabs(rhs.ImaginaryPart_) << rhs.ImaginaryUnit_;
  return os;
}

const Complex operator+(const Complex& lhs, const Complex& rhs) {
  return Complex(lhs.RealPart_ + rhs.RealPart_,
                 lhs.ImaginaryPart_ + rhs.ImaginaryPart_);
}

const Complex operator-(const Complex& lhs, const Complex& rhs) {
  return Complex(lhs.RealPart_ - rhs.RealPart_,
                 lhs.ImaginaryPart_ - rhs.ImaginaryPart_);
}

const Complex operator*(const Complex& lhs, const Complex& rhs) {
  double ac = lhs.RealPart_ * rhs.RealPart_;
  double bd = lhs.ImaginaryPart_ * rhs.ImaginaryPart_;
  double bc = lhs.ImaginaryPart_ * rhs.RealPart_;
  double ad = lhs.RealPart_ * rhs.ImaginaryPart_;

  return Complex ( (ac-bd), (bc+ad));
}

const Complex operator/(const Complex& lhs, const Complex& rhs) {
  double ac = lhs.RealPart_ * rhs.RealPart_;
  double bd = lhs.ImaginaryPart_ * rhs.ImaginaryPart_;
  double bc = lhs.ImaginaryPart_ * rhs.RealPart_;
  double ad = lhs.RealPart_ * rhs.ImaginaryPart_;
  double c2 = rhs.RealPart_ * rhs.RealPart_;
  double d2 = rhs.ImaginaryPart_ * rhs.ImaginaryPart_;

  return Complex((ac+bd)/(c2+d2), (bc-ad)/(c2+d2));
}

