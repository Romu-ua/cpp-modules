// Copyright 2026 hyamamot
#ifndef CPP00_EX01_INCLUDE_PHONEBOOK_HPP_
#define CPP00_EX01_INCLUDE_PHONEBOOK_HPP_

#include <string>
#include "include/Contact.hpp"

class PhoneBook {
  Contact contacts_[8];
  size_t next_index_;
  size_t count_;

 public:
  PhoneBook() : next_index_(0), count_(0) {}
  void add(const std::string& first_name, const std::string& last_name,
    const std::string& nick_name, const std::string& phone_number,
    const std::string& darkest_secret);

  void search(size_t index) const;
  void PrintPhoneBook() const;
  size_t GetCount() const;

  std::string GetFirstName(size_t index) const;
  std::string GetLastName(size_t index) const;
  std::string GetNickName(size_t index) const;
  std::string GetPhoneNumber(size_t index) const;
  std::string GetDarkestSecret(size_t index) const;
};

#endif  // CPP00_EX01_INCLUDE_PHONEBOOK_HPP_
