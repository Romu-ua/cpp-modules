// Copyright 2026 hyamamot
#ifndef CPP01_EX05_INCLUDE_HPP_
#define CPP01_EX05_INCLUDE_HPP_

#include <string>

class Harl {
  void debug(void);
  void info(void);
  void warning(void);
  void error(void);

 public:
  void complain(std::string level);
};

#endif  // CPP01_EX05_INCLUDE_HPP_
