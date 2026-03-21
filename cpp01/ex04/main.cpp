// Copyright 2026 hyamamot
#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
  if (argc != 4) {
    std::cout << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
    return (1);
  }

  std::string infilename = argv[1];
  std::string s1 = argv[2];
  std::string s2 = argv[3];

  std::fstream infile(infilename.c_str());

  std::string outfilename = infilename + ".replace";
  std::ofstream outfile(outfilename.c_str());

  size_t pos;

  std::string line;
  while (std::getline(infile, line)) {
    pos = line.find(s1);
    if (pos != std::string::npos) {
      line.erase(pos, s1.size());
      line.insert(pos, s2);
    }
    outfile << line << std::endl;
  }
}
