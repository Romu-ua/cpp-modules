// Copyright 2026 hyamamot
#include <iostream>
// sequence container
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <array>
// adapter container
#include <stack>
#include <queue> // queue, priority_queue
#include "include/easyfind.hpp"

int main() {
  std::vector<int> vec;
  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(42);


  std::vector<int>::iterator it1 = vec.begin();
  std::cout << *it1 << std::endl;

  // つまり、findのreturnがiteratorなので、T::iteratorになる。

  std::vector<int>::iterator it2 = easyfind(vec, 42);
  std::cout << *it2 << std::endl;

  // compile error
  //int a = 42;
  //easyfind(a, 42);

  
  try{
    std::vector<int>::iterator it3 = easyfind(vec, 1337);
    std::cout << *it3 << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
}
