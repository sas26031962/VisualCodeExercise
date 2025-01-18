#include <iostream>

int main() {
    int numbers[] = {10, 20, 30, 40, 50};

    // Доступ к элементу по индексу (индекс начинается с 0):
    std::cout << "Первый элемент: " << numbers[0] << std::endl;
    std::cout << "Третий элемент: " << numbers[2] << std::endl;

    // Изменение значения элемента:
    numbers[1] = 25;
    std::cout << "Измененный второй элемент: " << numbers[1] << std::endl;

    // Цикл для доступа ко всем элементам:
    for (int i = 0; i < 5; ++i) {
        std::cout << "Элемент " << i << ": " << numbers[i] << std::endl;
    }

    return 0;
}