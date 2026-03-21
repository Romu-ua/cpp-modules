// Copyright 2026 hyamamot
#include <iostream>
#include <string>
#include "include/Fixed.hpp"

int main() {
  std::cout << "pdf test" << std::endl;
  Fixed a;
  Fixed const b(Fixed(5.05f) * Fixed(2));

  std::cout << a << std::endl;
  std::cout << ++a << std::endl;
  std::cout << a << std::endl;
  std::cout << a++ << std::endl;
  std::cout << a << std::endl;

  std::cout << b << std::endl;
  std::cout << Fixed::max(a, b) << std::endl;

  std::cout << "-- four arithmetic operations test -- " << std::endl;
  
  Fixed c(42.24f);
  Fixed d(10);

  std::cout << "c: " << c << std::endl;
  std::cout << "d: " << d << std::endl;
  std::cout << "c + d: " << c + d << std::endl;
  std::cout << "c - d: " << c - d << std::endl;
  std::cout << "c * d: " << c * d << std::endl;
  std::cout << "c / d: " << c / d << std::endl;

  std::cout << "-- relational operators test --" << std::endl;

  std::cout << std::boolalpha;
  std::cout << "c: " << c << std::endl;
  std::cout << "d: " << d << std::endl;
  std::cout << "c == d: " << (c == d) << std::endl;
  std::cout << "c != d: " << (c != d) << std::endl;
  std::cout << "c > d: " << (c > d) << std::endl;
  std::cout << "c < d: " << (c < d) << std::endl;
  std::cout << "c <= d: " << (c <= d) << std::endl;
  std::cout << "c >= d: " << (c >= d) << std::endl;
}
