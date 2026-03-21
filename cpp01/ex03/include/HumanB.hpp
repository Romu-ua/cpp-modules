// Copyright 2026 hyamamot
#ifndef EX03_INCLUDE_HUMANB_H_
#define EX03_INCLUDE_HUMANB_H_

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

#endif  // EX03_INCLUDE_HUMANB_H_
