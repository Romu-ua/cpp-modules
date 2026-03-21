// Copyright 2026 hyamamot
#include "include/ClapTrap.hpp"
#include <iostream>
#include <string>

ClapTrap::ClapTrap(std::string name)
  : name_(name),
    hit_point_(10),
    energy_point_(10),
    attack_damage_(0) {
  std::cout << "constructor" << std::endl;
}

ClapTrap::~ClapTrap() {
  std::cout << "destructor" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
  std::cout << "ClapTrap "
            << name_
            << " attacks "
            << target
            << ", causing "
            << attack_damage_
            << " ponts of damage!"
            << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
  std::cout << "ClapTrap took " << amount << " damage" << std::endl;
  hit_point_ -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
  std::cout << "ClapTrap repaired " << amount << "hit point" << std::endl;
  hit_point_ += amount;
}
