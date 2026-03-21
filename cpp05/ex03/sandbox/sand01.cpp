// Copyright 2026 hyamamot
#include <iostream>
#include <exception>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>

// Bureaucratの中でAFormの型を使っているので前方宣言
class AForm;

class Bureaucrat {
  const std::string name_;
  int grade_;

 public:
  Bureaucrat(std::string name, int grade) : name_(name), grade_(grade) {
    std::cout << "Bureaucrat constructor" << std::endl;
    if (grade_ < 1) {
      throw GradeTooHighException(name_, grade_);  // Bureaucratのgradeがout of range.
    } else if (grade_ > 150) {
      throw GradeTooLowException(name_, grade_);  // Bureaucratのgradeがout of range.
    }
  }

  ~Bureaucrat() {
    std::cout << "Bureaucrat destructor" << std::endl;
  }

  std::string getName() const { return name_; }
  int getGrade() const { return grade_; }

  void incrementGrade() {
    --grade_;
    if (grade_ < 1) {
      throw GradeTooHighException(name_, grade_);  // out of range.
    }
  }
  void decrementGrade() {
    ++grade_;
    if (grade_ > 150) {
      throw GradeTooLowException(name_, grade_);  //out of range.
    }
  }

  // AFormのメンバ関数を使っているので、AFormを定義した後にこの関数を定義する。
  void signForm(AForm& form);

  class GradeTooHighException : public std::exception {
    const std::string name_;
    int grade_;

   public:
    GradeTooHighException(std::string name, int grade) : name_(name), grade_(grade) {
      std::cout << "GradeTooHighException constructor" << std::endl;
    }

    ~GradeTooHighException() throw() {
      std::cout << "GradeTooHighException destructor" << std::endl;
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
    GradeTooLowException(std::string name, int grade) : name_(name), grade_(grade) {
      std::cout << "GradeTooLowException constructor" << std::endl;
    }

    ~GradeTooLowException() throw() {
      std::cout << "GradeTooLowException destructor" << std::endl;
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


class AForm {
  const std::string name_;
  bool is_signed_;
  const int signed_grade_;
  const int exec_grade_;

 public:
  AForm(std::string name, int signed_grade, int exec_grade)
    :name_(name), is_signed_(false), signed_grade_(signed_grade), exec_grade_(exec_grade)  {
    std::cout << "AForm constructor" << std::endl;
    if (signed_grade < 1 || exec_grade < 1) {
      throw GradeTooHighException(name_, is_signed_, signed_grade_, exec_grade_); // AFormのgradeがout of range
    } else if (signed_grade > 150 || exec_grade > 150) {
      throw GradeTooLowException(name_, is_signed_, signed_grade_, exec_grade_); // AFormのgradeがout of range
    }
  }
  ~AForm() {
    std::cout << "AForm destructor" << std::endl;
  }

  std::string getName() const { return name_; }
  bool getIsSigned() const { return is_signed_; }
  int getSignedGrage() const { return signed_grade_; }
  int getExecGrade() const { return exec_grade_; }

  void beSigned(Bureaucrat& b) {
    if (signed_grade_ >= b.getGrade()) {
      is_signed_ = true;
    } else {
      throw GradeTooLowException(name_, is_signed_, signed_grade_, exec_grade_);
    }
  }

  virtual void execute(Bureaucrat const& executor) const = 0;

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
    ~GradeTooHighException() throw() {
      std::cout << "GradeTooHighException destructor" << std::endl;
    }

    const char* what() const throw() {
      return "Form grade too High";
    }

    friend std::ostream& operator<<(std::ostream& os, const GradeTooHighException& rhs) {
      os << rhs.name_ << ", is_signed " << rhs.is_signed_ << ", signed grade " << rhs.signed_grade_ << ", exec grade " << rhs.exec_grade_; 
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

    ~GradeTooLowException() throw() {
      std::cout << "GradeTooLowException destructor" << std::endl;
    }

    const char* what() const throw() {
      return "Form grade too low";
    }

    friend std::ostream& operator<<(std::ostream& os, const GradeTooLowException& rhs) {
      os << rhs.name_ << ", is_signed " << rhs.is_signed_ << ", signed grade " << rhs.signed_grade_ << ", exec grade " << rhs.exec_grade_; 
      return os;
    }
  };
};


void Bureaucrat::signForm(AForm& form) {
  try {
      form.beSigned(*this);
    } catch (AForm::GradeTooLowException& e) {  // Fromのgradeが高すぎるという意味でHighの方の例外を返している
      std::cout << name_ << " coundn't sign " << form.getName() << " because bureaucrat grade is low than form." << std::endl;
      return;
    }
    std::cout << name_ << " signed " << form.getName() << std::endl;
}

// AFormの派生クラス
class ShrubberyCreationForm : public AForm {
  std::string target_;

 public:
  explicit ShrubberyCreationForm(std::string target) : AForm(target, 145, 137) {
    std::cout << "ShrubberyCreationForm constructor" << std::endl;
  }

  ~ShrubberyCreationForm() {
    std::cout << "ShrhbberyCreateionForm destructor" << std::endl;
  }

  void execute(Bureaucrat const& executor) const;
};

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
  if (executor.getGrade() > getSignedGrage()) {
    throw GradeTooLowException(getName(), getIsSigned(), getSignedGrage(), getExecGrade());
  }
  std::string filename = getName() + "_shrubbery";
  std::ofstream file(filename);
  file << "this is test ascii tree." << std::endl;
}

class RobotomyRequestForm: public AForm {
  std::string target_;

 public:
  explicit RobotomyRequestForm(std::string target) : AForm(target, 72, 45) {
    std::cout << "RobotomyRequestForm constructor" << std::endl;
  }
  ~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm destructor" << std::endl;
  }

  void execute(Bureaucrat const& executor) const;
};

void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
  std::cout << "drilling noises" << std::endl;
  srand(time(NULL));
  if (rand() % 2) {
    std::cout << "successfully" << std::endl;
  } else {
    std::cout << "failed" << std::endl;
  }
}

class PresidentialPardonForm: public AForm {
  std::string target_;

 public:
  explicit PresidentialPardonForm(std::string target) : AForm(target, 25, 5) {
    std::cout << "PresidentialPardonForm constructor" << std::endl;
  }
  ~PresidentialPardonForm() {
    std::cout << "PresidentialPardonForm destructor" << std::endl;
  }

  void execute(Bureaucrat const& executor) const;
};

void PresidentialPardonForm::execute(Bureaucrat const& executor) const {
  std::cout << getName() << " is pardoned by Zaphod Beeblebrox" << std::endl;
}


// -- Intern クラス --

AForm* createShrubbery(std::string target) {
  return new ShrubberyCreationForm(target);
}
AForm* createRobotomy(std::string target) {
  return new RobotomyRequestForm(target);
}
AForm* createPresidential(std::string target) {
  return new PresidentialPardonForm(target);
}


class Intern {
 public:
  Intern() {
    std::cout << "Intern constructor" << std::endl;
  }
  ~Intern() {
    std::cout << "intern destructor" << std::endl;
  }

  AForm* makeForm(std::string name, std::string target);
};

AForm* Intern::makeForm(std::string name, std::string target) {
  if (name.empty()) {
    std::cout << "name is empty." << std::endl;
    return NULL;
  }
  std::string names[3] = {
    "ShrubberyCreationForm",
    "RobotomyRequestForm",
    "PresidentialPardonForm"
  };
  
  AForm* (*forms[3])(std::string) =  {
    createShrubbery,
    createRobotomy,
    createPresidential,
  };

  for (int i = 0; i < 3; ++i) {
    if (name == names[i]) {
      std::cout << "Intern create form " << names[i] << std::endl;
      return forms[i](target);
    }
  }
  return NULL;
}


int main() {
  Bureaucrat admin("admin", 1);
  try {
    admin.incrementGrade();
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << "-- derived class --" << std::endl;
  ShrubberyCreationForm shrubbery_form("shrubbery");
  try {
    shrubbery_form.execute(admin);
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  RobotomyRequestForm robotomy_form("robotomy");
  try {
    robotomy_form.execute(admin);
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  PresidentialPardonForm presidential_form("president");
  try {
    presidential_form.execute(admin);
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << "-- Intern class --" << std::endl;
  Intern intern;
  AForm *rrf;

  rrf = intern.makeForm("ShrubberyCreationForm", "Bender");
  std::cout << "form name is " << rrf->getName() << std::endl;
  
  std::cout << "------------------" << std::endl;
}
