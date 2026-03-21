// Copyright 2026 hyamamot
#ifndef CPP_EX00_INCLUDE_WRONGCAT_HPP_
#define CPP_EX00_INCLUDE_WRONGCAT_HPP_

#include <string>
#include "include/WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
 protected:
  std::string type_;

 public:
  WrongCat();
  virtual ~WrongCat();

  void makeSound();
};

#endif  // CPP_EX00_INCLUDE_WRONGCAT_HPP_
