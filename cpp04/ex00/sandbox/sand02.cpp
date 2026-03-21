// Copyright 2026 hyamamot
#include <iostream>
#include <string>


/*
デストラクターはvitualにする必要がある
なぜなら、
Animal* a = new Dog();
delete a;
の時、もしAnimalのdestructorがvirtualではない時、
Animal destructorだけ呼ばれて、Dog destructorは呼ばれない。

デストラクターは自動作成のはずだったが、上記コードを例にすると、
aの型 => Animal*なので、Animal destructorだけを呼ぶことになる。
もっと具体的にいうと、
+-------------+
| Animal part |
+-------------+
| Dog part    |
+-------------+
基本的に、クラスのポインタを使うときはdestructorにをvirtualにする。

deleteは1.デストラクタを呼ぶ、2. メモリを解放する、を行なっている。
つまり、概念的には、
a->~Animal(); // destructor
operator delete(a)； // メモリ解放
のようなもの。

Dogオブジェクトを作るにはAnimal partが含まれているから。Animal constructorも呼ばれ、
その順序は、Animal constructor -> Dog constructorになる。
*/
class Animal {
 protected:
  std::string type_;

 public:
  Animal(std::string type);
  virtual ~Animal();

  virtual void makeSound();
};

Animal::Animal(std::string type) : type_(type) {
  std::cout << "Animal constructor" << std::endl;
}

Animal::~Animal() {
  std::cout << "Animal destructor" << std::endl;
}

void Animal::makeSound() {
  std::cout << "The Answer to the Ultimate Question of Life, the Universe, "
               "and Everything is 'Animal'"
            << std::endl;
}

class Dog : public Animal {
 public:
  Dog();
  ~Dog();
  
  void makeSound();
};

Dog::Dog() : Animal("Dog") {
  std::cout << "Dog constructor" << std::endl;
}

Dog::~Dog() {
  std::cout << "Dog desturctor" << std::endl;
}

void Dog::makeSound() {
  std::cout << "wan wawa wan waf" << std::endl;
}

class Cat : public Animal {
 public:
  Cat();
  ~Cat();

  void makeSound();
};

Cat::Cat() : Animal("Cat") {
  std::cout << "Cat constructor" << std::endl;
}

Cat::~Cat() {
  std::cout << "Cat destructor" << std::endl;
}

void Cat::makeSound() {
  std::cout << "nya- nyanya" << std::endl;
}

// ----

class WrongAnimal {
 protected:
  std::string type_;

 public:
  WrongAnimal(std::string type);
  virtual ~WrongAnimal();

  void makeSound();
};

WrongAnimal::WrongAnimal(std::string type) : type_(type) {
  std::cout << "WrongAnimal constructor" << std::endl;
}

WrongAnimal::~WrongAnimal() {
  std::cout << "WrongAnimal destructor" << std::endl;
}

void WrongAnimal::makeSound() {
  std::cout << "WrongAnimal sound" << std::endl;
}


class WrongCat : public WrongAnimal {
 public:
  WrongCat();
  ~WrongCat();

  void makeSound();
};

WrongCat::WrongCat() : WrongAnimal("Cat") {
  std::cout << "WrongCat constructor" << std::endl;
}

WrongCat::~WrongCat() {
  std::cout << "WrongCat destructor" << std::endl;
}

void WrongCat::makeSound() {
  std::cout << "WrongCat nyanyanya" << std::endl;
}

int main() {
  Animal* dog = new Dog();
  Animal* cat = new Cat();

  dog->makeSound();
  cat->makeSound();

  delete dog;
  delete cat;

  WrongAnimal* wcat = new WrongCat();

  wcat->makeSound();

  delete wcat;
}
