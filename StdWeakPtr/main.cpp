/*
Класс std::weak_ptr в C++ используется для создания слабых указателей на объекты,
управляемые умными указателями (std::shared_ptr). Слабые указатели позволяют
избежать циклических зависимостей, которые могут привести к утечкам памяти.

В этом примере создается объект класса MyClass и управляется им с помощью std::shared_ptr.
Затем создается std::weak_ptr из std::shared_ptr. Слабый указатель не увеличивает
счетчик ссылок объекта. Когда объект уничтожается, а std::shared_ptr удаляется,
объект также будет удален, и слабый указатель станет недействительным.
Метод lock() используется для получения std::shared_ptr из std::weak_ptr с тем,
чтобы проверить, существует ли объект.

*/
#include <iostream>
#include <memory>
//===========================================================================================
// Классы
//===========================================================================================
class MyClass {
public:
    MyClass() {
        std::cout << "MyClass constructor called" << std::endl;
    }
    ~MyClass() {
        std::cout << "MyClass destructor called" << std::endl;
    }

    void doSomething() {
        std::cout << "MyClass is doing something" << std::endl;
    }
};

//===========================================================================================
// Главная программа
//===========================================================================================

int main(int argc, char *argv[])
{
     //---------------------------------------------------------------------------------------

    // Создание умного указателя shared_ptr на объект MyClass
    std::shared_ptr<MyClass> sharedPtr = std::make_shared<MyClass>();

    // Создание слабого указателя weak_ptr из shared_ptr
    std::weak_ptr<MyClass> weakPtr = sharedPtr;

    // Проверка, существует ли объект, на который указывает слабый указатель
    if (auto shared = weakPtr.lock()) {
        std::cout << "Object still exists" << std::endl;
        shared->doSomething(); // Использование объекта, на который указывает shared_ptr
    } else {
        std::cout << "Object has been deleted" << std::endl;
    }

    // Удаление shared_ptr, объект MyClass будет уничтожен
    sharedPtr.reset();

    // Попытка использовать объект через слабый указатель
    if (auto shared = weakPtr.lock()) {
        std::cout << "Object still exists" << std::endl;
        shared->doSomething();
    } else {
        std::cout << "Object has been deleted" << std::endl;
    }


    //---------------------------------------------------------------------------------------
    return 0;
}
