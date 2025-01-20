#include <iostream>
#include <thread>

void threadFunction() {
  std::cout << "Thread ID: " << std::this_thread::get_id() << std::endl;
}

int main() {
  std::cout << "Main thread ID: " << std::this_thread::get_id() << std::endl;

  std::thread t1(threadFunction);
  std::thread t2(threadFunction);

  t1.join();
  t2.join();

  return 0;
}
