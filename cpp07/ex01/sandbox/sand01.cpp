// Copyright 2926 hyaammot
#include <iostream>
#include <string>


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
