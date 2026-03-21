// Copyright 2026 hyamamot
#include <iostream>
#include <string>
#include "include/WrongAnimal.hpp"

WrongAnimal::WrongAnimal(std::string type) : type_(type) {
  std::cout << "WrongAnimal constructor" << std::endl;
}

WrongAnimal::~WrongAnimal() {
  std::cout << "WrongAnimal destructor" << std::endl;
}

void WrongAnimal::makeSound() {
  std::cout << "WrongAnimal sound" << std::endl;
}
