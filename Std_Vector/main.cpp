#include <iostream>
#include <vector>
#include <algorithm> // Для std::sort, std::for_each

int main() {
    // 1. Конструкторы
    std::vector<int> numbers; // Пустой вектор
    std::vector<int> initial_size(5); // Вектор из 5 элементов, инициализированных нулями
    std::vector<int> filled_with_twos(5, 2); // Вектор из 5 элементов, заполненных двойками
    std::vector<int> copy_vector = initial_size; // Копия вектора initial_size
    std::vector<int> init_list_vector = {1, 2, 3, 4, 5}; // Создание вектора из initializer_list
    
    std::cout << "Initial vector size: " << initial_size.size() << std::endl;
    std::cout << "filled_with_twos[0]: " << filled_with_twos[0] << std::endl;
  
    // 2. Доступ к элементам
    if (!init_list_vector.empty()){
        std::cout << "First element of init_list_vector: " << init_list_vector.front() << std::endl;
        std::cout << "Last element of init_list_vector: " << init_list_vector.back() << std::endl;
        std::cout << "Second element with []: " << init_list_vector[1] << std::endl;
        std::cout << "Second element with at(): " << init_list_vector.at(1) << std::endl;
    }
  
    // 3. Модификация вектора
    numbers.push_back(10);
    numbers.emplace_back(20);
    numbers.insert(numbers.begin(), 5);
    
    std::cout << "Modified vector: ";
    for(int n : numbers){
      std::cout << n << " ";
    }
     std::cout << std::endl;

    numbers.erase(numbers.begin());
    numbers.assign(3, 33);
    
        std::cout << "Modified vector: ";
    for(int n : numbers){
      std::cout << n << " ";
    }
     std::cout << std::endl;

    numbers.pop_back();
      std::cout << "Modified vector: ";
    for(int n : numbers){
      std::cout << n << " ";
    }
     std::cout << std::endl;

    numbers.clear();
    
    if (numbers.empty()){
        std::cout << "Vector is empty" << std::endl;
    }
  
    // 4. Получение информации о векторе
     std::cout << "Init_list_vector size: " << init_list_vector.size() << std::endl;
      std::cout << "Init_list_vector capacity: " << init_list_vector.capacity() << std::endl;

    
    // 5. Итераторы (с использованием алгоритма std::sort)
    std::vector<int> sorting = {5, 1, 4, 2, 3};
    std::sort(sorting.begin(), sorting.end());
      std::cout << "Sorted vector: ";
    std::for_each(sorting.begin(), sorting.end(), [](int n){
         std::cout << n << " ";
    });
     std::cout << std::endl;


    return 0;
}
