// Copyright 2026 hyamamot
#include <iostream>
// sequence container
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <array>
// adapter container
#include <stack>
#include <queue> // queue, priority_queue


/*
findはalgorithm
https://www.geeksforgeeks.org/cpp/std-find-in-cpp/
std::find(begin, end, value);

adapter containerにはbeginとendはないので実装しなくて良い。

findのreturnはiterator
これについて学習

stack, deque, priority-queueがno iterator supported

コンパイラはT::iteratorを型だと判定できない
struct A {
  static int iterator;
}
の時、A::iteratorはintの静的メンバになるから。
なので型であることを明示するためにtypenameをつける

::iteratorを持っていない値、プリミティブが渡されることはない。
なぜなら、T::iteratorで型推論するときに、コンパイルエラーになるから。
*/

template <typename T>
typename T::iterator easyfind(T& container, int value) {
  typename T::iterator it = find(container.begin(), container.end(), value);
  if (it == container.end()) {
    throw std::exception();
  }
  return it;
}

int main() {
  std::vector<int> vec = {1, 2, 42};

  std::vector<int>::iterator it1 = vec.begin();
  std::cout << *it1 << std::endl;

  // つまり、findのreturnがiteratorなので、T::iteratorになる。

  std::vector<int>::iterator it2 = easyfind(vec, 42);
  std::cout << *it2 << std::endl;

  // compile error
  //int a = 42;
  //easyfind(a, 42);

  
  try{
    std::vector<int>::iterator it3 = easyfind(vec, 1337);
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
}


