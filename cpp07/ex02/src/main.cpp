// Copyright 2026 hyamamot
#include <iostream>
#include <string>
#include "include/Array.hpp"
#include "include/Array.tpp"

int main() {
  Array<int> array1;
  Array<int> array2(42);
  Array<int> array3(array2);

  try {
    std::cout << array1[0] << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  array1 = array2;

  std::cout << array1[0] << std::endl;
  try {
    std::cout << array1[43] << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
}
