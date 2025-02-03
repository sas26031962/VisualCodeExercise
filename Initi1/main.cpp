#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
#include <any>

using Id = uint64_t;
using Buffer = std::vector<std::byte>;

enum class TypeId : Id {
    Uint,
    Float,
    String,
    Vector
};
//===================================================
// Класс Serializator
//===================================================
class Serializator {
public:
    template<typename Arg> void push(Arg&& _val);

    Buffer serialize() const;

    Buffer buf;

    static std::vector<std::byte> deserialize(const Buffer& _val);

    const std::vector<std::byte>& getStorage() const;
};

template<typename Arg> void Serializator::push(Arg&& _val)
{
    buf.push_back(_val);
}


std::vector<std::byte> Serializator::deserialize(const Buffer& _val)
{
    size_t len = _val.size();
    std::vector<std::byte> result;
    result.clear();

    std::byte * y = new std::byte;
    for(int i = 0; i <  len; i++)
    {
        memcpy(y, &_val.at(i), sizeof(std::byte));
        result.push_back(*y);
    }
    delete y;

    //std::copy(_val.begin(), _val.end(), result->begin());
    return result;    
}
Buffer Serializator::serialize() const
{
    return buf;
}

//===================================================
// Главная программа
//===================================================
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
    
    std::cout << "Result size:" << res.size() << std::endl;


    Serializator s;
    for (auto&& i : res)
        s.push(i);

    std::cout << (buff == s.serialize()) << '\n';

    return 0;
}