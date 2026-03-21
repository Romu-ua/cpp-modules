// Copyright 2026 hyamamot
#include <iostream>
#include <string>
#include "include/ClapTrap.hpp"
#include "include/ScavTrap.hpp"

int main() {
  std::string enemy = "enemy";

  ScavTrap scavbot("scav bot1");
  std::cout << "initialized" << std::endl;
  std::cout << "name: " << scavbot.name() << std::endl;
  std::cout << "hit point: " << scavbot.hitPoint() << std::endl;
  std::cout << "energy point: " << scavbot.energyPoint() << std::endl;
  std::cout << "attack damage: " << scavbot.attackDamage() << std::endl;

  std::cout << "----" << std::endl;
  scavbot.attack(enemy);
  scavbot.takeDamage(42);
  std::cout << scavbot.hitPoint() << std::endl;
  scavbot.beRepaired(42);
  std::cout << scavbot.hitPoint() << std::endl;

  scavbot.guardGate();
}
