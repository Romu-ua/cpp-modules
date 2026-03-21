// Copyright 2026 hyamamot
#ifndef EX00_INCLUDE_CLAPTRAP_HPP_
#define EX00_INCLUDE_CLAPTRAP_HPP_

#include <iostream>
#include <string>

class ClapTrap {
  std::string name_;
  int hit_point_;
  int energy_point_;
  int attack_damage_;

 public:
  ClapTrap(std::string name);
  ~ClapTrap();
  void attack(const std::string& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);

  // getterとsetterを定義する
  // 可読性のために、定義もクラスの中に書く
  std::string name() const { return name_; }
  int hitPoint() const { return hit_point_; }
  int energyPoint() const { return energy_point_; }
  int attackDamage() const { return attack_damage_; }

  void setName(std::string& name) { name_ = name; }
  void setHitPoint(int hit_point) { hit_point_ = hit_point; }
  void setEnergyPoint(int energy_point) { energy_point_ = energy_point; }
  void setAttackDamage(int attack_damage) { attack_damage_ = attack_damage; }
};

#endif  // EX00_INCLUDE_CLAPTRAP_HPP_
