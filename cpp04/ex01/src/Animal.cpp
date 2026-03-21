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

void Animal::makeSound() {
  std::cout << "The Answer to the Ultimate Question of Life, the Universe, "
               "and Everything is 'Animal'"
            << std::endl;
}
