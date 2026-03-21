// Copyright 2026 hyamamot
#ifndef CPP09_INCLUDE_EX00_HPP_
#define CPP09_INCLUDE_EX00_HPP_
#include <string>
#include <map>

bool CsvToMap(std::map<std::string, double>* csv_data);
bool CalculateValue(std::map<std::string, double> csv_data, std::string file);

#endif  // CPP09_INCLUDE_EX00_HPP_