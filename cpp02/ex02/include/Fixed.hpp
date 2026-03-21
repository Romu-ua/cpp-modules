// Copyright 2026 hyamamot
#ifndef EX02_INCLUDE_FIXED_H_
#define EX02_INCLUDE_FIXED_H_

#include <string>

class Fixed {
  static const int fractional_ = 8;
  int raw_;

 public:
  Fixed();
  explicit Fixed(const int raw);
  explicit Fixed(const float raw);
  Fixed(const Fixed& other);
  ~Fixed();

  Fixed& operator=(const Fixed& rhs);

  Fixed operator+(const Fixed& rhs) const;
  Fixed operator-(const Fixed& rhs) const;
  Fixed operator*(const Fixed& rhs) const;
  Fixed operator/(const Fixed& rhs) const;

  friend std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

  Fixed& operator++();
  Fixed& operator--();
  Fixed operator++(int);
  Fixed operator--(int);

  bool operator==(const Fixed& rhs) const ;
  bool operator!=(const Fixed& rhs) const ;
  bool operator<(const Fixed& rhs) const ;
  bool operator>(const Fixed& rhs) const ;
  bool operator<=(const Fixed& rhs) const ;
  bool operator>=(const Fixed& rhs) const ;

  int getRawBits(void) const;
  void setRawBits(int const raw);

  static Fixed& min(Fixed& lhs, Fixed& rhs);
  static const Fixed& min(const Fixed& lhs, const Fixed& rhs);
  static Fixed& max(Fixed& lhs, Fixed& rhs);
  static const Fixed& max(const Fixed& lhs, const Fixed& rhs);

  float toFloat(void) const;
  int toInt(void) const;
};

#endif  // EX02_INCLUDE_FIXED_H_
