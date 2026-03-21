// Copyright 2026 hyamamot
#include <iostream>
#include "include/Zombie.hpp"

int main() {
  Zombie* tmp = newZombie("hello world zombie");
  tmp->announce();

  delete tmp;

  std::cout << std::endl;
  randomChump("random zombie");
}
