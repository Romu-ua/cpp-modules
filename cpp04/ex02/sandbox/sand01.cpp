// Copyright 2026 hyamamot
#include <iostream>
#include <string>

// 純粋抽象関数/抽象クラスの練習

/*
抽象クラスなのでconstructorとdestructorは呼ばれない
makeSoundが純粋仮想関数で、これを持っているので抽象クラスとなる。
*/
class Animal {
 protected:
  std::string type_;

 public:
  Animal(std::string type) : type_(type) {
    std::cout << "Animal constructor" << std::endl;
  }
  virtual ~Animal() {
    std::cout << "Animal destructor" << std::endl;
  }

  virtual void makeSound() = 0;
};

class Brain {
  std::string ideas[100];

 public:
  Brain() {
    std::cout << "Brain constructor" << std::endl;
  }
  ~Brain() {
    std::cout << "Brain destructor" << std::endl;
  }
};

class Cat : public Animal{
  Brain* brain_;

 public:
  Cat() : Animal("Cat") {
    std::cout << "Cat constructor" << std::endl;
    brain_ = new Brain();
  }

  /*
  1. Animal(other)でotherを渡して良いのか？
    Animalに渡しているのは、otherだが、CatはAnimalを継承しているので、
    const Animal&となる。Animalが自動作成したコピーコンストラクタで、
    type_がコピーされる。
    "Cat"と書いてもよいが、コピー元の値を無視することになるので、こちらが正しい
  2.Brainに*other.brain_を渡して良いのか？
    Brainが持つstd::stirng ideas[100]はstd::string自身がコピーコンストラクタを
    持っているので、ディープコピーされる。
    ただし、BrainがCat/Dogと同様にポインタ型を持っている時はシャローコピーになる。
  */
  Cat(const Cat& other) : Animal(other) {
    std::cout << "Cat copy constructor" << std::endl;
    brain_ = new Brain(*other.brain_);
  }

  Cat& operator=(const Cat& other) {
    std::cout << "copy operator" << std::endl;
    if (this != &other) {
      delete brain_;
      brain_ = new Brain(*other.brain_);
    }
    return *this;
  }

  ~Cat() {
    std::cout << "Cat destructor" << std::endl;
    delete brain_;
  }

  void makeSound() {
    std::cout << "makeSound in Cat" << std::endl;
  }
};

class Dog : public Animal {
  Brain* brain_;

 public:
  Dog() : Animal("Dog") {
    std::cout << "Dog constructor" << std::endl;
    brain_ = new Brain();
  }

  Dog(const Dog& other) : Animal(other) {
    std::cout << "Dog copy constructor" << std::endl;
    brain_ = new Brain(*other.brain_);
  }

  Dog& operator=(const Dog& other) {
    std::cout << "Dog copy operator" << std::endl;
    if (this != &other) {
      delete brain_;
      brain_ = new Brain(*other.brain_);
    }
    return *this;
  }

  ~Dog() {
    std::cout << "Dog constructor" << std::endl;
    delete brain_;
  }

  void makeSound() {
    std::cout << "makeSound in Dog" << std::endl;
  }
};

int main() {
  // error: cannot declare variable ‘animal’ to be of abstract type ‘Animal’
  //Animal animal("animal");

  Animal* cat = new Cat();
  Animal* dog = new Dog();

  std::cout << "--- makeSound ---" << std::endl;
  cat->makeSound();
  dog->makeSound();
  std::cout << "-----------------" << std::endl;

  delete cat;
  delete dog;
}
