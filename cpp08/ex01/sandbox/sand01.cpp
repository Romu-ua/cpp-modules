// Copyright 2026 hyamamot
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Span {
  unsigned int size_;
  std::vector<int> vec;

 public:
  Span(unsigned int size) : size_(size) {
    std::cout << "Span constructor" << std::endl;
  }

  void addNumber(int num) {
    if (vec.size() >= size_) {
      throw std::exception();
    }
    vec.push_back(num);
  }

  unsigned int size() {
    return size_;
  }
  int shortestSpan();
  int longestSpan();
};

int Span::shortestSpan() {
  int shortest = INT_MAX;
  std::sort(vec.begin(), vec.end());

  int tmp;
  for (int i = 0; i < size_ - 1; ++i) {
    tmp = vec.at(i + 1) - vec.at(i);
    if (shortest > tmp) {
      shortest = tmp;
    }
  }

  return shortest;
}

int Span::longestSpan() {
  int longest;
  std::sort(vec.begin(), vec.end());
  longest = vec.at(size_ - 1) - vec.at(0);
  return longest;
}

int main() {
  Span sp = Span(5);

  sp.addNumber(6);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);

  try {
    sp.addNumber(-42);
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }


  std::cout << "size: " << sp.size() << std::endl;

  std::cout << "shortest: " << sp.shortestSpan() << std::endl;
  std::cout << "longest: " << sp.longestSpan() << std::endl;

}
