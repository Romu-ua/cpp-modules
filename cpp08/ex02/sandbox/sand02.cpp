// Copyright 2026 hyamamot
#include <iostream>
#include <stack>
#include <vector>
#include <iterator>

/*
iteratorについて学習

stackで実装するiteratorはforward iteratorsになると思われる
いや input iteratorを実装するのか。(read only)
値が変更できたらそれはstackとは言わないだろう。

Swappableは実装しなくても良いのでは？しかし、そうすると、input iteratorではないか？

https://www.geeksforgeeks.org/cpp/input-iterators-in-cpp/

メンバ関数
https://cpprefjp.github.io/reference/stack/stack.html
adaptor container: コンテナをラップしたクラス

vectorのリファレンスを見ると、イテレータの欄がある。
つまり、この実装をすれば良いということになるのか。
listと同じ出力なるということなので、こちらを参照する
リストにあるiteratorはbeing, end rbeign, endの４つになる。

よくわからんので、web記事のiteratorを実装してみる
クラス側では、*、++ !=の演算子オーバーロードが必要になる。

コンテナクラス側ではbeginとendが必要。
これは公式ドキュメントからも明らか、また、rbeginとrendも必要だと思われる
*/


class Iterator {
 public:
  const char *p;
  const char& operator*() { return *p; }
  Iterator& operator++() { ++p; return *this; }
  bool operator!=(const Iterator& v) { return p != v.p; }
};

class String {
 public:
  const char* s;
  Iterator begin() { return {s}; }
  Iterator end() { return {s + strlen(s)}; }
};

/*

*/
class schemes {
 public:
  std::vector<std::string> a = {"http", "ssh", "ftp"};
  std::vector<std::string>::iterator begin() { return a.begin(); }
  std::vector<std::string>::iterator end() { return a.end(); }
};


int main() {
  String s = {"abc"};
  for (Iterator it = s.begin(), end = s.end(); it != end; ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}
