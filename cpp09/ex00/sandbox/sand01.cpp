// Copyright 2026 hyamamot
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <regex>
#include <map>
#include <cstdlib>


/*
YYYY-MM-DDで
Y 0000 ~ 9999
M 01 ~ 01
D 01 ~ 31

であることを正規表現で保証している。
*/
bool IsDateFormat(std::string date) {
  std::regex pattern(R"(\d{4}-(0[1-9]|1[0-2])-(0[1-9]|[12][0-9]|3[01]))");
  return std::regex_match(date, pattern);
}

bool IsLeapYear(int y) {
  return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

bool IsValidDate(int y, int m, int d) {
  if (m < 1 || m > 12) {
    return false;
  }
  int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (IsLeapYear(y)) {
    days[1] = 29;
  }
  if (d < 1 || d > days[m - 1]) {
    return false;
  }
  return true;
}

bool IsValidVal(float value) {
  if (value < 0 || value > 10000) {
    return false;
  }
  return true;
}

std::string Trim(const std::string& s) {
  size_t start = 0;
  size_t end = s.size();

  while (start < end && std::isspace(s[start])) {
    start++;
  }
  while (end > start && std::isspace(s[end - 1])) {
    end--;
  }
  return s.substr(start, end - start);
}


/*
database側のチェックはいったん必要ないものとして考える。
*/
int main(int argc, char* argv[]) {
  if (argc != 2) {
    return (1);
  }

  // stringstream
  std::string text = "10 20 30";
  std::stringstream ss(text);

  int a, b, c;
  ss >> a >> b >> c;
  std::cout << a << " " << b << " " << c << std::endl;


  // csv to map
  std::map<std::string, double> csv_data;

  std::ifstream csv("my_data.csv");
  std::string line;

  // 先頭を単に読み捨てる : todo headerのvalidationも必要かもしれない
  std::getline(csv, line);

  while (std::getline(csv, line)) {
    std::stringstream ss(line);
    std::string key, value;
    if (std::getline(ss, key, ',') && std::getline(ss, value)) {
      csv_data[key] = std::stof(value);
    }
  }

  //std::cout << "debug" << std::endl;
  //std::map<std::string, double>::iterator it = csv_data.begin();
  //while (it != csv_data.end()) {
  //  std::cout << "first: " << it->first << ", second: " << it->second << std::endl;
  //  ++it;
  //}

  // file input
  std::string filename = argv[1];
  
  std::ifstream file(filename);
  // lineは上で定義している
  bool is_header = true;
  while (getline(file, line)) {
    std::stringstream ss(line);
    std::string cell;
    std::vector<std::string> row;

    while (getline(ss, cell, '|')) {
      cell = Trim(cell);
      row.push_back(cell);
    }

  // error check
  if (is_header) {
    if (row[0] != "data" || row[1] != "value") {
      std::cout << "hedaer name is invalid" << std::endl;
      break;
    }
    is_header = false;
    continue;
  }

  if (row.size() != 2) {
    std::cout << "element size is not three." << std::endl;
    continue;
  }
  if (!IsDateFormat(row[0])) {
    std::cout << "date format is invalid" << std::endl;
    continue;
  }
  int y, m, d;
  std::stringstream ss2(row[0]);
  char dash;
  ss2 >> y >> dash >> m >> dash >> d;
  if (!IsValidDate(y, m, d)) {
    std::cout << "data is invalid" << std::endl;
    continue;
  }

  int value;
  try {
    value = std::stof(row[1]);
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
    continue;
  }
  if (!IsValidVal(value)) {
    std::cout << "value is invalid" << std::endl;
    continue;
  }

  // multiple rate * value
  std::map<std::string, double>::iterator it = csv_data.lower_bound(row[0]);
  if (it == csv_data.end()) {
    std::cout << "not found previous value" << std::endl;
    continue;
  }

  std::cout << it->second * value << std::endl;
  }
  file.close();
}
