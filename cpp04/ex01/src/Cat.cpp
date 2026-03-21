// Copyright 2026 hyamamot
#include <iostream>
#include <string>
#include "include/Animal.hpp"
#include "include/Cat.hpp"

Cat::Cat() : Animal("Cat") {
  std::cout << "Cat constructor" << std::endl;
  brain_ = new Brain();
}

// Animal partコピーはAnimalに任せる
// Animalはシャローコピーになる
Cat::Cat(const Cat& other) : Animal(other) {
  brain_ = new Brain(*other.brain_);
}

Cat& Cat::operator=(const Cat& other) {
  std::cout << "copy operator" << std::endl;
  if (this != &other) {
    delete brain_;
    brain_ = new Brain(*other.brain_); // Brainにコピーコンストラクタを書かなくてもc++が自動作成したコピーコンストラクタが呼ばれる。
  }
  return *this;
}

Cat::~Cat() {
  std::cout << "Cat destructor" << std::endl;
  delete brain_;
}

void Cat::makeSound() {
  std::cout << "nya- nyanya" << std::endl;
}

