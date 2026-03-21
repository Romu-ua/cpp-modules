// Copyright hyamamot 2026
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

/*
module 08と09で使えるSTLについて学習
Standard Template Library (STL) in C++
*/

int main() {
  // initialize
  std::vector<int> v1;
  std::vector<int> v2(3, 5);
  for (int x : v2) {
    std::cout << x << " ";
  }
  std::cout << std::endl;
  std::vector<int> v3 = {1, 2, 3};
  for (int x : v3) {
    std::cout << x << " ";
  }
  std::cout << std::endl;

  // insert
  std::vector<char> v = {'a', 'b', 'c'};
  v.push_back('z');
  v.insert(v.begin() + 1, 'c');
  for (int i = 0; i < v.size(); i++) {
    std::cout << v[i] << " ";
  }
  std::cout << std::endl;

  // access elements
  std::vector<int> v4 = {10, 20, 30, 40};
  std::cout << "v[2]: " << v4[2] << std::endl;
  std::cout << "v.at(3): " << v4.at(3) << std::endl;
 
  // update elements
  std::cout << "original v[1]: " << v4[1] << std::endl;
  v4[1] = 50;
  std::cout << "update v[1]: " << v4[1] << std::endl;
  
  // find size
  std::cout << v.size() << std::endl;

  // traverse
  for (int i = 0; i < v.size(); i++) {
    std::cout << v[i] << " ";
  }
  std::cout << std::endl;

  // delete
  v.pop_back();
  for (int i = 0; i < v.size(); i++) {
    std::cout << v[i] << " ";
  }
  std::cout << std::endl;
  std::vector<char>::iterator it = find(v.begin(), v.end(), 'b');
  if (it != v.end())
    v.erase(it);
  for (int i = 0; i < v.size(); i++) {
    std::cout << v[i] << " ";
  }
  std::cout << std::endl;

  // empty check
  std::vector<int> vemp;
  if (vemp.empty()) {
    std::cout << "vector empty" << std::endl;
  }
  vemp.push_back(100);
  if (vemp.empty()) {
    std::cout << "vector empty" << std::endl;
  } else {
    std::cout << "vector not empty" << std::endl;
  }

  // Multidimensional
  std::vector<std::vector<int>> matrix {
    {1, 2, 3},
    {4, 5, 6}, 
    {7, 8, 9}
  };
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[i].size(); j++) {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << std::endl;
  }
}
