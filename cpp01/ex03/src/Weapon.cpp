// Copyright 2026 hyamamot
#include <string>
#include <iostream>
#include "include/Weapon.hpp"

Weapon::Weapon(std::string type) : type_(type) {
  std::cout << "constructor in Weapon" << std::endl;
}

Weapon::~Weapon() {
  std::cout << "destructor in Weapon" << std::endl;
}

const std::string& Weapon::getType() const {
  return type_;
}

void Weapon::setType(std::string type) {
  type_ = type;
}
