// main.cpp
#include "my_header.h"
#include <iostream>

int main() {
   globalCounter++;
  std::cout << "Counter in main.cpp: " << globalCounter << std::endl;
    return 0;
}