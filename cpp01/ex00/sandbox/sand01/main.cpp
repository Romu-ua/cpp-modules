// Copyright 2026 hyamamot
#include <iostream>
#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main() {
  Zombie* tmp = newZombie("hello world zombie");

  delete tmp;

  std::cout << std::endl;
  randomChump("random zombie");
}

Zombie* newZombie(std::string name) {
  Zombie* new_zombie = new Zombie(name);
  new_zombie->announce();
  return new_zombie;
}

void randomChump(std::string name) {
  Zombie new_zombie = Zombie(name);
  new_zombie.announce();
}
