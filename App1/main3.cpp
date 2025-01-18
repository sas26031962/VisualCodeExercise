#include <iostream>
#include <cstring> // для функций работы со строками

int main() {
    char name[] = "Alice";

    // Вывод строки:
    std::cout << "Имя: " << name << std::endl;

    // Длина строки:
    int len = std::strlen(name);
    std::cout << "Длина имени: " << len << std::endl;

    // Копирование строки:
    char copy[20];
    std::strcpy(copy, name);
     std::cout << "Скопированное имя: " << copy << std::endl;

    // Сравнение строк
    if (std::strcmp(name, "Alice") == 0) {
       std::cout << "Имена одинаковы" << std::endl;
    }

    return 0;
}