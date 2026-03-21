// Copyright 2026 hyamamot
#include <iostream>
#include <string>
#include <map>

class Harl {
  void debug(void);
  void info(void);
  void warning(void);
  void error(void);

 public:
  void complain(std::string level);
};

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
  std::map<std::string, void (Harl::*)(void)> table;

  table["debug"] = &Harl::debug;
  table["info"] = &Harl::info;
  table["warning"] = &Harl::warning;
  table["error"] = &Harl::error;

  std::map<std::string, void (Harl::*)(void)>::iterator it;

  it = table.find(level);
  if (it != table.end()) {
    (this->*(it->second))();
  }
}

int main() {
  Harl harl;

  harl.complain("debug");
  harl.complain("info");
  harl.complain("warning");
  harl.complain("error");
  harl.complain("not command");
}
