// Copyright 2026 hyamamot
#include <iostream>
#include <string>
#include "include/HumanB.hpp"

HumanB::HumanB(std::string name) : w_(NULL), name_(name) {
  std::cout << "constructor with argument in HumanB." << std::endl;
}

HumanB::~HumanB() {
  std::cout << "destructor in HumanB" << std::endl;
}

void HumanB::attack() {
  if (w_ && !w_->getType().empty()) {
    std::cout << name_ << " attack with their " << w_->getType() << std::endl;
  } else {
    std::cout << name_ << " has no weapon" << std::endl;
  }
}

void HumanB::setWeapon(Weapon& w) {
  w_ = &w;
}
