// Copyright 2026 hyamamot
#include <iostream>
#include <string>
#include "include/Zombie.hpp"

Zombie::Zombie() {
  std::cout << "default constructor" << std::endl;
}

Zombie::Zombie(std::string name) : name_(name) {
  std::cout << "constructor: setting name" << std::endl;
}

Zombie::~Zombie() {
  std::cout << "destructor: " << name_ << std::endl;
}

void Zombie::SetName(std::string name) {
  name_ = name;
}

void Zombie::announce(void) {
  std::cout << name_ << ": BraiiiiiiinnnnzzzZ..." << std::endl;
}
