// Copyright 2026 hyamamot
#include <iostream>
#include <string>
#include "include/ClapTrap.hpp"
#include "include/ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
  std::cout << "ScavTrap constructor" << std::endl;
  setHitPoint(100);
  setEnergyPoint(50);
  setAttackDamage(20);
}

ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap destructor" << std::endl;
}

void ScavTrap::guardGate() {
  std::cout << "ScavTrap is now in Gate keeper mdoe." << std::endl;
}
