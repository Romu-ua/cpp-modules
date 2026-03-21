// Copyright 2026 hyamamot
#ifndef CPP00_EX01_INCLUDE_CONTACT_HPP_
#define CPP00_EX01_INCLUDE_CONTACT_HPP_

#include <string>

class Contact {
  std::string first_name_;
  std::string last_name_;
  std::string nick_name_;
  std::string phone_number_;
  std::string darkest_secret_;

 public:
  void SetFirstName(const std::string& str);
  void SetLastName(const std::string& str);
  void SetNickName(const std::string& str);
  void SetPhoneNumber(const std::string& str);
  void SetDarkestSecret(const std::string& str);

  std::string GetFirstName() const;
  std::string GetLastName() const;
  std::string GetNickName() const;
  std::string GetPhoneNumber() const;
  std::string GetDarkestSecret() const;
};

#endif  // CPP00_EX01_INCLUDE_CONTACT_HPP_
