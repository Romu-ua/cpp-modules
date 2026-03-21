// Copyright 2026 hyamamot
#include <iostream>
#include "include/Zombie.hpp"

int main() {
  int n = 4;
  Zombie* Zombies = zombieHorde(n, "hello zombies");

  for (int i = 0; i < n; i++) {
    Zombies[i].announce();
  }
  delete [] Zombies;
}
