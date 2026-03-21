// Copyright 2026 hyamamot
#include <iostream>
#include <string>

class ClapTrap {
  std::string name_;
  int hit_point_;
  int energy_point_;
  int attack_damage_;

 public:
  ClapTrap();
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

ClapTrap::ClapTrap() : hit_point_(10), energy_point_(10), attack_damage_(0) {
  std::cout << "constructor" << std::endl;
}

ClapTrap::~ClapTrap() {
  std::cout << "destructor" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
  std::cout << "ClapTrap "
            << name_
            << " attacks "
            << target
            << ", causing "
            << attack_damage_
            << " ponts of damage!"
            << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
  std::cout << "ClapTrap took " << amount << " damage" << std::endl; 
  hit_point_ -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
  std::cout << "ClapTrap repaired " << amount << "hit point" << std::endl; 
  hit_point_ += amount;
}

int main() {
  ClapTrap bot1;
  std::string enemy = "enemy";

  std::cout << "initialized" << std::endl;
  std::cout << "name: " << bot1.name() << std::endl;
  std::cout << "hit point: " << bot1.hitPoint() << std::endl;
  std::cout << "energy point: " << bot1.energyPoint() << std::endl;
  std::cout << "attack damage: " << bot1.attackDamage() << std::endl;

  std::cout << "----" << std::endl;
  bot1.attack(enemy);
  bot1.takeDamage(42);
  std::cout << bot1.hitPoint() << std::endl;
  bot1.beRepaired(42);
  std::cout << bot1.hitPoint() << std::endl;
}
