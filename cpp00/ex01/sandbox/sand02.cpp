// Copyright 2026 hyamamot
#include <iostream>
#include <string>
#include <iomanip>

std::string Format(const std::string& str);

class Contact {
  std::string first_name_;
  std::string last_name_;
  std::string nick_name_;
  std::string phone_number_;
  std::string darkest_secret_;

 public:
  void SetFirstName(const std::string& str);
  void SetLastName(const std::string& str);
  void SetNicktName(const std::string& str);
  void SetPhoneNumber(const std::string& str);
  void SetDarkestSecret(const std::string& str);

  std::string GetFirstName() const;
  std::string GetLastName() const;
  std::string GetNickName() const;
  std::string GetPhoneNumber() const;
  std::string GetDarkestSecret() const;
};

void Contact::SetFirstName(const std::string& str) {
  first_name_ = str;
}

void Contact::SetLastName(const std::string& str) {
  last_name_ = str;
}

void Contact::SetNicktName(const std::string& str) {
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


class PhoneBook {
  std::array<Contact, 8> contacts;
  size_t index; // 次に追加する位置

 public:
 PhoneBook() : index(0) {};
  void add(std::string first_name, std::string last_name, 
    std::string nick_name, std::string phone_number, 
    std::string darkest_secret) {
      contacts[index].SetFirstName(first_name);
      contacts[index].SetLastName(last_name);
      contacts[index].SetNicktName(nick_name);
      contacts[index].SetPhoneNumber(phone_number);
      contacts[index].SetDarkestSecret(darkest_secret);
      index++;
      if (index == contacts.size())
        index = 0;
    }

  void search(size_t index);
};

void PhoneBook::search(size_t index) {
  if (index >= 0 && index < contacts.size()) {
    std::cout << std::right; // 右寄せ指定
    std::cout << std::setw(10) << Format(contacts[index].GetFirstName())
              << "|"
              << std::setw(10) << Format(contacts[index].GetLastName())
              << "|"
              << std::setw(10) << Format(contacts[index].GetNickName())
              << "|"
              << std::setw(10) << Format(contacts[index].GetPhoneNumber())
              << "|"
              << std::setw(10) << Format(contacts[index].GetDarkestSecret())
              << std::endl;
  }
}

std::string Format(const std::string& str) {
  if (str.length() > 10) {
    return str.substr(0, 9) + ".";
  }
  return str;
}

int main() {
  PhoneBook phonebook;

  // [debug] 値が入力できるかどうか。
  //phonebook.add(
  //  "first_name",
  //  "last_name",
  //  "nick_name",
  //  "phnoe_number",
  //  "darkest_secret"
  //);

  //phonebook.search(0);

  // 入力の処理を作成する
  std::string input;

  std::cout << "command: ";
  std::getline(std::cin, input);
  //std::cout << "input: " << input << std::endl;

  std::string first_name;
  std::string last_name;
  std::string nick_name;
  std::string phone_number;
  std::string darkest_secret;

  if (input == "ADD") {
    std::cout << "input all elements." << std::endl;
    std::getline(std::cin, first_name);
    std::getline(std::cin, last_name);
    std::getline(std::cin, nick_name);
    std::getline(std::cin, phone_number);
    std::getline(std::cin, darkest_secret);
    phonebook.add(first_name, last_name, nick_name, phone_number, darkest_secret);
  }

  int index;
  if (input == "SEARCH") {
    std::cout << "index(0 ~ 7): ";
    std::cin >> index;
    phonebook.search(index);
  }
}

/*
PhoneBookクラスはContactクラスの配列を持つ
*/