// Copyright 2026 hyamamot
#include <iostream>
#include <string>
#include "include/ClapTrap.hpp"
#include "include/ScavTrap.hpp"
#include "include/FragTrap.hpp"

int main() {
  std::string enemy = "enemy";

  FragTrap fragbot1("frag bot1");

  std::cout << "initialized" << std::endl;
  std::cout << "name: " << fragbot1.name() << std::endl;
  std::cout << "hit point: " << fragbot1.hitPoint() << std::endl;
  std::cout << "energy point: " << fragbot1.energyPoint() << std::endl;
  std::cout << "attack damage: " << fragbot1.attackDamage() << std::endl;

  std::cout << "----" << std::endl;
  fragbot1.attack(enemy);
  fragbot1.takeDamage(42);
  std::cout << fragbot1.hitPoint() << std::endl;
  fragbot1.beRepaired(42);
  std::cout << fragbot1.hitPoint() << std::endl;

  fragbot1.highFivesGuys();
}
