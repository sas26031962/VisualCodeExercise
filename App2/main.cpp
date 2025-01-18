#include <iostream>
#include <concepts>

// Концепт для типа, который можно выводить в поток
template <typename T>
concept Printable = requires(std::ostream& os, const T& obj) {
    os << obj;
};

// Функция, которая работает только с printable типами
template <Printable T>
void print(const T& obj) {
    std::cout << obj << std::endl;
}

int main() {
    int x = 10;
    print(x); //  работает, потому что int выводится в поток
    // print("hello");  // не работает, потому что const char* выводится по другому
    return 0;
}