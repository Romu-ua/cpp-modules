// Copyright 2026 hyamamot
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cstdlib>

#include "include/BitcoinExchange.hpp"

bool CsvToMap(std::map<std::string, double>* csv_data) {
  std::ifstream csv("data.csv");
  std::string header;

  std::getline(csv, header);
  if (header != "date,exchange_rate") {
    std::cerr << "csv file header is broken." << std::endl;
    return false;
  }
  std::string line;
  while (std::getline(csv, line)) {
    std::stringstream ss(line);
    std::string key;
    std::string value;
    if (std::getline(ss, key, ',') && std::getline(ss, value)) {
      (*csv_data)[key] = std::stof(value);
    }
  }
  return true;
}


namespace {
  void Trim(std::string& str) {
    size_t start = 0;
    size_t end = str.size();

    while (start < end && std::isspace(str[start])) {
      start++;
    }
    while (end > start && std::isspace(str[end - 1])) {
      end--;
    }
    str = str.substr(start, end - start);
  }

  bool IsCorectRowSize(std::vector<std::string>& row) {
    if (row.size() != 2) {
      std::cout << "Error: many element in one line." << std::endl;
      return true;
    }
    return false;
  }

  bool IsValidVal(int value) {
    if (value < 0) {
      std::cout << "Error: not a positive number." << std::endl;
      return false;
    } else if (value > 10000) {
      std::cout << "Error: too large number." << std::endl;
      return false;
    }
    return true;
  }

  bool PrintValue(std::map<std::string, double> csv_data, std::vector<std::string> row) {
    double value;

    try {
      value = std::stof(row[1]);
    } catch (std::exception& e) {
      std::cout << e.what() << std::endl;
      return false;
    }
    if (!::IsValidVal(value)) {
      return false;
    }

    std::map<std::string, double>::iterator it = csv_data.lower_bound(row[0]);
    if(it == csv_data.end()) {
      std::cout << "Error: not found previous value" << std::endl;
      return false;
    }
    std::cout << row[0] << " => " << value << " = " << it->second * value << std::endl;
    return true;
  }

  bool IsDateFormat(std::string date) {
    if (date.length() != 10) {
      return false;
    }
    return isdigit(date[0]) && isdigit(date[1]) &&
           isdigit(date[2]) && isdigit(date[3]) &&
           date[4] == '-' &&
           isdigit(date[5]) && isdigit(date[6]) &&
           date[7] == '-' &&
           isdigit(date[8]) && isdigit(date[9]);
  }
  
  bool IsLeapYear(int y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
  }

  bool IsValidDate(std::string date) {
    if (!IsDateFormat(date)) {
      std::cout << "Error: bad input => " << date << std::endl;
      return false;
    }
    int y, m, d;
    char dash;
    std::stringstream ss(date);
    ss >> y >> dash >> m >> dash >> d;
    if (m < 1 || m > 12) {
      std::cout << "Error: bad input => " << date << std::endl;
      return false;
    }

    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (IsLeapYear(y)) {
      days[1] = 29;
    }
    if (d < 1 || d > days[m - 1]) {
      std::cout << "Error: bad input => " << date << std::endl;
      return false;
    }
    return true;
  }
}

bool CalculateValue(std::map<std::string, double> csv_data, std::string filename) {
  std::ifstream file(filename);
  std::string header;

  std::getline(file, header);
  if (header != "data | value") {
    std::cout << "input file header is broken" << std::endl;
    return false;
  }
  std::string line;
  while (std::getline(file, line)) {
    std::stringstream ss(line);
    std::string elem;
    std::vector<std::string> row;

    while (std::getline(ss, elem, '|')) {
      ::Trim(elem);
      row.push_back(elem);
    }

    if (!::IsValidDate(row[0])) {
      continue;
    }

    if (::IsCorectRowSize(row)) {
      continue;
    }
    
    if (::PrintValue(csv_data, row)) {
      continue;
    }
  }
  file.close();
  return true;
}
