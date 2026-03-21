// Copyright 2026 hyamamot
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <regex>
#include <map>
#include <cstdlib>
#include "include/BitcoinExchange.hpp"

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cout << "Error: Usage ./btc <infile>" << std::endl;
    return 1;
  }
  std::map<std::string, double> csv_data;
  if (!CsvToMap(&csv_data)) {
    return 1;
  }
  if (!CalculateValue(csv_data, argv[1])) {
    return 1;
  }
}
