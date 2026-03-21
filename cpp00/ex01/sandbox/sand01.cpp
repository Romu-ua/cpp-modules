// Copyright 2026 hyamamot
#include <iostream>
#include <string>
#include <array>

class PhoneBook {
  std::array<std::string, 8> m_arr;

 public:
  PhoneBook();
  ~PhoneBook();
  const std::array<std::string, 8>& getArr() const;
  void setArr(size_t index, const std::string& str);

  void add_contact(std::string str);
};

PhoneBook::PhoneBook() {
  std::cout << "コンストラクタ呼び出し" << std::endl;
}

PhoneBook::~PhoneBook() {
  std::cout << "デストラクタ呼び出し" << std::endl;
}

const std::array<std::string, 8>& PhoneBook::getArr() const {
  return m_arr;
}

void PhoneBook::setArr(size_t index, const std::string& str) {
  m_arr[index] = str;
}

/*
indexが小さい方が最新のcontact.
末尾のcontactは破棄される.
*/
void PhoneBook::add_contact(std::string str) {
  for (int i = m_arr.size() - 1; i > 0; i--) {
    m_arr[i] = m_arr[i - 1];
  }
  m_arr[0] = str;
}



int main() {
  PhoneBook book;

  // [debug]
  // 値を追加するところまでできた
  for (int i = 0; i < 9; i++) {
    std::string contact = std::to_string(i);
    book.add_contact(contact);
  }

  std::array<std::string, 8> arr = book.getArr();
  for (int i = 0; i < arr.size() - 1; i++) {
    std::cout << arr[i] << std::endl;
  }
}


/*
実装メモ：

std::stringはデフォルトで構築されるとから文字になる
したがって、初期化のコンストラクタはなくて良い。
*/
