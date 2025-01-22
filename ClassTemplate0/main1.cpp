#include <iostream>
#include <string>

template <typename T>
class MyPair {
public:
    MyPair(T first, T second) : first_(first), second_(second) {}

    void print() const {
      std::cout << "First: " << first_ << ", Second: " << second_ << std::endl;
    }

    T getFirst() const { return first_; }
    T getSecond() const { return second_; }

private:
    T first_;
    T second_;
};

int main() {
    MyPair<int> intPair(10, 20); // Конкретизация шаблона с типом int
    intPair.print();

    MyPair<double> doublePair(3.14, 2.71); // Конкретизация шаблона с типом double
    doublePair.print();

     MyPair<std::string> stringPair("Hello", "World"); // Конкретизация шаблона с типом string
    stringPair.print();

    return 0;
}
