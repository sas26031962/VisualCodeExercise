#include <iostream>
#include <thread>
#include <atomic>

std::atomic<int> counter(0); // Атомарная переменная

void increment(int num_iterations) {
    for (int i = 0; i < num_iterations; ++i) {
        counter.fetch_add(1, std::memory_order_relaxed); // Атомарное увеличение
    }
}

int main() {
    const int num_threads = 4;
    const int num_iterations = 1000;

    std::thread threads[num_threads];
    for (int i = 0; i < num_threads; ++i) {
        threads[i] = std::thread(increment, num_iterations);
    }

    for (int i = 0; i < num_threads; ++i) {
        threads[i].join();
    }

    std::cout << "Final counter value: " << counter << std::endl;
    return 0;
}
