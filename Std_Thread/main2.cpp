#include <iostream>
#include <thread>
#include <vector>
#include <atomic>

std::atomic<int> sharedValue = 0;

void threadFunction() {
    while (sharedValue < 1000) {
    
      if (sharedValue % 10 == 0) {
         std::this_thread::yield(); // Уступаем процессор, если sharedValue кратно 10
      }
        sharedValue++;
    }
     std::cout << "Thread ID: " << std::this_thread::get_id() <<  " finished counting to 1000" << std::endl;
}

int main() {
    std::thread t1(threadFunction);
    std::thread t2(threadFunction);
    
    t1.join();
    t2.join();
    std::cout << "Main Thread Finished" << std::endl;
  return 0;
}

