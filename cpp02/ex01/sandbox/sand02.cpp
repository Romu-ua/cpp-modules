// Copyright 2026 hyamamot

#include <iostream>

class Fixed {
 int rawValue;

 public:
  Fixed(int v) : rawValue(v) {}
  int getRawValue() const {
    return rawValue;
  }
};

std::ostream& operator<<(std::ostream& os, const Fixed& f) {
  os << f.getRawValue();
  return os;
}

int main() {
  Fixed a(42);
  std::cout << a << std::endl;
}
