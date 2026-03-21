// Copyright 2026 hyamamot
#include <iostream>
#include <string>

class Fixed {
  static const int fractional_ = 8;
  int raw_;

 public:
  Fixed();
  explicit Fixed(int raw);
  Fixed(const Fixed& other);
  ~Fixed();

  void operator=(const Fixed& rhs);
  Fixed operator+(const Fixed& rhs) const;
  Fixed operator-(const Fixed& rhs) const;
  Fixed operator*(const Fixed& rhs) const;
  Fixed operator/(const Fixed& rhs) const;

  int getRawBits(void) const;
  void setRawBits(int const raw);
};

int Fixed::getRawBits() const {
  std::cout << "getRawBits member function called" << std::endl; 
  return raw_;
}

void Fixed::setRawBits(int const raw) {
  raw_ = raw;
}

Fixed::Fixed() : raw_(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int raw) : raw_(raw) {
  std::cout << "constructor with arguments" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
  std::cout << "Copy constructor called" << std::endl;
  setRawBits(other.getRawBits());
}

Fixed::~Fixed() {
  std::cout << "Destructor called" << std::endl;
}

void Fixed::operator=(const Fixed& rhs) {
  std::cout << "Copy assignment operator called" << std::endl;
  setRawBits(rhs.getRawBits());

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

int main() {
  Fixed a;
  Fixed b(a);
  Fixed c;

  c = b;

  std::cout << a.getRawBits() << std::endl;
  std::cout << b.getRawBits() << std::endl;
  std::cout << c.getRawBits() << std::endl;
}
