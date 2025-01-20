#include <iostream>
#include <thread>
#include <chrono>
#include <ctime> // Для std::time

void task() {
    
  std::cout << "Task started." << std::endl;
    
  auto now = std::chrono::system_clock::now();
  auto tenSecondsLater = now + std::chrono::seconds(10);

  std::cout << "Sleeping until: " << std::chrono::system_clock::to_time_t(tenSecondsLater) << std::endl; // to see what time is expected

  std::this_thread::sleep_until(tenSecondsLater);

  std::cout << "Task finished after sleep until." << std::endl;
}

int main() {
  std::thread t(task);
  t.join();
  return 0;
}

