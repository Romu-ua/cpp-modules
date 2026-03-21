// Copyright 2026 hyamamot
#include <iostream>
#include <exception>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>

// Formクラスが使うものを前方定義
class Bureaucrat;


// Formクラス
class AForm {
  const std::string name_;
  bool is_signed_;
  const int signed_grade_;
  const int exec_grade_;

 public:
  AForm(std::string name, int signed_grade, int exec_grade)
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
  bool getIsSigned() const {
    return is_signed_;
  }
  int getSignedGrade() const {
    return signed_grade_;
  }
  int getExecGrade() const {
    return exec_grade_;
  }

  void beSigned(Bureaucrat& b);  // Bureaucrat定義後に実装

  // ex03で追加
  // これでAFormが抽象クラスになった。
  virtual void execute(Bureaucrat const& executor) const = 0;

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

  void signForm(AForm& form) {
    try {
      form.beSigned(*this);
    } catch (AForm::GradeTooLowException& e) {
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

void AForm::beSigned(Bureaucrat& b) {
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


// ex02で新しく追加する具象クラス

class ShrubberyCreationForm : public AForm {
  std::string target_;

 public:
  explicit ShrubberyCreationForm(std::string target) : AForm(target, 145, 137) {
    std::cout << "ShrubberyCreationForm constructor" << std::endl;
  }

  void execute(Bureaucrat const& executor) const;
};

// working directoryにファイルを作成して、ASCII treeをファイルの中に書き込む。
// これは自分でアルゴリズムを実装しないといけないのか？
// AFormにgetterとsetterを用意しないといけないわ。
// FormかBureaucratかどちらの例外を使えば良いのだ？
// 例外処理の引数を見直す必要がある。コピーコンストラクタにする方が良いのではないか。
void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
  if (executor.getGrade() > getSignedGrade()) {
    throw GradeTooLowException(getName(), getIsSigned(), getSignedGrade(), getExecGrade());
  }
  std::string filename = getName() + "_shrubbery";
  std::ofstream file(filename);
  // このファイルの中にディレクトリのtreeを作成しなければならないが。
  file << "this is test ascii tree." << std::endl;
}


class RobotomyRequestForm: public AForm {
  std::string target_;

 public:
  explicit RobotomyRequestForm(std::string target) : AForm(target, 72, 45) {
    std::cout << "RobotomyRequestForm constructor" << std::endl;
  }

  void execute(Bureaucrat const& executor) const;
};

void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
  std::cout << "drilling noises" << std::endl;
  srand(time(NULL));  // 乱数初期化
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

  void execute(Bureaucrat const& executor) const;
};

void PresidentialPardonForm::execute(Bureaucrat const& executor) const {
  std::cout << getName() << " is pardoned by Zaphod Beeblebrox" << std::endl;
}


int main() {
}
// ゴチャついてきたので、修正も兼ねて整理し直す。
