#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
<<<<<<< HEAD
#include <algorithm>
#include <memory>
#include <charconv>
=======
#include <any>
>>>>>>> sas26031962/main

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
<<<<<<< HEAD
//=================================
class Serializator 
{
    std::array<char, 10> res;

    Buffer buf;//Область данных
public:
    //Конструктор
    Serializator();

    //Деструктор
    ~Serializator();

    //Методы
    std::array<char, 10> charToString(int x);
    
=======
//===================================================
class Serializator {
public:
>>>>>>> sas26031962/main
    template<typename Arg> void push(Arg&& _val);

    Buffer serialize() const;

    Buffer buf;

    static std::vector<std::byte> deserialize(const Buffer& _val);

    const std::vector<std::byte>& getStorage() const;
};

<<<<<<< HEAD
Serializator::Serializator()
{
    //...    
}

Serializator::~Serializator()
{
    //...    
}

const std::vector<std::byte>& Serializator::getStorage() const
{
    return buf;
}

Buffer Serializator::serialize() const
{
    int iStringPosition = 0;
    int iRowNumber = 0;
    const int iStringWwidth = 16;
    std::string sLine = "";
    for(std::byte f : buf)
    {
        //std::byte l;// = 0;
        //charToString(l);
        sLine.append("55: ");
        iStringPosition++;
        if(iStringPosition == iStringWwidth)  
        {
            std::cout << sLine << std::endl;
            iStringPosition = 0;
            sLine.clear();
        }
    }

    return buf;
}

std::array<char, 10> Serializator::charToString(int x)
{
    std::to_chars(res.begin(), res.end(), x, 16);
    return res;
}

=======
>>>>>>> sas26031962/main
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