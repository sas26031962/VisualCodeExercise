#include <iostream>
#include <array>
#include <numeric>


int main() {
    std::array<int, 5> arr = {1, 2, 3, 4, 5};

    // Суммирование элементов с помощью fold expression
    int sum = 0;
    sum = (arr[0] + arr[1] + arr[2] + arr[3] + arr[4]);
    std::cout << "Sum (fold expression): " << sum << std::endl;


    //Суммирование элементов с помощью accumulate
    sum = std::accumulate(arr.begin(), arr.end(), 0);
    std::cout << "Sum (accumulate): " << sum << std::endl;
    return 0;
}
