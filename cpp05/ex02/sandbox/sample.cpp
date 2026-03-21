// Copyright 2026 hyamamot
#include <iostream>
#include <exception>
#include <string>

// Formクラスが使うものを前方定義
class Bureaucrat;


// Formクラス
class Form {
  const std::string name_;
  bool is_signed_;
  const int signed_grade_;
  const int exec_grade_;

 public:
  Form(std::string name, int signed_grade, int exec_grade)
    : name_(name),
      is_signed_(false),
      signed_grade_(signed_grade),
      exec_grade_(exec_grade) {
    std::cout << "Form constructor" << std::endl;
    if (signed_grade < 1 || exec_grade < 1) {
      throw ;
    } else if  (signed_grade > 150 || exec_grade > 150) {
      throw ;
    }
  }

  std::string getName() const {
    return name_;
  }

  void beSigned(Bureaucrat& b);  // Bureaucrat定義後に実装

  // 例外クラス
  class GradeTooHighException : public std::exception {
    const std::string name_;
    bool is_signed_;
    const int signed_grade_;
    const int exec_grade_;

   public:
    GradeTooHighException(std::string name, bool is_signed, int signed_grade, int exec_grade)
      : name_(name),
        is_signed_(is_signed),
        signed_grade_(signed_grade),
        exec_grade_(exec_grade) {
      std::cout << "GradeTooHighException constrcutor" << std::endl;
    }

    const char* what() const throw() {
      return "Form grade too High";
    }

    friend std::ostream& operator<<(std::ostream& os, const GradeTooHighException& rhs) {
      os << rhs.name_ << ", Form signed grade " << rhs.signed_grade_ << ", exec grade " << rhs.exec_grade_; 
      return os;
    }
  };

  class GradeTooLowException : public std::exception {
    const std::string name_;
    bool is_signed_;
    const int signed_grade_;
    const int exec_grade_;

   public:
    GradeTooLowException(std::string name, bool is_signed, int signed_grade, int exec_grade)
      : name_(name),
        is_signed_(is_signed),
        signed_grade_(signed_grade),
        exec_grade_(exec_grade) {
      std::cout << "GradeTooLowException constrcutor" << std::endl;
    }

    const char* what() const throw() {
      return "Form grade too low";
    }

    friend std::ostream& operator<<(std::ostream& os, const GradeTooLowException& rhs) {
      os << rhs.name_ << ", Form signed grade " << rhs.signed_grade_ << ", exec grade " << rhs.exec_grade_; 
      return os;
    }
  };
};

// Bureaucratクラス
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

  void signForm(Form& form) {
    try {
      form.beSigned(*this);
    } catch (Form::GradeTooLowException& e) {
      std::cout << name_ << " coundn't sign " << form.getName() << " because bureaucrat low grade" << std::endl;
      return;
    }
    std::cout << name_ << " signed " << form.getName() << std::endl;
  }

  // 例外クラス
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

void Form::beSigned(Bureaucrat& b) {
  if (signed_grade_ >= b.getGrade()) {
    is_signed_ = true;
  } else {
    throw GradeTooLowException(name_, is_signed_, signed_grade_, exec_grade_);
  }
}

// Form内でまだ定義していないBureaucaratのメンバ関数を使うので、
// 定義し終わった後にこちらを定義する。
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
