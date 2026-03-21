// Copyright 2026 hyamamot
#include <iostream>
#include <string>

class Fixed {
  int val_;

 public:
  Fixed();
  Fixed(int val);  // NOLINT
  Fixed(const Fixed& other);
  ~Fixed();

  int get_val() const {
    return val_;
  }
  void set_val(int val) {
    val_ = val;
  }

  // 演算子オーバーロード
  Fixed operator+(const Fixed& rhs) const;
  Fixed operator-(const Fixed& rhs) const;
  Fixed operator*(const Fixed& rhs) const;
  Fixed operator/(const Fixed& rhs) const;
};

Fixed::Fixed() : val_(0) {
  std::cout << "default constructor" << std::endl;
}

Fixed::Fixed(int val) : val_(val) {
  std::cout << "constructor with arguments: val = " << get_val() << std::endl;
}

Fixed::Fixed(const Fixed& other) {
  std::cout << "copy constructor" << std::endl;
  set_val(other.get_val());
}

Fixed::~Fixed() {
  std::cout << "destructor" << std::endl;
}

Fixed Fixed::operator+(const Fixed& rhs) const {
  return Fixed(get_val() + rhs.get_val());
}

Fixed Fixed::operator-(const Fixed& rhs) const {
  return Fixed(get_val() - rhs.get_val());
}

Fixed Fixed::operator*(const Fixed& rhs) const {
  return Fixed(get_val() * rhs.get_val());
}

Fixed Fixed::operator/(const Fixed& rhs) const {
  return Fixed(get_val() / rhs.get_val());
}


int main() {
  // =は、Fixed::Fixed(int val)を呼んでいる。
  Fixed a = 10;
  Fixed b = 20;
  Fixed c = 30;

  std::cout << std::endl;

  Fixed d = a + b;  // 30
  Fixed e = d / c;  // 1
  Fixed f = c - e;  // 29

  // ここの13の整数リテラルは暗黙的にFixedに型変換が行われる。
  Fixed g = f / 13;  // 1

  std::cout << std::endl;

  std::cout << d.get_val() << std::endl;
  std::cout << e.get_val() << std::endl;
  std::cout << f.get_val() << std::endl;
  std::cout << g.get_val() << std::endl;
}
