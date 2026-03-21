// Copyright 2026 hyamamot
#include <iostream>
#include "include/Fixed.hpp"

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
