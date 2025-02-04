#include <iostream>
#include <charconv>
#include <array>

int main() {
    // Число для преобразования
    int number = 128;//255;
    // Массив для хранения строки
    std::array<char, 10> buffer; 
    // Выполнение преобразования
    auto result = std::to_chars(buffer.begin(), buffer.end(), number, 16); //Основание 16
    // Вывод результата и обработка ошибок
    if (result.ec == std::errc()) 
    {
        //Результат преобразуется в строку из буфера
        // buffer.begin() - указатель на начало буфера
        // result.ptr  - указатель на первый свободный элемент в буфере после записи
        std::cout << "Converted string (hex): " << std::string(buffer.begin(), result.ptr) << std::endl;
    }
    else 
    {
      std::cerr << "Error: not enough space." << std::endl;
    }

    return 0;
}