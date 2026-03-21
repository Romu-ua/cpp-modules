// Copyright 2026 hyamamot
#include <iostream>
#include <string>
#include "include/iter.hpp"

int main() {
  int array[5];
  for (int i = 0; i < 5; ++i) {
    array[i] = i;
  }
  iter(array, 5, func);

  const std::string str = "hello";
  iter(str.c_str(), 5, func);


  const int const_array[5] = {0};
  iter(const_array, 5, func);
}
