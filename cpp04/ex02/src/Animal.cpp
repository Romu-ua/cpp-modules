// Copyright 2026 hyamamot
#include <iostream>
#include <string>
#include "include/Animal.hpp"

Animal::Animal(std::string type) : type_(type) {
  std::cout << "Animal constructor" << std::endl;
}

Animal::~Animal() {
  std::cout << "Animal destructor" << std::endl;
}
