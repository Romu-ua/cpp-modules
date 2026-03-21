// Copyright 2026 hyamamot
#include <iostream>
#include <string>
#include <map>

/*
メンバ関数ポインタの練習
*/

class Test {
  int add(int a, int b) { return a + b; }
  int sub(int a, int b) { return a - b; }
  int mul(int a, int b) { return a * b; }

 public:
  int calc(std::string operation);
};

/*
メンバ関数ポインタの宣言は
int (Test::*func)(int, int)と書いていたが、
funcが変数名で、int (Test::*)(int, int)が型だとみなすとわかりやすい。

map::findの戻り値はstd::map(key, value)::iterator
つまり、itの戻り値は
std::map<std::string, int (Test::*)(int, int)>::iteratorになる。
// ------
iteratorの使い方:
itは("add", &Test::add)のように一つの要素を指し示す。

mapの一つの要素は std::pair<const key, value>になる。
つまり、itがさし示しているのは、上記型の値のポインタになる。
したがって、使い方はit->firstになる。
// -------
std::map::findの戻り値:
公式ドキュメントより、「そうではない場合は、end()を返す」
// --------
findで見つかった場合のreturnの値:
mapの型はstd::map<std::string, int (Test::*)(int, int))>
なので、it->secondはint (Test::*)(int, int)になる。
つまり、Testクラスのメンバ関数のポインタになる。例えば、&Test::addが入っている。
メンバ関数ポインタは
Test t
t.add(3, 4)
のように呼び出す必要がある。
よって、(this->*(it->second))(3, 4)になる。

具体的に展開すると、
(this->*(it->second))(3, 4);
  1. it->second => &Test::add
  2. *(it -> second) => add
  3. this->add
  4. this->add(3, 4);と同じになる。
*/
int Test::calc(std::string operation) {
  std::map<std::string, int (Test::*)(int, int)> table;

  table["add"] = &Test::add;
  table["sub"] = &Test::sub;
  table["mul"] = &Test::mul;
  
  std::map<std::string, int (Test::*)(int, int)>::iterator it;

  // [test] iteratorを使って全ての要素をprintしてみる
  for (it = table.begin(); it != table.end(); ++it) {
    std::cout << it->first << std::endl;
  }

  // findしてみる。
  it = table.find(operation);
  if (it != table.end()) {
    return (this->*(it->second))(3, 4);
  }

  return -1;
}

int main() {
  Test t;


  int result = t.calc("add");
  std::cout << result << std::endl;
}
