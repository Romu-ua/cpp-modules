// Copyright 2026 hyamamot
#include <iostream>
#include "include/ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : name_(name), hit_point_(10), energy_point_(10), attack_damage_(0) {
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
  energy_point_ -= 1;
}

void ClapTrap::takeDamage(unsigned int amount) {
  std::cout << "ClapTrap" << name_ <<  " was took " << amount << " damage" << std::endl; 
  hit_point_ -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
  std::cout << "ClapTrap " << name_  <<  " was repaired " << amount << "hit point" << std::endl; 
  hit_point_ += amount;
  energy_point_ -= 1;
}




std::string ClapTrap::name() const { return name_; }
int ClapTrap::hitPoint() const { return hit_point_; }
int ClapTrap::energyPoint() const { return energy_point_; }
int ClapTrap::attackDamage() const { return attack_damage_; }

void ClapTrap::setName(std::string& name) { name_ = name; }
void ClapTrap::setHitPoint(int hit_point) { hit_point_ = hit_point; }
void ClapTrap::setEnergyPoint(int energy_point) { energy_point_ = energy_point; }
void ClapTrap::setAttackDamage(int attack_damage) { attack_damage_ = attack_damage; }
