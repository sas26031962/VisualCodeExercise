/*
Передача списков инициализации в C++ позволяет передавать инициализацию для массивов,
контейнеров STL и объектов классов с помощью одного удобного синтаксиса.
*/
//--------------------------------------------------------------------------------
// Подключаемые файлы
//--------------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <initializer_list>


//--------------------------------------------------------------------------------
// Классы, функции
//--------------------------------------------------------------------------------
void printValues(const std::initializer_list<int>& values) {
    std::vector<int> v;
    v.clear();

    std::cout << "Values: ";
    for (auto value : values) {
        std::cout << value << " ";
        v.push_back(value);
    }
    std::cout << std::endl;
}

//--------------------------------------------------------------------------------
// Главная программа
//--------------------------------------------------------------------------------
/*
int main(int argc, char *argv[])
{
    int A = 0;
//--------------------------------------------------------------------------------
    // Передача списка инициализации для массива
    std::initializer_list<int> listx = {1, 2, 3, 4, 5};
    //printValues({1, 2, 3, 4, 5});
    printValues(listx);

//--------------------------------------------------------------------------------
    return A;
}
*/
//-------------------------------------------------------------------------------
//    Передача списка инициализации для контейнера STL (например, std::vector):
//-------------------------------------------------------------------------------

#include <iostream>
#include <vector>

void printVector(const std::vector<int>& vec) {
    std::cout << "Vector: ";
    for (auto value : vec) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Передача списка инициализации для вектора
    printVector({1, 2, 3, 4, 5});
    return 0;
}


//------------------------------------------------------------------------------
//    Передача списка инициализации для объекта класса:
//------------------------------------------------------------------------------
/*
#include <iostream>
#include <string>

class Person {
public:
    Person(std::string n, int a) : name(n), age(a) {}

    void printInfo() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }

private:
    std::string name;
    int age;
};

int main() {
    // Передача списка инициализации для объекта класса Person
    Person person = {"Alice", 30};
    person.printInfo();
    return 0;
}
*/
