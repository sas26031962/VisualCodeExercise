#include <iostream>
#include <coroutine>
#include <exception>

// Обещание для нашей корутины
struct NumberGenerator {
    struct promise_type {
        int current_value;

        std::suspend_always initial_suspend() { return {}; }
        std::suspend_always final_suspend() noexcept { return {}; }
        NumberGenerator get_return_object() { return NumberGenerator{this}; }
        void unhandled_exception() { std::terminate(); }

        std::suspend_always yield_value(int value) {
            current_value = value;
            return {};
        }

        void return_void() {}
    };

    promise_type* promise;

    NumberGenerator(promise_type* p) : promise(p) {}

    int get_next() {
        return promise->current_value;
    }

    bool next() {
        if (coroutine_handle_) {
            coroutine_handle_.resume();
            return !coroutine_handle_.done();
        }
        return false;
    }

private:
    using coroutine_handle = std::coroutine_handle<promise_type>;
    coroutine_handle coroutine_handle_ = coroutine_handle::from_promise(promise);

};

NumberGenerator generate_numbers(int start, int end) {
    for (int i = start; i <= end; ++i) {
        co_yield i;
    }
}

int main() {
    NumberGenerator generator = generate_numbers(1, 5);

    while (generator.next()) {
        std::cout << generator.get_next() << " "; // Вывод: 1 2 3 4 5
    }
    std::cout << std::endl;

    return 0;
}