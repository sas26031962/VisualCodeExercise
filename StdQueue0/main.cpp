
#include <iostream>
#include <queue>
#include <string>

int main() {
    std::queue<std::string> tasks; // Создаем очередь строк

    // Добавляем задачи в очередь
    tasks.push("Task 1");
    tasks.push("Task 2");
    tasks.push("Task 3");

    // Выводим количество задач
    std::cout << "Number of tasks: " << tasks.size() << std::endl;

    // Извлекаем и обрабатываем задачи из очереди
    while (!tasks.empty()) {
        std::string task = tasks.front(); // Получаем первый элемент
        std::cout << "Processing task: " << task << std::endl;
        tasks.pop(); // Удаляем первый элемент
    }

     std::cout << "Number of tasks after processing: " << tasks.size() << std::endl;

    // Проверяем пуста ли очередь
    if (tasks.empty()) {
        std::cout << "Queue is empty." << std::endl;
    }

    return 0;
}