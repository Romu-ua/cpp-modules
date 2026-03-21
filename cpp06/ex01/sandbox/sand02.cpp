// Copyright 2026 hyamamot
#include <iostream>

/*
reinterpret_castの練習
*/

struct Packet {
  int id;
  short value;
};

void hello() {
  std::cout << "good morning" << std::endl;
}

int main() {
  // 1. intのメモリをcharとして読む
  int value = 0x12345678;

  char* p = reinterpret_cast<char*>(&value);

  // リトルエンディアンとして並ぶ
  for (size_t i = 0; i < sizeof(int); i++) {
    std::cout << std::hex << (0xFF & p[i]) << " ";
  }
  std::cout << std::endl;


  // 2. アドレスを整数として扱う
  std::cout << "2. ---" << std::endl;
  int x = 42;

  int* ptr = &x;

  uintptr_t addr = reinterpret_cast<uintptr_t>(ptr);
  std::cout << "address: " << addr << std::endl;
  std::cout << "sizeof(uintptr_t): " << sizeof(uintptr_t) << std::endl;

  int* ptr2 = reinterpret_cast<int*>(addr);
  std::cout << std::dec << *ptr2 << std::endl;

  // 3. バイナリデータを構造体として読む
  std::cout << "3. ---" << std::endl;
  char buffer[sizeof(Packet)];

  std::cout << "sizeof(Packet): " << sizeof(Packet) << std::endl;
  // 手動でint id = 1, value = 10を入れる
  // int = 4byte, short = 2byte
  // パディングで2byte
  buffer[0] = 1;
  buffer[1] = 0;
  buffer[2] = 0;
  buffer[3] = 0;

  buffer[4] = 10;
  buffer[5] = 0;

  Packet* packet = reinterpret_cast<Packet*>(buffer);
  
  std::cout << "id: " << packet->id << std::endl;
  std::cout << "value: " << packet->value << std::endl;

  // 4. 関数ポインタの変換
  std::cout << "4. ---" << std::endl;
  void (*func)() = hello;

  void* funcptr = reinterpret_cast<void*>(func);
  // キャストに関数ポインタ入っているの見ずらい
  auto func2 = reinterpret_cast<void(*)()>(funcptr);

  func2();
}
