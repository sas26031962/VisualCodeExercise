#include <iostream>
#include <string>
#include <type_traits>


template <typename T>
void printValue(const T& value) {
    if constexpr (std::is_integral_v<T>) { //Проверяем является ли T целым числом
        std::cout << "Integer value: " << value << std::endl;
    } else if constexpr (std::is_floating_point_v<T>) { //Проверяем является ли T числом с плавающей точкой
        std::cout << "Floating-point value: " << value << std::endl;
    } else if constexpr (std::is_same_v<T, std::string>) {  //Проверяем является ли T строкой
        std::cout << "String value: " << value << std::endl;
    } else {
        std::cout << "Unsupported type" << std::endl;
    }
}

int main() {
    printValue(10);         // Выведет "Integer value: 10"
    printValue(3.14);       // Выведет "Floating-point value: 3.14"
    printValue(std::string("Hello")); // Выведет "String value: Hello"
    printValue(true);       // Выведет "Integer value: 1"
    return 0;
}
