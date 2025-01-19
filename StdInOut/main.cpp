#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <chrono>
#include <thread>

int main() {
    // Пример ввода-вывода
    std::cout << "Enter your name: ";
    std::string name;
    std::getline(std::cin, name);
    std::cout << "Hello, " << name << "!" << std::endl;

    // Пример работы со строками
    std::string message = "Hello, world!";
    std::cout << "Length of message: " << message.length() << std::endl;
    message.append(" C++");
    std::cout << "Message with append: " << message << std::endl;

    // Пример использования vector
    std::vector<int> numbers = {5, 2, 8, 1, 9};
    std::sort(numbers.begin(), numbers.end());
    std::cout << "Sorted numbers: ";
    for(int num : numbers)
      std::cout << num << " ";
     std::cout << std::endl;

    // Пример sqrt
    double a = 100;
    std::cout << "Sqrt of " << a << " is " << std::sqrt(a) << std::endl;

     // Пример sleep
    std::cout << "Sleeping..." << std::endl;
     std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Slept." << std::endl;

     // Пример потоков
    std::thread my_thread([] {
        std::cout << "Hello from a thread!" << std::endl;
    });
    my_thread.join();

    return 0;
}
