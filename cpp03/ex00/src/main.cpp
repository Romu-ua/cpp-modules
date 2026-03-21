// Copyright 2026 hyamamot
#include <iostream>
#include "include/ClapTrap.hpp"

int main() {
  ClapTrap bot1("bot1");
  std::string enemy = "enemy";

  std::cout << "-- initialized --" << std::endl;
  std::cout << "name: " << bot1.name() << std::endl;
  std::cout << "hit point: " << bot1.hitPoint() << std::endl;
  std::cout << "energy point: " << bot1.energyPoint() << std::endl;
  std::cout << "attack damage: " << bot1.attackDamage() << std::endl;

  std::cout << "----" << std::endl;
  bot1.attack(enemy);
  bot1.takeDamage(42);
  std::cout << bot1.hitPoint() << std::endl;
  bot1.beRepaired(42);
  std::cout << bot1.hitPoint() << std::endl;
}
