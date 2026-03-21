#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
  std::string name_;

 public:
 Zombie(std::string name);
 ~Zombie();
  void announce(void);
};

// randomChump.cpp
void randomChump(std::string name);

// newZombie.cpp
Zombie* newZombie(std::string name);

#endif  // ZOMBIE_HPP
