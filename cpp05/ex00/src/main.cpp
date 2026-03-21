// Copyright 2026 hyamamot
#include <iostream>
#include <string>
#include "include/Bureaucrat.hpp"

int main() {
  std::cout << "test1" << std::endl;
  try {
    Bureaucrat b1("admin", 1);
    b1.incrementGrade();
  } catch (Bureaucrat::GradeTooHighException& e) {
    std::cout << e << std::endl;
  } catch (Bureaucrat::GradeTooLowException& e) {
    std::cout << e << std::endl;
  }

  std::cout << "test2" << std::endl;
  try {
    Bureaucrat b1("noob", 150);
    b1.decrementGrade();
  } catch (Bureaucrat::GradeTooHighException& e) {
    std::cout << e << std::endl;
  } catch (Bureaucrat::GradeTooLowException& e) {
    std::cout << e << std::endl;
  }

  std::cout << "test3" << std::endl;
  /*
  operator<<がstd::exception&では使えないのは、それぞれの例外クラスはstd::exceptionから
  派生しており、std::exceptionにはoperator<<が定義されていないから。
  一方,virtual whatで定義されているので、オーバーライドされ、それぞれの例外クラスのwhatが使える
  */
  try {
    Bureaucrat b1("admin", 1);
    b1.incrementGrade();
  } catch (std::exception& e) {
    //std::cout << e << std::endl;
    std::cout << e.what() << std::endl;
  }

  std::cout << "test4" << std::endl;
  try {
    Bureaucrat b1("noob", 150);
    b1.decrementGrade();
  } catch (std::exception& e) {
    //std::cout << e << std::endl;
    std::cout << e.what() << std::endl;
  }
}
