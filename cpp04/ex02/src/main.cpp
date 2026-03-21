// Copyright 2026 hyamamot
#include <iostream>
#include <string>
#include "include/Animal.hpp"
#include "include/Dog.hpp"
#include "include/Cat.hpp"
#include "include/WrongAnimal.hpp"
#include "include/WrongCat.hpp"


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
