// Copyright 2026 hyamamot
#ifndef CPP07_EX00_INCLUDE_WHATEVER_HPP_
#define CPP07_EX00_INCLUDE_WHATEVER_HPP_

template <typename T>
void ::swap(T& a, T& b) {
  T tmp = a;
  a = b;
  b = tmp;
}

template <typename T>
T& ::min(T& a, T& b) {
  if (a < b) {
    return a;
  }
  return b;
}

template <typename T>
T& ::max(T& a, T& b) {
  if (a > b) {
    return a;
  }
  return b;
}

#endif  // CPP07_EX00_INCLUDE_WHATEVER_HPP_
