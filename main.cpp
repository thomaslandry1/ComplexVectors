#include "ComplexVector.h"
#include <iostream>
#include <iomanip>

using std::cout;
using std::setw;
const int width = 9;

int main() {

  ComplexVector v1(2.0, 4.0, 3.0, 5.0, -1.0, -3.0, 8.0, 10.0);
  ComplexVector v2(-10.0, 3.5, 4.0, 7.3, 2.0, -8.0, 10.0, -142.0);
  cout << setw(width) << "v1 =";
  v1.print();
  cout << setw(width) << "v2 =";
  v2.print();

  cout << setw(width) << "v1 + v2 =";
  (v1 + v2).print();

  cout << setw(width) << "v1 - v2 =";
  (v1 - v2).print();

  cout << setw(width) << "v1 * v2 =";
  (v1 * v2).print();

  cout << setw(width) << "v1 / v2 =";
  (v1 / v2).print();

  ComplexVector test;

  test.computeSequence(0);

  return 0;
}