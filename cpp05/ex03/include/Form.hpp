// Copyright 2026 hyamamot
#ifndef CPP05_EX01_INCLUDE_FORM_HPP_
#define CPP05_EX01_INCLUDE_FORM_HPP_

#include <string>
#include "include/Bureaucrat.hpp"

class Bureaucrat;

class Form {
  const std::string name_;
  bool is_signed_;
  const int signed_grade_;
  const int exec_grade_;

 public:
  Form(std::string name, int signed_grade, int exec_grade);

  std::string getName() const;
  void beSigned(Bureaucrat& b);

  class GradeTooHighException : public std::exception {
    const std::string name_;
    bool is_signed_;
    const int signed_grade_;
    const int exec_grade_;

   public:
    GradeTooHighException(
      std::string name,
      bool is_signed,
      int signed_grade,
      int exec_grade);
    ~GradeTooHighException() throw();
    const char* what() const throw();

    friend std::ostream& operator<<(
      std::ostream&os,
      const GradeTooHighException& rhs);
  };

  class GradeTooLowException : public std::exception {
    const std::string name_;
    bool is_signed_;
    const int signed_grade_;
    const int exec_grade_;

   public:
    GradeTooLowException(
      std::string name,
      bool is_signed,
      int signed_grade,
      int exec_grade);
    ~GradeTooLowException() throw();
    const char* what() const throw();

    friend std::ostream& operator<<(
      std::ostream&os,
      const GradeTooLowException& rhs);
  };
};

#endif  //  CPP05_EX01_INCLUDE_FORM_HPP_
