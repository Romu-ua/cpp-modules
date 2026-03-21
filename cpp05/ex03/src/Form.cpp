// Copyright 2026 hyamamot
#include <iostream>
#include <string>
#include "include/Form.hpp"
#include "include/Bureaucrat.hpp"

Form::Form(std::string name, int signed_grade, int exec_grade)
  : name_(name),
    is_signed_(false),
    signed_grade_(signed_grade),
    exec_grade_(exec_grade) {
  std::cout << "Form constructor" << std::endl;
  if (signed_grade < 1 || exec_grade < 1) {
    throw GradeTooLowException(name_, is_signed_, signed_grade_, exec_grade_);
  } else if (signed_grade > 150 || exec_grade > 150) {
    throw GradeTooHighException(name_, is_signed_, signed_grade_, exec_grade_);
  }
}


std::string Form::getName() const {
  return name_;
}

// Formのgradeの方が高いのでHighを返すのかな？
void Form::beSigned(Bureaucrat& b) {
  if (signed_grade_ >= b.getGrade()) {
    is_signed_ = true;
  } else {
    throw GradeTooHighException(name_, is_signed_, signed_grade_, exec_grade_);
  }
} 

// 例外クラス
Form::GradeTooHighException::GradeTooHighException(
  std::string name,
  bool is_signed,
  int signed_grade,
  int exec_grade)
  : name_(name),
    is_signed_(is_signed),
    signed_grade_(signed_grade),
    exec_grade_(exec_grade) {
  std::cout << "GradeTooHighException constrcutor" << std::endl;
}

Form::GradeTooHighException::~GradeTooHighException() throw() {
  std::cout << "GradeTooHighException destructor" << std::endl;
}

const char* Form::GradeTooHighException::what() const throw() {
  return "Form grade too high";
}

std::ostream& operator<<(
  std::ostream& os,
  const Form::GradeTooHighException& rhs) {
  os << rhs.name_
     << ", Form is singed "
     << rhs.is_signed_
     << ", Form signed grade "
     << rhs.signed_grade_
     << ", exec grade "
     << rhs.exec_grade_; 
  return os;
}


Form::GradeTooLowException::GradeTooLowException(
  std::string name,
  bool is_signed,
  int signed_grade,
  int exec_grade)
  : name_(name),
    is_signed_(is_signed),
    signed_grade_(signed_grade),
    exec_grade_(exec_grade) {
  std::cout << "GradeTooLowException constrcutor" << std::endl;
}

Form::GradeTooLowException::~GradeTooLowException() throw() {
  std::cout << "GradeTooLowException destructor" << std::endl;
}

const char* Form::GradeTooLowException::what() const throw() {
  return "Form grade too low";
}

std::ostream& operator<<(
  std::ostream& os,
  const Form::GradeTooLowException& rhs) {
  os << rhs.name_
     << ", Form is singed "
     << rhs.is_signed_
     << ", Form signed grade "
     << rhs.signed_grade_
     << ", exec grade "
     << rhs.exec_grade_; 
  return os;
}
