#include <iostream>
#include <tuple>
#include <optional>
#include <variant>
#include <any>
#include <vector>
#include <algorithm>
#include <execution>
#include <string>

// 1. inline-переменные
inline int counter = 0;

// 2. structured bindings
std::tuple<int, std::string, double> getData() {
  return std::make_tuple(1, "data", 3.14);
}

// 3. if и switch с инициализатором
int checkValue(int value) {
    if(int temp = value * 2; temp > 100) {
      return temp;
    } else {
        return temp - 5;
    }
}

// 4. constexpr if
template <typename T>
constexpr bool isIntegral() {
  if constexpr (std::is_integral_v<T>) {
    return true;
  } else {
    return false;
  }
}

// 5. std::optional
std::optional<int> tryDivide(int a, int b) {
  if (b == 0) {
    return std::nullopt;
  } else {
    return a / b;
  }
}

// 6. std::variant
std::variant<int, double, std::string> processData(int type, double value) {
    if (type == 1) {
       return static_cast<int>(value);
    } else if (type == 2) {
        return value * 2;
    } else {
        return std::to_string(value);
    }
}

// 7. std::any
void printAny(const std::any& value){
    if (value.type() == typeid(int)) {
        std::cout << "Integer: " << std::any_cast<int>(value) << std::endl;
    } else if (value.type() == typeid(double)) {
      std::cout << "Double: " << std::any_cast<double>(value) << std::endl;
    } else if (value.type() == typeid(std::string)) {
      std::cout << "String: " << std::any_cast<std::string>(value) << std::endl;
    } else {
         std::cout << "Unknown type" << std::endl;
    }
}


int main() {
  // 1. inline-переменные
  counter++;
  std::cout << "Counter: " << counter << std::endl;
    
  // 2. structured bindings
  auto [id, name, pi] = getData();
  std::cout << "ID: " << id << ", Name: " << name << ", PI: " << pi << std::endl;

  // 3. if с инициализатором
    std::cout << "CheckValue(20): " << checkValue(20) << std::endl;
    std::cout << "CheckValue(70): " << checkValue(70) << std::endl;
    
  // 4. constexpr if
  std::cout << "isIntegral<int>: " << std::boolalpha << isIntegral<int>() << std::endl;
  std::cout << "isIntegral<double>: " << isIntegral<double>() << std::endl;

  // 5. std::optional
    auto result = tryDivide(10, 2);
  if (result) {
      std::cout << "Division result: " << *result << std::endl;
  }
  result = tryDivide(10, 0);
  if (!result) {
        std::cout << "Division failed" << std::endl;
  }

  // 6. std::variant
  std::variant<int, double, std::string> variantResult = processData(1, 20.5);
  if(std::holds_alternative<int>(variantResult)) {
    std::cout << "variant result (int): " << std::get<int>(variantResult) << std::endl;
  }
   variantResult = processData(2, 20.5);
   if(std::holds_alternative<double>(variantResult)) {
       std::cout << "variant result (double): " << std::get<double>(variantResult) << std::endl;
    }
   variantResult = processData(3, 20.5);
    if(std::holds_alternative<std::string>(variantResult)) {
       std::cout << "variant result (string): " << std::get<std::string>(variantResult) << std::endl;
   }
    
     // 7. std::any
    std::any anyValue = 10;
    printAny(anyValue);
    anyValue = 15.2;
    printAny(anyValue);
    anyValue = "some string";
    printAny(anyValue);


    // 8. Parallel STL
  std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::for_each(std::execution::par, numbers.begin(), numbers.end(), [](int& x){ x *= 2; });
  std::cout << "Parallel for_each: ";
  for (const auto& number : numbers){
    std::cout << number << " ";
  }
  std::cout << std::endl;
  return 0;
}