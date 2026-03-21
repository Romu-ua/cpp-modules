// Copyright 2026 hyamamot
#include <iostream>
#include "include/Fixed.hpp"

int Fixed::getRawBits() const {
  return raw_;
}

void Fixed::setRawBits(int const raw) {
  raw_ = raw;
}

Fixed::Fixed() : raw_(0) {}

Fixed::Fixed(const int raw) {
  raw_ = raw << Fixed::fractional_;
}

Fixed::Fixed(const float raw) {
  setRawBits(static_cast<int>(roundf(raw * (1 << Fixed::fractional_))));
}

Fixed::Fixed(const Fixed& other) {
  *this = other;
}

Fixed::~Fixed() {
}

Fixed& Fixed::operator=(const Fixed& rhs) {
  setRawBits(rhs.getRawBits());
  return *this;
}

Fixed Fixed::operator+(const Fixed& rhs) const {
  Fixed result;
  result.setRawBits(this->getRawBits() + rhs.getRawBits());
  return result;
}

Fixed Fixed::operator-(const Fixed& rhs) const {
  Fixed result;
  result.setRawBits(this->getRawBits() - rhs.getRawBits());
  return result;
}

Fixed Fixed::operator*(const Fixed& rhs) const {
  Fixed result;
  long tmp = this->getRawBits() * rhs.getRawBits();
  result.setRawBits(tmp >> Fixed::fractional_);
  return result;
}

Fixed Fixed::operator/(const Fixed& rhs) const {
  Fixed result;
  double tmp = this->getRawBits() << Fixed::fractional_;
  result.setRawBits(tmp / rhs.getRawBits());
  return result;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
  os << fixed.toFloat();
  return os;
}

Fixed& Fixed::operator++() {
  ++raw_;
  return *this;
}

Fixed& Fixed::operator--() {
  --raw_;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed tmp = *this;
  ++*this;
  return tmp;
}

Fixed Fixed::operator--(int) {
  Fixed tmp = *this;
  --*this;
  return tmp;
}

bool Fixed::operator==(const Fixed& rhs) const {
  return raw_ == rhs.getRawBits();
}

bool Fixed::operator!=(const Fixed& rhs) const {
  return !(*this == rhs);
}

bool Fixed::operator<(const Fixed& rhs) const {
  return raw_ < rhs.getRawBits();
}

bool Fixed::operator>(const Fixed& rhs) const {
  return rhs < *this;
}

bool Fixed::operator<=(const Fixed& rhs) const {
  return !(rhs < *this);
}

bool Fixed::operator>=(const Fixed& rhs) const {
  return !(*this < rhs);
}


float Fixed::toFloat(void) const {
  return static_cast<float>(getRawBits()) / (1<<fractional_);
}

int Fixed::toInt(void) const {
  return getRawBits() >> fractional_;
}


Fixed& Fixed::min(Fixed& lhs, Fixed& rhs) {
  if (lhs < rhs) {
    return lhs;
  } else {
    return rhs;
  }
}

const Fixed& Fixed::min(const Fixed& lhs, const Fixed& rhs) {
  if (lhs < rhs) {
    return lhs;
  } else {
    return rhs;
  }
}

Fixed& Fixed::max(Fixed& lhs, Fixed& rhs) {
  if (lhs < rhs) {
    return rhs;
  } else {
    return lhs;
  }
}

const Fixed& Fixed::max(const Fixed& lhs, const Fixed& rhs) {
  if (lhs < rhs) {
    return rhs;
  } else {
    return lhs;
  }
}
