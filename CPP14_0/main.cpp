/*
Generic Lambdas - пример использования
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

template <typename T>
void printVector(const std::vector<T>& vec) {
    std::for_each(vec.begin(), vec.end(), [](const auto& element){
        std::cout << element << " ";
    });
  std::cout << std::endl;
}

int main() {
  std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::cout << "Integers : ";
  printVector(numbers);

  std::vector<double> doubles = {1.1, 2.2, 3.3, 4.4, 5.5};
    std::cout << "Doubles : ";
  printVector(doubles);

  std::vector<std::string> strings = {"apple", "banana", "cherry"};
    std::cout << "Strings : ";
  printVector(strings);
    
     std::cout << "Using lambda directly: ";
    std::for_each(numbers.begin(), numbers.end(), [](const auto& element){
        std::cout << element * 2 << " ";
    });
  std::cout << std::endl;

    std::cout << "Using lambda directly: ";
  std::for_each(doubles.begin(), doubles.end(), [](const auto& element){
      std::cout << element * 2 << " ";
  });
  std::cout << std::endl;

  return 0;
}