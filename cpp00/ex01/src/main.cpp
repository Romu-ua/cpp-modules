// Copyright 2026 hyamamot
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include "include/Contact.hpp"
#include "include/PhoneBook.hpp"

bool IsEmpty(const std::string& str) {
  if (str.empty()) {
    std::cout << "Entering an empty input is invalid." << std::endl;
    return true;
  }
  return false;
}

bool IsAlphabetOrSpace(const std::string& str) {
  for (size_t i = 0; i < str.size(); ++i) {
    unsigned char ch = static_cast<unsigned char>(str[i]);
    if (!std::isalpha(ch) && ch != ' ') {
      return false;
    }
  }
  return true;
}


bool IsPhoneNumber(const std::string& phone_number) {
  if (IsEmpty(phone_number))
    return false;

  for (size_t i = 0; i < phone_number.size(); i++) {
    if (!std::isdigit(static_cast<unsigned char>(phone_number[i]))) {
      std::cout << "Please enter number only (1234567890)" << std::endl;
      return false;
    }
  }
  return true;
}

bool ParseIndex(const std::string& index_input, size_t* index) {
  if (index_input.empty())
    return false;

  for (size_t i = 0; i < index_input.size(); ++i) {
    if (!std::isdigit(static_cast<unsigned char>(index_input[i]))) {
      return false;
    }
  }

  std::stringstream ss(index_input);
  size_t parsed = 0;

  ss >> parsed;
  if (ss.fail() || !ss.eof())
    return false;
  *index = parsed;
  return true;
}

int main() {
  PhoneBook phonebook;

  std::string input;

  std::string first_name;
  std::string last_name;
  std::string nick_name;
  std::string phone_number;
  std::string darkest_secret;

  while (true) {
    std::cout << "command(ADD, SEARCH, EXIT): ";
    if (!std::getline(std::cin, input)) {
      if (std::cin.eof()) {
        std::cout << "EOF" << std::endl;
        break;
      }
      std::cin.clear();
      continue;
    }

    if (input == "ADD") {
      while (true) {
        std::cout << "first_name: ";
        if (!std::getline(std::cin, first_name)) {
          std::cout << "EOF" << std::endl;
          return 0;
        }
        if (IsEmpty(first_name)) {
          continue;
        }
        if (!IsAlphabetOrSpace(first_name)) {
          std::cout << "Please use alphabet characters and spaces only."
                    << std::endl;
          continue;
        }
        break;
      }

      while (true) {
        std::cout << "last_name: ";
        if (!std::getline(std::cin, last_name)) {
          std::cout << "EOF" << std::endl;
          return 0;
        }
        if (IsEmpty(last_name)) {
          continue;
        }
        if (!IsAlphabetOrSpace(last_name)) {
          std::cout << "Please use alphabet characters and spaces only."
                    << std::endl;
          continue;
        }
        break;
      }

      while (true) {
        std::cout << "nick_name: ";
        if (!std::getline(std::cin, nick_name)) {
          std::cout << "EOF" << std::endl;
          return 0;
        }
        if (IsEmpty(nick_name)) {
          continue;
        }
        if (!IsAlphabetOrSpace(nick_name)) {
          std::cout << "Please use alphabet characters and spaces only."
                    << std::endl;
          continue;
        }
        break;
      }

      while (true) {
        std::cout << "phone_number: ";
        if (!std::getline(std::cin, phone_number)) {
          std::cout << "EOF" << std::endl;
          return 0;
        }
        if (!IsPhoneNumber(phone_number)) {
          continue;
        }
        break;
      }

      std::cout << "darkest_secret: ";
      if (!std::getline(std::cin, darkest_secret)) {
        std::cout << "EOF" << std::endl;
        return 0;
      }

      if (IsEmpty(darkest_secret))
        continue;

      phonebook.add(first_name,
                    last_name,
                    nick_name,
                    phone_number,
                    darkest_secret);
    } else if (input == "SEARCH") {
      phonebook.PrintPhoneBook();
      if (phonebook.GetCount() == 0)
        continue;

      std::cout << "index(0 ~ " << phonebook.GetCount() - 1 << "): ";
      std::string index_input;
      if (!std::getline(std::cin, index_input))
        continue;

      size_t index;
      if (!ParseIndex(index_input, &index) || index >= phonebook.GetCount()) {
        std::cout << "Input number (0 ~ " << phonebook.GetCount() - 1
                  << "). An invalid value was entered." << std::endl;
        continue;
      }
      phonebook.search(index);
    } else if (input == "EXIT") {
      std::cout << "EXIT" << std::endl;
      break;
    } else {
      std::cout << "not command registered" << std::endl;
    }
  }
}
