#ifndef EX01_INCLUDE_ZOMBIE_HPP
#define EX01_INCLUDE_ZOMBIE_HPP

#include <string>

class Zombie {
  std::string name_;

 public:
  Zombie();
  Zombie(std::string name);
  ~Zombie();

  void SetName(std::string name);

  void announce(void);
};

// zombieHorde.cpp
Zombie* zombieHorde(int N, std::string name);

#endif  // EX01_INCLUDE_ZOMBIE_HPP
