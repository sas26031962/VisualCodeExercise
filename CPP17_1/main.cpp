#include <iostream>
#include <tuple>

int main() {
    auto [x, y] = std::make_tuple(10, 20); // Структурированная привязка
    std::cout << "x = " << x << ", y = " << y << std::endl;

    auto [name, age] = std::make_pair("Alice", 30);
    std::cout << "Name: " << name << ", Age: " << age << std::endl;

    return 0;
}
