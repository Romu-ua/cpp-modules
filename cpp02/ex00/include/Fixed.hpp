// Copyright 2026 hyamamot
#ifndef EX00_INCLUDE_FIXED_H_
#define EX00_INCLUDE_FIXED_H_

#include <string>

class Fixed {
  static const int fractional_ = 8;
  int raw_;

 public:
  Fixed();
  Fixed(const Fixed& other);
  ~Fixed();

  void operator=(const Fixed& rhs);

  int getRawBits(void) const;
  void setRawBits(int const raw);
};

#endif  // EX00_INCLUDE_FIXED_H_
