#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>

using Id = uint64_t;
using Buffer = std::vector<std::byte>;

enum class TypeId : Id {
    Uint,
    Float,
    String,
    Vector
};

//=================================
// Класс Serializator
//=================================
class Serializator 
{
    Buffer buf;//Область данных
public:
    //Методы
    template<typename Arg> void push(Arg&& _val);

    Buffer serialize() const;

    static std::vector<std::byte> deserialize(const Buffer& _val);

    const std::vector<std::byte>& getStorage() const;
};

std::vector<std::byte> Serializator::deserialize(const Buffer& _val)
{
    std::vector<std::byte> result;
    result.clear();
    std::byte * x = new std::byte;
    for(size_t i = 0; i < _val.size(); i++)
    {
        std::memcpy(&x, &_val.at(i), sizeof(std::byte));
        result.push_back(*x);
    }
    delete x;

    return result;    
}

int main() {

    std::cout << "Open file:" << "raw.bin" << std::endl;
    
    std::ifstream raw;
    raw.open("raw.bin", std::ios_base::in | std::ios_base::binary);
    if (!raw.is_open())
        return 1;
    raw.seekg(0, std::ios_base::end);
    std::streamsize size = raw.tellg();
    raw.seekg(0, std::ios_base::beg);

    Buffer buff(size);
    raw.read(reinterpret_cast<char*>(buff.data()), size);

    std::cout << "Buffer size:" << buff.size() << std::endl;

    auto res = Serializator::deserialize(buff);
/*
    Serializator s;
    for (auto&& i : res) s.push(i);

    std::cout << (buff == s.serialize()) << '\n';
*/
    return 0;
}