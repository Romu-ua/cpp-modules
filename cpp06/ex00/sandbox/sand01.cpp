// Copyright 2026 hyamamot
#include <iostream>
#include <string>

/*
現代では、namespaceを使う方が多いらしい？
*/

// static util class
class MathUtils {
 public:
  static int add(int a, int b) {
    return a + b;
  }

  static int square(int x) {
    return x * x;
  }

 private:
  // MathUtils() = delete;  // これはc++11以降の書き方
  MathUtils();  // 宣言だけしてリンクエラーとして処理するのがc++98の書き方
};

// cpplint的にはインテンドはいらないらしい。
namespace math_utils {

int add(int a, int b) {
  return a + b;
}

int square(int x) {
  return x * x;
}
}

int main() {
  int result = MathUtils::add(4, 2);
  std::cout << result << std::endl;

  result = math_utils::add(4, 3);
  std::cout << result << std::endl;
}
