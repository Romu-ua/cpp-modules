// Copyright 2026 hyamamot
#ifndef CPP01_EX03_INCLUDE_HUMANB_HPP_
#define CPP01_EX03_INCLUDE_HUMANB_HPP_

#include <string>
#include "include/Weapon.hpp"

class HumanB {
  Weapon* w_;
  std::string name_;

 public:
  explicit HumanB(std::string name);
  ~HumanB();
  void attack();
  void setWeapon(Weapon& w);
};

#endif  // CPP01_EX03_INCLUDE_HUMANB_HPP_
