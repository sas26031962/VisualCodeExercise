#include <iostream>
#include <functional>
#include <string>

// Обычная функция
int add(int a, int b) {
    return a + b;
}

// Функция-член
class MyClass {
public:
    int multiply(int a, int b) {
        return a * b;
    }
};

int main() {
    // Создаем объект std::function
    std::function<int(int, int)> operation;

    // Присваиваем обычную функцию
    operation = add;
    std::cout << "add(5, 3) = " << operation(5, 3) << std::endl;

    // Присваиваем лямбда-выражение
    operation = [](int a, int b) { return a - b; };
    std::cout << "lambda(5, 3) = " << operation(5, 3) << std::endl;

    // Присваиваем функцию-член
    MyClass obj;
    operation = std::bind(&MyClass::multiply, &obj, std::placeholders::_1, std::placeholders::_2);
    std::cout << "multiply(5, 3) = " << operation(5, 3) << std::endl;

    // Проверка на пустоту
    std::function<void()> empty_func;
    if (empty_func) {
        std::cout << "Function is not empty" << std::endl;
    } else {
        std::cout << "Function is empty" << std::endl;
    }


    return 0;
}