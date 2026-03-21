// Copyright 2026 hyamamot
#include <iostream>
#include <string>
#include "include/Animal.hpp"
#include "include/Dog.hpp"

Dog::Dog() : Animal("Dog") {
  std::cout << "Dog constructor" << std::endl;
  brain_ = new Brain();
}

Dog::~Dog() {
  std::cout << "Dog desturctor" << std::endl;
  delete brain_;
}

void Dog::makeSound() {
  std::cout << "wan wawa wan waf" << std::endl;
}

Brain* Dog::getBrainPtr() {
  return brain_;
}
