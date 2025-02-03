#include <iostream>
#include <charconv>
#include <array>

int main() {
    int number = 128;//255;
    std::array<char, 10> buffer; // Массив для хранения строки
    auto result = std::to_chars(buffer.begin(), buffer.end(), number, 16); //Основание 16
    if (result.ec == std::errc()) {
        std::cout << "Converted string (hex): " << std::string(buffer.begin(), result.ptr) << std::endl;
    }else {
      std::cerr << "Error: not enough space." << std::endl;
    }

    return 0;
}