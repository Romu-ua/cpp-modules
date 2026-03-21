// Copyright 2026 hyamamot
#include <iostream>
#include <exception>
#include <string>

class Bureaucrat {
  const std::string name_;
  int grade_;
 
 public:
  Bureaucrat(std::string name, int grade) : name_(name), grade_(grade) {
    std::cout << "Bureaucrat constructor" << std::endl;
    if (grade_ < 1) {
      throw GradeTooHighException(name_, grade_);
    } else if  (grade_ > 150) {
      throw GradeTooLowException(name_, grade_);
    }
  }

  std::string getName() const { return name_; }
  int getGrade() const { return grade_; }

  void incrementGrade();
  void decrementGrade();

  class GradeTooHighException : public std::exception {
    const std::string name_;
    int grade_;
    
   public:
    GradeTooHighException(const std::string name, int grade) : name_(name), grade_(grade) {
      std::cout << "GradeToolHighException constructor" << std::endl;
    }

    const char* what() const throw() {
      return "grade too high";
    }

    friend std::ostream& operator<<(std::ostream& os, const GradeTooHighException& rhs) {
      os << rhs.name_ << ", bureaucrat grade " << rhs.grade_;
      return os;
    }
  };

  class GradeTooLowException : public std::exception {
    const std::string name_;
    int grade_;
    
   public:
    GradeTooLowException(const std::string name, int grade) : name_(name), grade_(grade) {
      std::cout << "GradeToolLowException constructor" << std::endl;
    }

    const char* what() const throw() {
      return "grade too low";
    }

    friend std::ostream& operator<<(std::ostream& os, const GradeTooLowException& rhs) {
      os << rhs.name_ << ", bureaucrat grade " << rhs.grade_;
      return os;
    }
  };
};

// インスタンスを作ってthrowする
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

// ここからe.wath()ではなくて、std::cout << e << std::endl
// でエラーを表示できるよう<<をオーバーロードする
int main() {
  //Bureaucrat bureaucrat("admin", 1);

  //try {
  //  bureaucrat.incrementGrade();
  //} catch (Bureaucrat::GradeTooHighException& e) {
  //  std::cout << e.what() << std::endl;
  //} catch (Bureaucrat::GradeTooLowException& e) {
  //  std::cout << e.what() << std::endl;
  //}

  Bureaucrat brueaucrat("noob", 150);
  try {
    brueaucrat.decrementGrade();
  } catch (Bureaucrat::GradeTooHighException& e) {
    std::cout << e << std::endl;
  } catch (Bureaucrat::GradeTooLowException& e) {
    std::cout << e << std::endl;
  }

  Bureaucrat bureaucratAd("admin", 1);
  try {
    bureaucratAd.incrementGrade();
  } catch (Bureaucrat::GradeTooHighException& e) {
    std::cout << e << std::endl;
  } catch (Bureaucrat::GradeTooLowException& e) {
    std::cout << e << std::endl;
  }

  try {
    Bureaucrat nonbureaucrat("non", -1);
  } catch (Bureaucrat::GradeTooHighException& e) {
    std::cout << e << std::endl;
  } catch (Bureaucrat::GradeTooLowException& e) {
    std::cout << e << std::endl;
  }
}
