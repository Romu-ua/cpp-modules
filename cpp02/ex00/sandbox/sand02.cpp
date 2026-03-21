// Copyright 2026 hyamamot
#include <iostream>
#include <string>

/*
演算子オーバーロードを使わない場合
*/
class Fixed {
  int val_;

 public:
  Fixed();
  Fixed(int val);  // NOLINT

  ~Fixed();
  Fixed(const Fixed& other);

  int get_val() {
    return val_;
  }

  Fixed add(const Fixed& other) const {
    return Fixed(val_ + other.val_);
  }
  Fixed sub(const Fixed& other) const {
    return Fixed(val_ - other.val_);
  }
  Fixed mul(const Fixed& other) const {
    return Fixed(val_ * other.val_);
  }
  Fixed div(const Fixed& other) const {
    return Fixed(val_ / other.val_);
  }
};

Fixed::Fixed() : val_(0) {
  std::cout << "call default constructor: set val = 0" << std::endl;
}

Fixed::Fixed(int val) : val_(val) {
  std::cout << "call constructor with arguments: set val = "
            << val
            << std::endl;
}

Fixed::~Fixed() {
  std::cout << "call destructor" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
  std::cout << "call copy constructor" << std::endl;
  val_ = other.val_;
}

int main() {
  Fixed fixed1;
  Fixed fixed2(42);
  Fixed copy(fixed2);  // NOLINT

  // returnするたびにfixedのコンストラクターが呼ばれている。
  fixed1 = fixed1.add(fixed2);  // 0 + 42 = 42;
  std::cout << fixed1.get_val() << std::endl;
  fixed1 = fixed1.sub(fixed2);  // 42 - 42 = 0;
  std::cout << fixed1.get_val() << std::endl;
  fixed2 = fixed2.mul(fixed2);  // 42 * 42 = 1764;
  std::cout << fixed2.get_val() << std::endl;
  fixed2 = fixed2.div(fixed2);  // 1764 / 1763 = 1;
  std::cout << fixed2.get_val() << std::endl;
}
