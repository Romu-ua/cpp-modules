// Copyrithg 2026 hyamamot
#include "include/Array.hpp"
#include <cstddef>

template <typename T>
Array<T>::Array() : array_(NULL), size_(0) {
  std::cout << "Array default constructor" << std::endl;
}

template <typename T>
Array<T>::~Array() {
  std::cout << "Array destrctor" << std::endl;
    delete [] array_;
}

template <typename T>
Array<T>::Array(unsigned n) : array_(new T[n]), size_(n) {
  std::cout << "Array constructor with unsigned n" << std::endl;
}

template <typename T>
Array<T>::Array(const Array& other) {
  std::cout << "Array Copy constructor" << std::endl;
  array_ = new T[other.size()];
  for (size_t i = 0; i < other.size(); ++i) {
    array_[i] = other.array_[i];
  }
  size_ = other.size_;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
  if (this != &other) {
    delete [] array_;
    size_ = other.size();
    array_ = new T[other.size()];
    for (size_t i = 0; i < other.size(); ++i) {
      array_[i] = other.array_[i];
    }
  }
  return *this;
}

template <typename T>
T&  Array<T>::operator[](size_t index) {
  if (index >= size_) {
    throw std::exception();
  }
  return array_[index];
}

template <typename T>
size_t Array<T>::size() const {
  return size_;
}