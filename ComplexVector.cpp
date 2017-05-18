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

ComplexVector::ComplexVector() { }

ComplexVector::ComplexVector(Complex& num) : VectorParts_( {num} ) { }

ComplexVector::ComplexVector(double a, double b, double c, double d, double e, double f, double g, double h)
    : VectorParts_({ Complex(a, b), Complex(c, d), Complex(e, f),
                     Complex(g, h) })
{ }

ComplexVector::~ComplexVector() {
}

ComplexVector::ComplexVector(const ComplexVector& copy)
    : VectorParts_(copy.VectorParts_) {
}

void ComplexVector::computeSequence(int n) {
  std::ofstream outFile("ComplexSequence.txt", std::ios::app);
  if (n == 0) {
    VectorParts_.push_back( (1,1) );
  }
  Complex num( 2*(n+1), 3*(n+1) );
  Complex den( 7, 5*((n+1)*(n+1)));
  Complex result = num / den * VectorParts_[n];
  if (n < 5) {
    VectorParts_.push_back(result);
    computeSequence(n + 1);
  }

  if (n == 5) {
    for (auto i : VectorParts_) {
      outFile << i << endl;
    }
  }
}

void ComplexVector::print() const {
  auto& end = *(VectorParts_.rbegin());

  cout << " <";

  cout.setf(std::ios::fixed);
  cout.precision(PRECISION);

  for (auto& i : VectorParts_) {
    cout << setw(WIDTH) << i;

    if (&i != &end) {
      cout << setw(WIDTH) << " , ";

    } else {
      cout << " >\n";
    }
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