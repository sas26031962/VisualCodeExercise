#include <iostream>
#include <memory>
#include <type_traits>

using namespace std;

// 1. Обобщенные лямбда-выражения (auto в параметрах)
auto multiply = [](auto a, auto b) { return a * b; };

// 2. Возврат auto для функций
auto factorial(int n) {
    if (n == 0) return 1;    // Тип выводится автоматически
    return n * factorial(n - 1);
}

// 3. Constexpr с условиями и циклами
constexpr int compute() {
    int res = 0;
    for (int i = 0; i < 10; ++i) {  // Циклы в constexpr
        if (i % 2 == 0) res += i;   // Условия в constexpr
        else res -= i;
    }
    return res;
}

int main() {
    // 1. Использование обобщенной лямбды
    cout << multiply(3, 4) << endl;           // 12
    cout << multiply(2.5, 3.2) << endl;       // 8.0

    // 2. Автовозвращаемый тип
    cout << "Factorial(5): " << factorial(5) << endl;  // 120

    // 3. Constexpr вычисления
    constexpr int result = compute();
    cout << "Compute(): " << result << endl;  // -5

    // 4. Бинарные литералы и разделители '
    int binary = 0b1010'1100;  // 0b... для двоичных чисел
    long long big_num = 9'223'372'036'854'775'807LL;
    cout << "Binary: " << binary << endl;      // 172

    // 5. make_unique (C++14)
    auto ptr = make_unique<int>(42);
    cout << *ptr << endl;  // 42

    // 6. Упрощенный захват переменных в лямбдах
    int x = 10, y = 20;
    auto lambda = [z = x + y] { return z; };  // Захват с инициализацией
    cout << "Lambda: " << lambda() << endl;    // 30

    return 0;
}
