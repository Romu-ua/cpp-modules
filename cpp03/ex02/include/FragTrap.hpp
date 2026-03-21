// Copyright 2026 hyamamot
#ifndef EX02_INCLUDE_FRAGTRAP_HPP_
#define EX02_INCLUDE_FRAGTRAP_HPP_

#include <iostream>
#include <string>
#include "ScavTrap.hpp"

class FragTrap : public ScavTrap {
 public:
  FragTrap(std::string name);
  ~FragTrap();

  void highFivesGuys(void);
};

#endif  // EX02_INCLUDE_FRAGTRAP_HPP_
