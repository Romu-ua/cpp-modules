// Copyright 2026 hyamamot
#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>


class ScalarConverter {
 public:
  static void convert(std::string& str);

 private:
  ScalarConverter();
};

/*
数値型の広さ
char < int < float < double
より、doubleに変換してから各literalに変換すれば良い
*/
void ScalarConverter::convert(std::string& str) {
  char* endptr;
  double val = strtod(str.c_str(), &endptr);

  // [debug]
  std::cout << "val: " << val << std::endl;
  std::cout << "endptr: " << endptr << std::endl;
  
  // nanの性質で「自分自身と等しくない」がある。
  bool is_nan = (val != val);
  if (is_nan) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << static_cast<float>(val) << std::endl;
    std::cout << "double: " << static_cast<double>(val) << std::endl;
    return;
  }

  if (str.size() == 1 && isalpha(str[0])) {
    char c = static_cast<char>(str[0]);

    std::cout << "char: " << c << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
  } else {
    char c = static_cast<char>(val);
    int i = static_cast<int>(val);
    float f = static_cast<float>(val);
    double d = val;

    if (c > 23 && c < 127) {
      std::cout << "char: " << c << std::endl;
    } else {
      std::cout << "char: Non displayable" << std::endl;
    }
    std::cout << "int: " << i << std::endl;
    std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f" << std::endl;
    std::cout << std::fixed << std::setprecision(1) << "double: " << d << std::endl;
  }
}


int main(int argc, char *argv[]) {
  if (argc != 2)
    return 1;

  std::string str = argv[1];
  ScalarConverter::convert(str);
}
