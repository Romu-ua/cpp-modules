// Copyright 2026 hyamamot
#ifndef EX02_INCLUDE_SCAVTRAP_HPP_
#define EX02_INCLUDE_SCAVTRAP_HPP_

#include <iostream>
#include <string>
#include "include/ClapTrap.hpp"

class ScavTrap : public ClapTrap {
 public:
  explicit ScavTrap(std::string name);
  ~ScavTrap();

  void guardGate();
};

#endif  // EX02_INCLUDE_SCAVTRAP_HPP_
