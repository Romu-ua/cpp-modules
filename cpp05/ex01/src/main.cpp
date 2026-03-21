// Copyright 2026 hyamamot
#include <iostream>
#include <string>
#include "include/Bureaucrat.hpp"
#include "include/Form.hpp"

int main() {
  // 成功
  try {
    Form form("form1",2, 2);
    Bureaucrat b("admin", 1);

    b.signForm(form);
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  // 失敗
  try {
    Form form("form1",2, 2);
    Bureaucrat b("noob", 150);

    b.signForm(form);
  } catch (Form::GradeTooHighException& e) {
    std::cout << e << std::endl;
  }
}
