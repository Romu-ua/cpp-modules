// Copyright 2026 hyamamot
#include <iostream>
#include <string>
#include "include/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade)
  : name_(name), grade_(grade) {
  std::cout << "Bureaucrat constructor" << std::endl;
  if (grade_ < 1) {
    throw GradeTooHighException(name_, grade_);
  } else if (grade_ > 150) {
    throw GradeTooLowException(name_, grade_);
  }
}

std::string Bureaucrat::getName() const {
  return name_;
}

int Bureaucrat::getGrade() const {
  return grade_;
}

void Bureaucrat::incrementGrade() {
  --grade_;
  if (grade_ < 1) {
    throw GradeTooHighException(name_, grade_);
  }
}

void Bureaucrat::decrementGrade() {
  ++grade_;
  if (grade_ > 150) {
    throw GradeTooLowException(name_, grade_);
  }
}

// 例外クラス GradeTooHighExceptionの定義
Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string name, int grade) 
  : name_(name), grade_(grade) {
    std::cout << "GradeToolHighException constructor" << std::endl;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {
  std::cout << "GradeTooHighException destructor" << std::endl;
}

// whatがnoexceptなのは定義より。
// 理由は、例外処理中の例外を外に出さないため
// これはオーバーライドしなくても良いが、基本はこれなので、レビューで注意されたら消す。
const char* Bureaucrat::GradeTooHighException::what() const throw() {
  return "grade too high";
}

std::ostream& operator<<(
  std::ostream& os,
  const Bureaucrat::GradeTooHighException& rhs) {
  os << rhs.name_ << ", bureaucrat grade " << rhs.grade_;
  return os;
}


// 例外クラス GradeToolLowException
Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string name, int grade) 
  : name_(name), grade_(grade) {
    std::cout << "GradeToolLowException constructor" << std::endl;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {
  std::cout << "GradeTooLowException destructor" << std::endl;
}

// whatがnoexceptなのは定義より。
// 理由は、例外処理中の例外を外に出さないため
// これはオーバーライドしなくても良いが、基本はこれなので、レビューで注意されたら消す。
const char* Bureaucrat::GradeTooLowException::what() const throw() {
  return "grade too low";
}

std::ostream& operator<<(
  std::ostream& os,
  const Bureaucrat::GradeTooLowException& rhs) {
  os << rhs.name_ << ", bureaucrat grade " << rhs.grade_;
  return os;
}
