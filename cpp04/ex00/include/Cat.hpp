// Copyright 2026 hyamamot
#ifndef CPP_EX00_INCLUDE_CAT_HPP_
#define CPP_EX00_INCLUDE_CAT_HPP_

#include <string>
#include "include/Animal.hpp"
#include "include/Brain.hpp"

class Cat : public Animal {
  Brain* brain_;
  
 public:
  Cat();
  Cat(const Cat& other);
  ~Cat();

  Cat& operator=(const Brain& rhs);

  void makeSound();
};

#endif  // CPP_EX00_INCLUDE_CAT_HPP_
