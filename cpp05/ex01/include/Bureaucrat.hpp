// Copyright 2026 hyamamot
#ifndef CPP05_EX01_INCLUDE_BUREAUCRAT_HPP_
#define CPP05_EX01_INCLUDE_BUREAUCRAT_HPP_

#include <string>
#include <exception>
#include "include/Form.hpp"

class Form;

class Bureaucrat {
  const std::string name_;
  int grade_;

 public:
  Bureaucrat(std::string name, int grade);
  
  std::string getName() const;
  int getGrade() const;

  void incrementGrade();
  void decrementGrade();

  void signForm(Form& form);

  class GradeTooHighException : public std::exception {
    const std::string name_;
    int grade_;

   public:
    GradeTooHighException(const std::string name, int grade);
    ~GradeTooHighException() throw();

    const char* what() const throw();
    friend std::ostream& operator<<(
      std::ostream& os,
      const GradeTooHighException& rhs);
  };

  class GradeTooLowException : public std::exception {
    const std::string name_;
    int grade_;

   public:
    GradeTooLowException(const std::string name, int grade);
    ~GradeTooLowException() throw();
    const char* what() const throw();
    friend std::ostream& operator<<(
      std::ostream& os,
      const GradeTooLowException& rhs);
  };
};

#endif  // CPP05_EX01_INCLUDE_BUREAUCRAT_HPP_
