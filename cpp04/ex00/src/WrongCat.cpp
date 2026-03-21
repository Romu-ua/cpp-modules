// Copyright 2026 hyamamot
#include <iostream>
#include <string>
#include "include/WrongAnimal.hpp"
#include "include/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("Cat") {
  std::cout << "WrongCat constructor" << std::endl;
}

WrongCat::~WrongCat() {
  std::cout << "WrongCat destructor" << std::endl;
}

void WrongCat::makeSound() {
  std::cout << "WrongCat nyanyanya" << std::endl;
}
