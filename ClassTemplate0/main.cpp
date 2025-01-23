#include <iostream>
#include <array>

template <typename T, int SIZE>
class MyArray {
public:
    MyArray() = default;
    MyArray(const std::array<T, SIZE>& arr) : arr_(arr) {}

    void print() const {
      for(const auto& element: arr_) {
         std::cout << element << " ";
      }
        std::cout << std::endl;
    }

private:
    std::array<T, SIZE> arr_;
};

int main() {
    std::array<int, 5> my_int_arr = {1,2,3,4,5};
    MyArray<int, 5> myArrayInt(my_int_arr);
    myArrayInt.print();

     std::array<double, 3> my_double_arr = {1.1,2.2,3.3};
     MyArray<double, 3> myArrayDouble(my_double_arr);
     myArrayDouble.print();
    return 0;
}
