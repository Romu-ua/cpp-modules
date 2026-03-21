// Copyright 2026 hyamamot
#ifndef EX00_INCLUDE_CLAPTRAP_H_
#define EX00_INCLUDE_CLAPTRAP_H_

#include <iostream>
#include <string>

class ClapTrap {
  std::string name_;
  int hit_point_;
  int energy_point_;
  int attack_damage_;

 public:
  ClapTrap();
  ClapTrap(std::string name);
  ClapTrap(const ClapTrap& other);
  ClapTrap& operator=(const ClapTrap& rhs);
  ~ClapTrap();

  void attack(const std::string& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);

  std::string name() const;
  int hitPoint() const;
  int energyPoint() const;
  int attackDamage() const;

  void setName(std::string& name);
  void setHitPoint(int hit_point);
  void setEnergyPoint(int energy_point);
  void setAttackDamage(int attack_damage);
};

#endif  // EX00_INCLUDE_CLAPTRAP_H_
