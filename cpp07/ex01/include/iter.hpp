// Copyright 2026 hyamamot
#ifndef CPP07_EX01_INCLUDE_ITER_HPP_
#define CPP07_EX01_INCLUDE_ITER_HPP_

#include <ctype.h>

template <typename T>
void func(T& elem) {
  std::cout << elem << std::endl; 
}

template <typename T>
void iter (T* array, const size_t size, void(*func)(T&)) {
  for (size_t i = 0; i < size; ++i) {
    func(array[i]);
  }
}

#endif  // CPP07_EX01_INCLUDE_ITER_HPP_
