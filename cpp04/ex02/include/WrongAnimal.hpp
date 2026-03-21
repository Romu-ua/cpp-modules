// Copyright 2026 hyamamot
#ifndef CPP_EX00_INCLUDE_WRONGANIMAL_HPP_
#define CPP_EX00_INCLUDE_WRONGANIMAL_HPP_

#include <string>

class WrongAnimal {
 protected:
  std::string type_;

 public:
  WrongAnimal(std::string type);
  virtual ~WrongAnimal();

  void makeSound();
};

#endif  // CPP_EX00_INCLUDE_WRONGANIMAL_HPP_
