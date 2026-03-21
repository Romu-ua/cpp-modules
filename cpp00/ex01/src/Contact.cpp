// Copyright 2026 hyamamot
#include <string>
#include "include/Contact.hpp"

void Contact::SetFirstName(const std::string& str) {
  first_name_ = str;
}

void Contact::SetLastName(const std::string& str) {
  last_name_ = str;
}

void Contact::SetNickName(const std::string& str) {
  nick_name_ = str;
}

void Contact::SetPhoneNumber(const std::string& str) {
  phone_number_ = str;
}

void Contact::SetDarkestSecret(const std::string& str) {
  darkest_secret_ = str;
}

std::string Contact::GetFirstName() const {
  return (first_name_);
}

std::string Contact::GetLastName() const {
  return (last_name_);
}

std::string Contact::GetNickName() const {
  return (nick_name_);
}

std::string Contact::GetPhoneNumber() const {
  return (phone_number_);
}

std::string Contact::GetDarkestSecret() const {
  return (darkest_secret_);
}
