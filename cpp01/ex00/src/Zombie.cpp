// Copyright 2026 hyamamot
#include <iostream>
#include <string>
#include "include/Zombie.hpp"

Zombie::Zombie(std::string name) : name_(name) {
  std::cout << "constructor: setting name" << std::endl;
}

Zombie::~Zombie() {
  std::cout << "destructor: " << name_ << std::endl;
}

void Zombie::announce(void) {
  std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
