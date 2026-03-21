// Copyright 2026 hyamamot
#include <iostream>
#include <iomanip>
#include <string>
#include "include/PhoneBook.hpp"

std::string Format(const std::string& str) {
  if (str.length() > 10) {
    return str.substr(0, 9) + ".";
  }
  return str;
}

void PhoneBook::search(size_t index) const {
  if (index >= count_) {
    std::cout << "No contact at this index." << std::endl;
    return;
  }

  std::cout << std::right;
  std::cout << "FIRST NAME: "
            <<contacts_[index].GetFirstName()
            << std::endl;
  std::cout << "LAST NAME: "
            <<contacts_[index].GetLastName()
            << std::endl;
  std::cout << "NICK NAME: "
            <<contacts_[index].GetNickName()
            << std::endl;
  std::cout << "PHONE NUMBER: "
            <<contacts_[index].GetPhoneNumber()
            << std::endl;
  std::cout << "DARKEST SECRET: "
            <<contacts_[index].GetDarkestSecret()
            << std::endl;
}

void PhoneBook::PrintPhoneBook() const {
  if (count_ == 0) {
    std::cout << "PhoneBook is empty." << std::endl;
    return;
  }

  std::cout << std::right;

  std::cout << std::setw(10) << "INDEX"
            << "|"
            << std::setw(10) << "FIRST NAME"
            << "|"
            << std::setw(10) << "LAST NAME"
            << "|"
            << std::setw(10) << "NICK NAME"
            << "|"
            << std::endl;

  for (size_t i = 0; i < count_; ++i) {
    std::cout << std::setw(10) << i
              << "|"
              << std::setw(10) << Format(contacts_[i].GetFirstName())
              << "|"
              << std::setw(10) << Format(contacts_[i].GetLastName())
              << "|"
              << std::setw(10) << Format(contacts_[i].GetNickName())
              << "|"
              << std::endl;
  }
}

void PhoneBook::add(const std::string& first_name, const std::string& last_name,
    const std::string& nick_name, const std::string& phone_number,
    const std::string& darkest_secret) {
      contacts_[next_index_].SetFirstName(first_name);
      contacts_[next_index_].SetLastName(last_name);
      contacts_[next_index_].SetNickName(nick_name);
      contacts_[next_index_].SetPhoneNumber(phone_number);
      contacts_[next_index_].SetDarkestSecret(darkest_secret);
      next_index_++;
      if (next_index_ == 8)
        next_index_ = 0;
      if (count_ < 8)
        count_++;
    }

size_t PhoneBook::GetCount() const {
  return count_;
}

std::string PhoneBook::GetFirstName(size_t index) const {
  return contacts_[index].GetFirstName();
}

std::string PhoneBook::GetLastName(size_t index) const {
  return contacts_[index].GetLastName();
}

std::string PhoneBook::GetNickName(size_t index) const {
  return contacts_[index].GetNickName();
}
std::string PhoneBook::GetPhoneNumber(size_t index) const {
  return contacts_[index].GetPhoneNumber();
}

std::string PhoneBook::GetDarkestSecret(size_t index) const {
  return contacts_[index].GetDarkestSecret();
}
