// Copyright 2026 hyamamot
#include <iostream>
#include <string>
#include <cstdlib>

// C#などのstatic classのイディオムなのか。
class ScalarConverter {
 public:
  static void convert(std::string str);
};

enum Type {
  CHAR,
  INT,
  FLOAT,
  DOUBLE,
  INVALID
};

// asciiで0 ~ 32と127は入力されないので、sizeが1のものはそのまま返して良い。
// 1文字の数字と1文字のcharの違いはどうやってつけるのか？
// 一旦、charはisalphaで実装する。
bool isChar(std::string& str) {
  if (str.size() != 1) {
    return false;
  }
  if (isalpha(str[0])) {
    return true;
  }
  return false;
}

// オーバーフローの対応もしなくてはいけない。
// ここは単なる判定のところなので、オーバーフロー実際に変換するところで対処する。
bool isInt(std::string& str) {
  for (int i = 0; i < str.size(); ++i) {
    if (!isdigit(str[i])) {
      return false;
    }
  }
  return true;
}


bool isFloat(std::string str) {
  int count_comma = 0;

  for (int i = 0; i < str.size() - 1; ++i) {
    if (!isdigit(str[i])) {
      return false;
    } else if (str[i] == '.') {
      ++count_comma;
      continue;
    }
  }

  if (count_comma == 1 && str[str.size() - 1] == 'f') {
    return true;
  }
  return false;
}

bool isDouble(std::string str) {
  int count_comma = 0;
  for (int i = 0; i < str.size(); ++i) {
    if (!isdigit(str[i])) {
      return false;
    } else if (str[i] == '.') {
      ++count_comma;
      continue;
    }
  }
  
  if (count_comma == 1) {
    return true;
  }
  return false;
}


Type checkType(std::string& str) {
  if (isChar(str)) {
    return CHAR;
  } else if (isInt(str)) {
    return INT;
  } else if (isFloat(str)) {
    return FLOAT;
  } else if (isDouble(str)) {
    return DOUBLE;
  } else {
    return INVALID;
  }
}

void ScalarConverter::convert(std::string str) {
  // intかつfloatみたいなパターンもあるよね？
  // それは考慮していない。if-elseに最初に引っかかったものを採用
  // pdfに書いてある「first detect tye type of the literal」を実装
  Type t = checkType(str);
  char c;
  int i;
  float f;
  double d;
  bool is_invalid = false;

  // 実際の型に変換しているところ
  if (t == Type::CHAR) {
    c = static_cast<char>(str[0]);
  } else if (t == Type::INT) {
    i = atoi(str.c_str());
  } else if (t == Type::FLOAT) {
    f = (float)strtod(str.c_str(), NULL);
  } else if (t == Type::DOUBLE) {
    d = atof(str.c_str());
  } else {
    // invalid case
    is_invalid = true;
  }
  
  // 明示的に残りの3つのリテラルに変換するところ

}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    return 1;
  }
  std::string str = argv[1];
  ScalarConverter::convert(str);
}

// doubleに変換した後に、他の方にcastしたほうが簡単らしい。
