// Copyright 2026 hyamamot
#include <iostream>
#include <string>
#include <map>
#include "include/Harl.hpp"

void Harl::debug(void) {
  std::cout << "debug" << std::endl;
}

void Harl::info(void) {
  std::cout << "info" << std::endl;
}

void Harl::warning(void) {
  std::cout << "warning" << std::endl;
}

void Harl::error(void) {
  std::cout << "error" << std::endl;
}

void Harl::complain(std::string level) {
  std::string names[] = {"debug", "info", "warning", "error"};
  void (Harl::*funcs[])() = {
    &Harl::debug,
    &Harl::info,
    &Harl::warning,
    &Harl::error
  };

  for (int i = 0; i < 4; ++i) {
    if (names[i] == level) {
      (this->*funcs[i])();
      return;
    }
  }
  std::cout << "[" <<  level << "] is unknown level" << std::endl;
}
