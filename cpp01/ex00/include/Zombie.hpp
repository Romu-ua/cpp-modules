// Copyright 2026 hyamamot
#ifndef CPP01_EX00_INCLUDE_ZOMBIE_HPP_
#define CPP01_EX00_INCLUDE_ZOMBIE_HPP_

#include <string>

class Zombie {
  std::string name_;

 public:
  explicit Zombie(std::string name);
  ~Zombie();
  void announce(void);
};

// randomChump.cpp
void randomChump(std::string name);

// newZombie.cpp
Zombie* newZombie(std::string name);

#endif  // CPP01_EX00_INCLUDE_ZOMBIE_HPP_
