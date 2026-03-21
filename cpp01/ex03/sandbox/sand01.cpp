// Copyright 2026 hyamamot
#include <iostream>
#include <string>

/*
知識の復習: 関数の後ろにつくconstは非コンストのメンバ変数はreturnできないという意味。
constの変数を返すときはconst std::string&とする
*/
class Weapon {
  std::string type_;
 public:
  explicit Weapon(std::string type);
  ~Weapon();
  const std::string& getType() const;
  void setType(std::string type);
};

Weapon::Weapon(std::string type) : type_(type) {
  std::cout << "constructor set type_" << std::endl;
}

Weapon::~Weapon() {
  std::cout << "destructor" << std::endl;
}

/*
この関数でreturn type;だけでも同じ意味になる
*/
const std::string& Weapon::getType() const {
  const std::string& typeREF = type_;
  return typeREF;
}

void Weapon::setType(std::string type) {
  type_ = type;
}

class HumanA {
  Weapon w_;
  std::string name_;

 public:
  explicit HumanA(Weapon w);
  void attack() {
    std::cout << name_ << "attack with their" << w_.getType() << std::endl;
  }
};

/*
こうするとw_ = wが実行される？
*/
HumanA::HumanA(Weapon w) : w_(w) {
  std::cout << "Human A constructor" << std::endl;
}

/*
「HumanBクラスはWeaponクラスを常に持っているとは限らない」
これをどうやって実装するのか
持っていない可能性があるということは、w_を動的に作成するということ？
ここに宣言だけをしていて、初期化はしないということで良いのか？

=>
HumanAはWeapon& w_で持つことによって、初期化時に引数のWeaponのコピーを作成しなくて良い。
HumanBはWeapon* w_で持つことによって、持たない可能性を表現できるし、初期化時にコピーを
作成しない。
*/
class HumanB {
  Weapon w_;
  std::string name_;

 public:
  explicit HumanB();
  ~HumanB();
  void attack() {
    std::cout << name_ << "attack with their" << w_.getType() << std::endl;
  }
};


int main() {
  // [bebug] Weapon class
  Weapon w("hello world");
  std::cout << w.getType() << std::endl;
  w.setType("set new type");
  std::cout << w.getType() << std::endl;


}
