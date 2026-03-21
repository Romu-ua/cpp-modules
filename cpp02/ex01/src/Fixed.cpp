// Copyright 2026 hyamamot
#include <iostream>
#include "include/Fixed.hpp"

int Fixed::getRawBits() const {
  return raw_;
}

void Fixed::setRawBits(int const raw) {
  raw_ = raw;
}

Fixed::Fixed() : raw_(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int raw) {
  std::cout << "Int constructor called" << std::endl;
  raw_ = raw << Fixed::fractional_;
}

Fixed::Fixed(const float raw) {
  std::cout << "Float constructor called" << std::endl;
  setRawBits(static_cast<int>(roundf(raw * (1 << Fixed::fractional_))));
}

Fixed::Fixed(const Fixed& other) {
  std::cout << "Copy constructor called" << std::endl;
  *this = other;
}

Fixed::~Fixed() {
  std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& rhs) {
  std::cout << "Copy assignment operator called" << std::endl;
  setRawBits(rhs.getRawBits());
  return *this;
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
