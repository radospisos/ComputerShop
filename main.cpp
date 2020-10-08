#include <iostream>

int main() {
  std::cout << "Hello, World!" << std::endl;
  uint32_t *i = (uint32_t*)1024;
  i++;
  std::cout << *i;
  return 0;
}
