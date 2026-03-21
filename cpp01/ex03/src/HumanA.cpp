// Copyright 2026 hyamamot
#include <iostream>
#include <string>
#include "include/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& w) :  w_(w), name_(name) {
  std::cout << "constructor with argument in HumanA." << std::endl;
}

HumanA::~HumanA() {
  std::cout << "destructor in HumanA" << std::endl;
}

void HumanA::attack() {
  std::cout << name_ << " attack with their " << w_.getType() << std::endl;
}
