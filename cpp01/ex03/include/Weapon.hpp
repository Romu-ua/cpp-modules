// Copyright 2026 hyamamot
#ifndef CPP01_EX03_INCLUDE_WEAPON_HPP_
#define CPP01_EX03_INCLUDE_WEAPON_HPP_

#include <string>

class Weapon {
  std::string type_;

 public:
  explicit Weapon(std::string type);
  ~Weapon();
  const std::string& getType() const;
  void setType(std::string type);
};

#endif  // CPP01_EX03_INCLUDE_WEAPON_HPP_
