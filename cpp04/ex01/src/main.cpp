// Copyright 2026 hyamamot
#include <iostream>
#include <string>
#include "include/Animal.hpp"
#include "include/Dog.hpp"
#include "include/Cat.hpp"
#include "include/WrongAnimal.hpp"
#include "include/WrongCat.hpp"


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

  std::cout << "----" << std::endl;

  // Animalのポインターで、Dog, Catを半分ずつ入れるから、この定義になる。
  // Animal* animal = new Dog[10]とかだと、delete [] を使う。
  //Animal* animals[10];

  //for (int i = 0; i < 10 / 2; ++i) {
  //  animals[i] = new Dog();
  //}
  
  //for (int i = 10 / 2; i < 10; ++i) {
  //  animals[i] = new Cat();
  //}

  //for (int i = 0; i < 10; ++i) {
  //  delete animals[i];
  //}

  /*
  Dog a;
  Dog b = a;
  この時、c++は自動コピーになる。
  つまり、a.brain_ とb.brain_が指すbrainが同じになる。
  polymorphismの練習でクラスのポインタで定義していると、シャローコピーは起きない。
  単にインスタンス化した時に起こる。
  */
  //Dog dog1;
  //Dog dog2 = dog1;

  //if (dog1.getBrainPtr() == dog2.getBrainPtr()) {
  //  std::cout << "same object" << std::endl;
  //}
  // 出力を確認した。
  // こうすると、デストラクタが呼ばれた時に、同じBrainをdeleteしているので、double freeになる。
  // 自動コピーは b = aと b(a)の時に起こるので、
  // コピーコンストラクタと、=の演算子オーバーロードが必要。
  // だから、入門書に演算子オーバーロードが乗っているのか。

  std::cout << "deep copy test" << std::endl;
  Cat cat1;
  Cat cat2 = cat1;
}

/*
クラスがnew delete メモリ管理をするなら、
destructor,
copy constructor
copy assignment operator
の全てを実装するというrule of threeがあるらしい。
*/
