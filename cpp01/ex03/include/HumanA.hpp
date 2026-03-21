// Copyright 2026 hyamamot
#ifndef EX03_INCLUDE_HUMANA_H_
#define EX03_INCLUDE_HUMANA_H_

#include <string>
#include "include/Weapon.hpp"

class HumanA {
  Weapon& w_;
  std::string name_;

 public:
  HumanA(std::string name, Weapon& w);
  ~HumanA();

  void attack();
};

#endif  // EX03_INCLUDE_HUMANA_H_
