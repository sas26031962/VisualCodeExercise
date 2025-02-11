#include <coroutine>
#include <iostream>

struct NumberGenerator {
    struct promise_type {
        int current_value;
        auto get_return_object() { return NumberGenerator{this}; }
        auto initial_suspend() { return std::suspend_always{}; }
        auto final_suspend() noexcept { return std::suspend_always{}; }
        void unhandled_exception() { std::terminate(); }
        auto yield_value(int value) {
            current_value = value;
            return std::suspend_always{};
        }
        void return_void() {}
    };

    using handle_type = std::coroutine_handle<promise_type>;
    handle_type coro_handle;

    explicit NumberGenerator(promise_type* p)
        : coro_handle(handle_type::from_promise(*p)) {}
    ~NumberGenerator() {
        if (coro_handle) coro_handle.destroy();
    }
    int next() {
        coro_handle.resume();
        return coro_handle.promise().current_value;
    }
};

NumberGenerator generateNumbers() {
    for (int i = 0; i < 5; ++i) {
        co_yield i;
    }
}

int main() {
    auto gen = generateNumbers();
    for (int i = 0; i < 5; ++i) {
        std::cout << gen.next() << std::endl;
    }
}
