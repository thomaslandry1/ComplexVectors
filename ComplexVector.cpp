//
// Created by Thomas Landry on 5/17/17.
//

#include "ComplexVector.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::setw;

const int PRECISION = 1;
const int WIDTH = 2;

ComplexVector::ComplexVector() {
}

ComplexVector::ComplexVector(double a, double b, double c, double d,
                             double e, double f, double g, double h)
    : VectorParts_({ Complex(a, b), Complex(c, d),
                     Complex(e, f), Complex(g, h) }) {
}

ComplexVector::ComplexVector(const ComplexVector& copy)
    : VectorParts_(copy.VectorParts_) {
}

ComplexVector::~ComplexVector() {
}

void ComplexVector::print() const {
  auto& end = *(VectorParts_.rbegin());

  cout << " <" << *this << " >\n";
}

void ComplexVector::computeSequence(int n) {
  std::ofstream outFile("ComplexSequence.txt", std::ios::app);

  // base case
  if (n == 0) {
    VectorParts_.push_back(Complex(1, 1));
  }

  //recursive sequence setup
  Complex num(Areal_ * (n + 1), Bimag_ * (n + 1));
  Complex den(Creal_, Dimag_ * ((n + 1) * (n + 1)));
  Complex result = num / den * VectorParts_[n];

  if (n != 5) {
    VectorParts_.push_back(result);
    computeSequence(n + 1);
  } else {
    outFile << "{" << *this << " } ";
    outFile.close();
  }
}

const ComplexVector operator+(const ComplexVector& lhs, const ComplexVector& rhs) {
  std::vector<Complex>::const_iterator rhsIter = rhs.VectorParts_.begin();
  ComplexVector newVector;
  for (auto i : lhs.VectorParts_) {
    Complex result;
    newVector.VectorParts_.push_back(i + *rhsIter);
    ++rhsIter;
  }
  return newVector;
}

const ComplexVector operator-(const ComplexVector& lhs, const ComplexVector& rhs) {
  std::vector<Complex>::const_iterator rhsIter = rhs.VectorParts_.begin();
  ComplexVector newVector;
  for (auto i : lhs.VectorParts_) {
    Complex result;
    newVector.VectorParts_.push_back(i - *rhsIter);
    ++rhsIter;
  }
  return newVector;
}

const ComplexVector operator*(const ComplexVector& lhs, const ComplexVector& rhs) {
  std::vector<Complex>::const_iterator rhsIter = rhs.VectorParts_.begin();
  ComplexVector newVector;
  for (auto i : lhs.VectorParts_) {
    Complex result;
    newVector.VectorParts_.push_back(i * *rhsIter);
    ++rhsIter;
  }
  return newVector;
}

const ComplexVector operator/(const ComplexVector& lhs, const ComplexVector& rhs) {
  std::vector<Complex>::const_iterator rhsIter = rhs.VectorParts_.begin();
  ComplexVector newVector;
  for (auto i : lhs.VectorParts_) {
    Complex result;
    newVector.VectorParts_.push_back(i / *rhsIter);
    ++rhsIter;
  }
  return newVector;
}

std::ostream& operator<<(std::ostream& os, const ComplexVector& rhs) {

  //iterator to reverse beginning of vector
  //needed because ranged based for loops unable to offer index of current
  auto& end = *(rhs.VectorParts_.rbegin());

  cout.setf(std::ios::fixed);
  cout.precision(PRECISION);

  for (auto& i : rhs.VectorParts_) {
    os << setw(WIDTH) << i;

    if (&i != &end) {
      os << setw(WIDTH) << " , ";

    } else {
      os << "";
    }
  }
  return os;
}
