// Copyright
#include <iostream>
#include <string>

int main(int argc, char **argv) {
  for (int i = 0; i < argc; ++i) {
    std::string arg = argv[i];
    std::cout << arg << std::endl;
  }
}
