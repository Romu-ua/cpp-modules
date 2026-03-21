// Copyright 2026 hyamamot
#include <iostream>
#include <string>
#include <cstdint>

typedef struct Data {
  std::string str;
} Data;


/*
uintptr_t:
  ポインタサイズの符号なし整数型
  uintptr_t型のポインタ値から、voidへのポインタへの逆変換
  変換前と逆変換のポインタ値が等値となる
*/
class Serializer {
 public:
  static uintptr_t serialize(Data* ptr);
  static Data* deserialize(uintptr_t raw);

 private:
  Serializer();
};

uintptr_t Serializer::serialize(Data* ptr) {
  return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
  return reinterpret_cast<Data*>(raw);
}

int main() {
  Data data;
  data.str = "hello";

  uintptr_t ptr = Serializer::serialize(&data);
  Data* serial_data = Serializer::deserialize(ptr);

  std::cout << "ptr: " << ptr << std::endl;
  std::cout << "serial_data str: " << serial_data->str << std::endl; 
}
