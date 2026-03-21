// Copyright 2026 hyamamot
#include <iostream>
#include <stack>
#include <deque>

/*
namespace std {
  template <class T, class Container = deque<T>>
  class stack;
}

https://en.cppreference.com/w/cpp/container/stack.html

stackの定義を見てみると、Container_typeのdefineのdefaultはstd::deque<T>
であるので、std::stack::container_typeは、std::deque<T>と同じになる
よって、std::stack::container_type::iteratorがある
これをstackで定義すれば良い。
*/

template <typename T>
class MutantStack : public std::stack<T> {
public:
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;

    MutantStack() : std::stack<T>() {}

    MutantStack(const MutantStack& other) : std::stack<T>(other) {}

    MutantStack& operator=(const MutantStack& other) {
        std::stack<T>::operator=(other);
        return *this;
    }

    ~MutantStack() {}

    iterator begin() {
        return this->c.begin();
    }

    iterator end() {
        return this->c.end();
    }

    const_iterator begin() const {
        return this->c.begin();
    }

    const_iterator end() const {
        return this->c.end();
    }
};

int main() {
  MutantStack<int> m;
  m.push(10);
  m.push(20);
  std::cout << m.top() << std::endl;
  m.pop();

  MutantStack<int>::iterator it = m.begin();
  MutantStack<int>::iterator ite = m.end();

  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }
}
