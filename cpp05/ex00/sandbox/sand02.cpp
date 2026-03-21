// Copyright 2026 hyamamot
#include <iostream>
#include <string>

// 型に応じた補足

int main() {
  try {
    throw "123";  // true, 123, "123"
  } catch (const bool v) {
    std::cout << "bool" << std::endl;
  } catch (const int v) {
    std::cout << "int" << std::endl;
  } catch (...) {
    std::cout << "Unexpected exception was thrown" << std::endl;
  }
}
