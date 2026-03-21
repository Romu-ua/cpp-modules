// Copyright 2026 hyamamot
#include <iostream>
#include <string>

#include "include/Weapon.hpp"
#include "include/HumanA.hpp"
#include "include/HumanB.hpp"

int main() {
  {
    Weapon w("hello weaopne");
    std::cout << w.getType() << std::endl;
    w.setType("changed weapone");
    std::cout << w.getType() << std::endl;
  
    std::cout << "---" << std::endl;
    HumanA a("bob", w);
    a.attack();
  
    std::cout << "---" << std::endl;
    HumanB b("Ami");
    b.attack();
  }

  std::cout << "-- pdf test --" << std::endl;
  {
    Weapon club = Weapon("crude spiked club");

    HumanA bob("Bob", club);
    bob.attack();
    club.setType("some other type of club");
    bob.attack();
  }
  std::cout << std::endl;
  {
    Weapon club = Weapon("crude spiked club");

    HumanB jim("Jim");
    jim.setWeapon(club);
    jim.attack();
    club.setType("some other type of club");
    jim.attack();
  }
  return 0;
}
