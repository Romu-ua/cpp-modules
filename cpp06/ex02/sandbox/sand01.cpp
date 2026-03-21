// Copyright 2026 hyamamot
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

class Base {
 public:
  virtual ~Base() {}
};

class A : public Base {
};

class B : public Base {
};

class C : public Base {
};

Base* generate() {
  std::srand(std::time(NULL));
  int r = std::rand() % 3;
  
  Base* base;
  if (r == 0) {
    base = new A;
    return base;
  } else if (r == 2) {
    base = new B;
  } else {
    base = new C;
  }
  
  return base;
}

void identify(Base* base) {
  if (dynamic_cast<A*>(base)) {
    std::cout << "A" << std::endl;
  } else if (dynamic_cast<B*>(base)) {
    std::cout << "B" << std::endl;
  } else {
    std::cout << "C" << std::endl;
  }
}

int main() {
  Base* base = generate();

  // RTTIを学習させたいのだと思う。
  identify(base);
}
