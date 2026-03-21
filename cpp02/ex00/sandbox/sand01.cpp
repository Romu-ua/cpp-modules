// Copyright 2026 hyamamot
#include <iostream>
#include <string>

#include <bitset>

int main() {
  /*
  参考文献によると、これで固定小数点に変換できる
  1.5_(10) = 1.1_(2)
  1.1_(2) * 10_(2) = 11_(2)
  のようになるため、2の累乗の値をかけると、その分だけ小数点が右にずれる。
  */ 
  int fval = (int)round(1.5 * (1 << 8));

  // 同様に、小数点を左にずらすと整数部分を復元できる
  int n = fval >> 8;

  std::cout << "fval: " << std::bitset<16>(fval) << std::endl;
  std::cout << "n: " << std::bitset<16>(n) << std::endl;

  int fval1 = (int)round(3.5 * (1<<8));
  int fval2 = (int)round(1.25 * (1<<8));

  int n1 = fval1 + fval2;
  int n2 = fval1 - fval2;

  std::cout << "fval1: " << std::bitset<16>(fval1) << std::endl;
  std::cout << "fval2: " << std::bitset<16>(fval2) << std::endl;

  std::cout << "fval1 + fval2: " << std::bitset<16>(n1) << std::endl;
  std::cout << "fval1 - fval2: " << std::bitset<16>(n2) << std::endl;
}
