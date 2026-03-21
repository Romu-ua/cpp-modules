// Copyright 2026 hyamamot
#include <iostream>
#include <string>
#include "include/ScavTrap.hpp"
#include "include/FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ScavTrap(name) {
  std::cout << "FragTrap constructor" << std::endl;
  setHitPoint(100);
  setEnergyPoint(100);
  setAttackDamage(30);
}

FragTrap::~FragTrap() {
  std::cout << "FragTrap destructor" << std::endl;
}

void FragTrap::highFivesGuys(void) {
  std::cout << "positive high-fives request" << std::endl;
}
