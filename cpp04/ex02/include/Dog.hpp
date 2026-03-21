// Copyright 2026 hyamamot
#ifndef CPP_EX00_INCLUDE_DOG_HPP_
#define CPP_EX00_INCLUDE_DOG_HPP_

#include <string>
#include "include/Animal.hpp"
#include "include/Brain.hpp"

class Dog : public Animal {
  Brain* brain_;
 
  public:
  Dog();
  ~Dog();
  
  void makeSound();
  
  Brain* getBrainPtr();
};

#endif  // CPP_EX00_INCLUDE_DOG_HPP_
