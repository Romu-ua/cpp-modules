// Copyright 2026 hyamamot
#include <iostream>
#include <string>

/*
polymorphism(多様体)基礎:
同じ名前の関数を呼び出して異なる処理を実行すること。
オーバーロードとオーバーライドで実現することができる。

オーバーロードだけを用いたプログラムは以前にやっている
=> Ad hoc polymorphism
今回はオーバーライドを用いたプログラムを練習する。
=> Subtyping polymorphism


virutalとは:
virtualは親クラスのポインタや参照を使っても、
実際のオブジェクトの方に応じて関数が呼ばれる仕組み。
virtualをつけると、どの関数を呼ぶのかを実行時に決めるようになる。

*/

// practice 1
class Human {
 public:
  virtual void show() {
    std::cout << "I am Human." << std::endl;
  }
};

class Student: public Human {
 public:
  void show() {
    std::cout << "I am Student." << std::endl;
  }
};

// practice 2
class Animal {
 public:
  virtual void Speak() {
    std::cout << "Animal sound" << std::endl;
  }
};

class Dog : public Animal {
 public:
  void Speak() {
    std::cout << "I am Dog. wow fantastic voice. (This is cry)" << std::endl;
  }
};

class Cat : public Animal {
 public:
  void Speak() {
    std::cout << "I am Cat. wow super voice. (This is cry)" << std::endl;
  }
};

int main() {
  // practice 1
  Human human;
  human.show();
  Student student;
  student.show();

  // practice 2

  // 1.newはheapにメモリを確保して、2.コンストラクタを読んでいる。
  // Dog*ではないのか？
  // > Derived*はBase*に変換できる。というルールがある。
  // メモリ構造を見ると、Animal partとDog partがある。
  // つまり、メモリが小さくなる方向は許容でき、Dogで新たに定義した関数は呼べない。
  Animal* a1 = new Dog();
  Animal* a2 = new Cat();

  a1->Speak();
  a2->Speak();
}
