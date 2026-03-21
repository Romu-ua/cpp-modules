// Copyright 2026 hyamamot
#include <iostream>
#include <string>
#include "include/whatever.hpp"

int main() {
  std::cout << "[pdf test]" << std::endl;
  int a = 2;
  int b = 3;

  ::swap(a, b);
  std::cout << "a = " << a << ", b = " << b << std::endl;
  std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
  std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

  std::string c = "chain1";
  std::string d = "chain2";

  ::swap(c, d);
  std::cout << "c = " << c << ", d = " << d << std::endl;
  std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
  std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

  std::cout << "[swap test]" << std::endl;
  a = 42;
  b = 24;

  std::cout << std::endl;

  std::cout << "a: " << a << " b: " << b << std::endl;
  ::swap<int>(a, b);
  std::cout << "a: " << a << " b: " << b << std::endl;

  std::cout << std::endl;

  std::cout << "[min, max test]" << std::endl;
  int x = 5;
  int y = 6;

  std::cout << "x: " << x << " y: " << y << std::endl;
  std::cout << "min(x, y): " << ::min(x, y) << std::endl;
  std::cout << "max(x, y): " << ::max(x, y) << std::endl;

  std::cout << std::endl;

  // return the second one
  int first = -42;
  int second = -42;
  std::cout << "first: " << first << " second: " << second << std::endl;

  int& second_ptr = ::min(first, second);
  std::cout << "min(first, second): " << ::min(first, second) << std::endl;
  std::cout << "origianl first address: " << &first << std::endl;
  std::cout << "origianl second address: " << &second << std::endl;
  std::cout << "min return address: " << &second_ptr << std::endl;

  second_ptr = ::max(first, second);
  std::cout << "max(first, second): " << ::max(first, second) << std::endl;
  std::cout << "origianl first address: " << &first << std::endl;
  std::cout << "origianl second address: " << &second << std::endl;
  std::cout << "max return address: " << &second_ptr << std::endl;
}
