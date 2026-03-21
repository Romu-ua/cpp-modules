// Copyright 2026 hyamamot
#ifndef CPP07_EX02_INCLUDE_Array_HPP_
#define CPP07_EX02_INCLUDE_Array_HPP_

template <typename T>
class Array {
  T* array_;
  size_t size_;

 public:
  Array();
  ~Array();
  Array(unsigned n);
  Array(const Array& other);

  Array& operator=(const Array& other);

  T& operator[](size_t index);
  
  size_t size() const;
};

#endif  // CPP07_EX00_INCLUDE_Array_HPP_
