#include <iostream>
#include <thread>
#include <chrono>

void task() {
  std::cout << "Task started." << std::endl;
  std::this_thread::sleep_for(std::chrono::seconds(2)); // Задержка на 2 секунды
  std::cout << "Task finished after sleep." << std::endl;
}

int main() {
  std::thread t(task);
  t.join();
  return 0;
}
