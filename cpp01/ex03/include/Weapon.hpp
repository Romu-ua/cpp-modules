// Copyright 2026 hyamamot
#ifndef EX03_INCLUDE_WEAPON_H_
#define EX03_INCLUDE_WEAPON_H_

#include <string>

class Weapon {
  std::string type_;

 public:
  explicit Weapon(std::string type);
  ~Weapon();
  const std::string& getType() const;
  void setType(std::string type);
};

#endif  // EX03_INCLUDE_WEAPON_H_
