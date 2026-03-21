// Copyright 2026 hyamamot
#include <iostream>
#include <string>


/*
コンストラクタでリソース管理をしているので、
Rule of three を守って実装させている。
*/
template <typename T>
class Array {
  T* array_;
  size_t size_;

 public:
  Array() : array_(NULL), size_(0) {
    std::cout << "Array default constructor" << std::endl;
  }

  ~Array() {
    std::cout << "Array destrctor" << std::endl;
    delete [] array_;
  }

  Array(unsigned n) : array_(new T[n]), size_(n) {
    std::cout << "Array constructor with unsigned n" << std::endl;
  }

  Array(const Array& other) {
    std::cout << "Array Copy constructor" << std::endl;
    array_ = new T[other.size()];
    for (size_t i = 0; i < other.size(); ++i) {
      array_[i] = other.array_[i];
    }
    size_ = other.size_;
  }

  Array& operator=(const Array& other) {
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

  // 初めてアクセス指定子のオーバーロードを実装した。
  T& operator[](size_t index) {
    if (index >= size_) {
      throw std::exception();
    }
    return array_[index];
  }
  size_t size() const {
    return size_;
  }
};

int main() {
  //int* a = new int();
  //std::cout << *a << std::endl;  // 0で初期化されている。

  //std::string* str = new std::string();
  //std::cout << *str << std::endl;  // から文字で初期化されている。

  //std::vector<int>* vec = new std::vector<int>();
  //std::cout << vec->size() << std::endl;
  //std::cout << vec->capacity() << std::endl; 

  //int* b = new int[42];
  //for (int i = 0; i < 42; ++i) {
  //  std::cout << a[i] << " ";
  //}
  //std::cout << std::endl;

  Array<int> array1;
  Array<int> array2(42);

  array1 = array2;
}
