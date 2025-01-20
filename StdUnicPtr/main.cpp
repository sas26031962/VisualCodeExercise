/*
В этом примере std::unique_ptr используется для обеспечения безопасного владения
динамическими объектами и массивами. Когда указатель выходит из области видимости,
он автоматически удаляет свой объект, что предотвращает утечки памяти. В примере
также показано, как перемещать умные указатели с помощью std::move и как создавать
массивы с помощью std::unique_ptr.
*/

#include <iostream>
#include <memory>

class MyClass {
public:
    MyClass(int value) : data(value) {
        std::cout << "Constructor called. Data: " << data << std::endl;
    }
    ~MyClass() {
        std::cout << "Destructor called. Data: " << data << std::endl;
    }
    void printData() {
        std::cout << "Data: " << data << std::endl;
    }

private:
    int data;
};


int main(int argc, char *argv[])
{
    //----------------------------------------------------------------------------
    // Создание умного указателя unique_ptr
    std::unique_ptr<MyClass> ptr1(new MyClass(5));

    // Необходимо использовать std::move, чтобы передать управление умным указателем
    std::unique_ptr<MyClass> ptr2 = std::move(ptr1);

    // Теперь ptr1 пустой, а ptr2 указывает на созданный объект
    if (ptr1 == nullptr) {
        std::cout << "ptr1 is nullptr" << std::endl;
    }

    // Использование умного указателя для динамического создания массива
    std::unique_ptr<int[]> arrayPtr(new int[5]);
    for (int i = 0; i < 5; ++i) {
        arrayPtr[i] = i;
        std::cout << arrayPtr[i] << " ";
    }
    std::cout << std::endl;

    // Нет необходимости явно вызывать delete - память освобождается автоматически
    //----------------------------------------------------------------------------
    return 0;
}
