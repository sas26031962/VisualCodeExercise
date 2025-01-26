#include <iostream>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

int main() {
    fs::path p("/tmp/my_file.txt"); // Создание пути

    if (fs::exists(p)) {
        std::cout << "File exists: " << p << std::endl;
    } else {
        std::cout << "File does not exist: " << p << std::endl;
    }

    try {
        fs::create_directories(p.parent_path()); //Создать директории если их нет
        std::ofstream file(p);
        file << "Hello from C++17 filesystem!" << std::endl;
    } catch(const fs::filesystem_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
