// Copyright 2026 hyamamot
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char *argv[]) {
  if (argc != 4)
    return 1;

  std::string filename = argv[1];
  std::string s1 = argv[2];
  std::string s2 = argv[3];

  std::fstream file(filename);

  size_t pos;

  std::string line;
  while (std::getline(file, line)) {
    pos = line.find(s1);
    if (pos != std::string::npos) {
      line.replace(pos, s1.size(), s2);
    }
    std::cout << line << std::endl;
  }
  return 0;
}
