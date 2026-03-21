// Copyright 2026 hyamamot
#ifndef EX01_INCLUDE_FIXED_H_
#define EX01_INCLUDE_FIXED_H_

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

  int getRawBits(void) const;
  void setRawBits(int const raw);

  float toFloat(void) const;
  int toInt(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif  // EX01_INCLUDE_FIXED_H_
