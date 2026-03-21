// Copyright 2026 hyamamot
#ifndef CPP_EX00_INCLUDE_ANIMAL_HPP_
#define CPP_EX00_INCLUDE_ANIMAL_HPP_

#include <string>
#include "include/Brain.hpp"

class Animal {
 protected:
  std::string type_;

 public:
  Animal(std::string type);
  virtual ~Animal();

  virtual void makeSound();
};

#endif  // CPP_EX00_INCLUDE_ANIMAL_HPP_
