#include <iostream>
#include <tuple> // Для std::tuple

int main() {
    // Создание кортежа с разными типами данных
    std::tuple<int, std::string, double> person(25, "John Doe", 175.5);

    // Доступ к элементам кортежа по индексу
    std::cout << "Age: " << std::get<0>(person) << std::endl;
    std::cout << "Name: " << std::get<1>(person) << std::endl;
    std::cout << "Height: " << std::get<2>(person) << " cm" << std::endl;

    // Изменение значения кортежа по индексу
    std::get<0>(person) = 30;

    // Вывод измененного значения
    std::cout << "Updated Age: " << std::get<0>(person) << std::endl;

    return 0;
}
