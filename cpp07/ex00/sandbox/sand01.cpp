// Copyright 2026 hyamamot
#include <iostream>
#include <string>

/*
テンプレートについて学習
*/

// Tのスコープは次に宣言される一つの関数、またはクラス
template <typename T>
T max(T a, T b) {
  // [test]
  std::cout << "typeid(T).name(): " << typeid(T).name() << std::endl;
  if (a > b) {
    return a;
  }
  return b;
}

template <typename T>
T min(T a, T b) {
  // [test]
  std::cout << "typeid(T).name(): " << typeid(T).name() << std::endl;
  if (a < b) {
    return a;
  }
  return b;
}

template <typename T>
class Box {
 private:
  T value;

 public:
  Box(T v) {
    value = v;
  }

  T get() { return value; }
};


template <typename T>
void print(T value) {
  std::cout << value << std::endl;
}

template <>
void print<std::string>(std::string value) {
  std::cout << "string: " << value << std::endl;
}

template <typename T>
class Printer {
 public:
  void print(T value) {
    std::cout << value << std::endl;
  }
};

template <>
class Printer<int> {
 public:
  void print(int value) {
    std::cout << "fantastic int : " << value << std::endl;
  }
};

template <typename T>
class Printer<T*> {
 public:
  void print(int* value) {
    std::cout << "pointer type" << std::endl;
  }
};


// 整数値をテンプレート引数にすることもできる
// ::valueは定義されていないが、
// テンプレートは実際に使われた時に実体化され、その時点でvalueが定義される。
// Factorial<3>::value
// > value = 3 * Factorial<2>::value
// Factorial<2>::value
// > value = 2 * Factorial<1>::value
// Factorial<1>::value
// > value = 1 * Factorial<0>::value
// Factorial<0>::value = 1ここでvalueが確定する。
template <int N>
struct Factorial {
  static const int value = N * Factorial<N-1>::value;
};

// 終了条件
template <>
struct Factorial<0> {
  static const int value = 1;
};


// 特殊化を用いて、型の判定もできる。
template <typename T>
struct is_pointer {
  static const bool value = false;
};

template <typename T>
struct is_pointer<T*> {
  static const bool value = true;
};



int main() {
  // 1. 関数テンプレート
  std::cout << "1. ---" << std::endl;
  std::cout << max(3, 5) << std::endl;
  std::cout << max(3.5, 4.2) << std::endl;

  std::cout << min(0.1f, 0.2f) << std::endl;
  std::cout << min('a', 'b') << std::endl;
  std::cout << min("aaa", "bbb") << std::endl;

  /*
  面白いエラーが出る。
  min(a, b)と修飾なし(名前解決演算子をつけない)で呼ぶと、今いるスコープでminを探す、
  だけで終わらず、引数の型に関連する名前空間・クラスも探索する。
  これがADL(Argument-Dependent Lookup)
  そのため、aとbがstd::stirngの時は、std::名前空間も候補に入る。

  逆にいうと、この仕組みがあるから、std::minと呼ばなくてもminがstd::stringで使える
  */
  std::string a = "aaa";
  std::string b = "bbb";
  //std::cout << min(a, b) << std::endl;
  std::cout << ::min(a, b) << std::endl;


  // 2. クラステンプレート
  std::cout << "2. ---" << std::endl;
  Box<int> ina(10);
  Box<double> inb(3.1415);

  std::cout << ina.get() << std::endl;
  std::cout << inb.get() << std::endl;


  // 3. 特殊化
  std::cout << "3. ---" << std::endl;
  print(10);
  print(3.14);
  print("hello");
  print(std::string("hello string"));

  
  // 4. クラステンプレートの特殊化
  std::cout << "4. ---" << std::endl;
  Printer<double> claa;
  claa.print(4.2);

  Printer<int> clab;
  clab.print(42);

  // 5. 部分特殊化
  std::cout << "5. ---" << std::endl;
  Printer<int> clac;
  clac.print(4222);
  Printer<int*> clad;
  int num = 1337;
  int* num_ptr = &num;
  
  clad.print(num_ptr);

  // 6. factorial おそらく最後にはこれを導入するのだろう
  std::cout << "6. ---" << std::endl;
  std::cout << Factorial<5>::value << std::endl;

  // 7. type trait (STLでよく使う)
  std::cout << "7. ---" << std::endl;
  std::cout << std::boolalpha << is_pointer<int>::value << std::endl;
  std::cout << std::boolalpha << is_pointer<int*>::value << std::endl;
}
