// Copyright 2026 hyamamot
#include <iostream>
#include <string>

/*
<< は演算子で、
operator(std::cout, a);
が呼ばれる。

std::cout << a << b;
のように連続しているとき、
std::cout << a
=> operator<<(std::cout, a)
次の << bを続けるために、operatorはostream&を返す必要がある
*/
class Fixed {
  static const int fractional_ = 8;
  int raw_;

 public:
  Fixed();
  explicit Fixed(int raw);
  explicit Fixed(float raw);
  Fixed(const Fixed& other);
  ~Fixed();

  Fixed& operator=(const Fixed& rhs);

  Fixed operator+(const Fixed& rhs) const;
  Fixed operator-(const Fixed& rhs) const;
  Fixed operator*(const Fixed& rhs) const;
  Fixed operator/(const Fixed& rhs) const;

  friend std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

  int getRawBits(void) const;
  void setRawBits(int const raw);

  float toFloat(void) const;
  int toInt(void) const;
};

int Fixed::getRawBits() const {
  return raw_;
}

void Fixed::setRawBits(int const raw) {
  raw_ = raw;
}


Fixed::Fixed() : raw_(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int raw) {
  std::cout << "constructor with arguments (int)" << std::endl;
  raw_ = raw << Fixed::fractional_;
}

Fixed::Fixed(float raw) {
  std::cout << "constructor with arguments (float)" << std::endl;
  setRawBits(static_cast<int>(roundf(raw * (1 << Fixed::fractional_))));
}

Fixed::Fixed(const Fixed& other) {
  std::cout << "Copy constructor called" << std::endl;
  setRawBits(other.getRawBits());
}

Fixed::~Fixed() {
  std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& rhs) {
  std::cout << "Copy assignment operator called" << std::endl;
  setRawBits(rhs.getRawBits());
  return *this;
}

Fixed Fixed::operator+(const Fixed& rhs) const {
  return Fixed(getRawBits() + rhs.getRawBits());
}

Fixed Fixed::operator-(const Fixed& rhs) const {
  return Fixed(getRawBits() - rhs.getRawBits());
}

Fixed Fixed::operator*(const Fixed& rhs) const {
  return Fixed(getRawBits() * rhs.getRawBits());
}
Fixed Fixed::operator/(const Fixed& rhs) const {
  return Fixed(getRawBits() / rhs.getRawBits());
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
  os << fixed.toFloat();
  return os;
}

float Fixed::toFloat(void) const {
  return static_cast<float>(getRawBits()) / (1<<fractional_);
}

int Fixed::toInt(void) const {
  return getRawBits() >> fractional_;
}


int main() {
  Fixed a;
  Fixed const b(10);
  Fixed const c(42.42f);
  Fixed const d(b);

  a = Fixed(1234.4321f);

  std::cout << "a is " << a << std::endl;
  std::cout << "b is " << b << std::endl;
  std::cout << "c is " << c << std::endl;
  std::cout << "d is " << d << std::endl;

  std::cout << "a is " << a.toInt() << " as integer" << std::endl;
  std::cout << "b is " << b.toInt() << " as integer" << std::endl;
  std::cout << "c is " << c.toInt() << " as integer" << std::endl;
  std::cout << "d is " << d.toInt() << " as integer" << std::endl;
}
