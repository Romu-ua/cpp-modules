// Copyright 2026 hyamamot
#ifndef CPP01_EX03_INCLUDE_HUMANA_HPP_
#define CPP01_EX03_INCLUDE_HUMANA_HPP_

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

#endif  // CPP01_EX03_INCLUDE_HUMANA_HPP_
