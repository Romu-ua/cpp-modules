// Copyright 2026 hyamamot
#include <iostream>
#include <string>

/*
メンバ関数ポインタの練習
*/

class Test {
 public:
  void hello() {
    std::cout << "HI!" << std::endl;
  }
};

int add(int a, int b) {
  return a + b;
}

int main() {
  Test t;

  /*
  1. なぜ&をつけているのか？
    クラスの関数名は自動的にアドレスに変換されない。
    つまり、
    int (*func)(int, int) = add;
    のように書いたときに書けないので明示的に、&をつけている。

  2. なぜTes::が*fの宣言に必要なのか？
    例えば２つのクラスが同じ関数名を持っている時、区別ができない。
    Test::*と書くと、Testクラスのメンバ関数のポインタと言う意味になる。
    void (*f)();と書くと、普通の関数ポインタと言う意味になるが、
    メンバ関数は、実質的にはHello(Test* this)になるから、void (*)()には代入できない。
    ちなみに、void (*f)(Test* this)で宣言すると別の意味になる。
  */
  void (Test::*f)() = &Test::hello;

  /*
  3. なぜt.が必要なのか
    例えば２つのクラスが同じ関数名を持っている時、区別ができない。
    つまり、どのクラスのインスタンスのhelloかを明示する必要がある。
  */
  (t.*f)();
}
