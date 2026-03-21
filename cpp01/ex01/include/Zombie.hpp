// Copyright 2026 hyamamot
#ifndef CPP01_EX01_INCLUDE_ZOMBIE_HPP_
#define CPP01_EX01_INCLUDE_ZOMBIE_HPP_

#include <string>

class Zombie {
  std::string name_;

 public:
  Zombie();
  explicit Zombie(std::string name);
  ~Zombie();

  void SetName(std::string name);

  void announce(void);
};

// zombieHorde.cpp
Zombie* zombieHorde(int N, std::string name);

#endif  // CPP01_EX01_INCLUDE_ZOMBIE_HPP_
