#include <iostream>
#include <iterator>
#include <fstream>
#include <regex>
#include <string>

int readLines()
{
    int count = -1;

    //std::regex self_regex("^.*");//Любая строка
    //std::regex self_regex("^DO#.*");//Выходные сигналы
    std::regex self_regex("^DO#.*O_.*");//Неиспользуемые выходные сигналы
  
    std::string line;
    std::fstream in("wires.txt");

    if(in.is_open())
    {
        count = 0;

        while (std::getline(in, line))
        {
            if (std::regex_search(line, self_regex))
            {
                std::cout << line << std::endl;
                count++;
            }
        }
        
    }
    in.close();

    return count;
}

int main()
{
    int Error = 0;
    int LinesCount = readLines();
     
    if(LinesCount < 0) Error++; 

    std::cout << "Read effective lines: " << LinesCount << std::endl;


 /*   
    std::string s = "Some people, when confronted with a problem, think "
        "\"I know, I'll use regular expressions.\" "
        "Now they have two problems.";
 
    std::regex self_regex("REGULAR EXPRESSIONS",
        std::regex_constants::ECMAScript | std::regex_constants::icase);
    if (std::regex_search(s, self_regex))
        std::cout << "Text contains the phrase 'regular expressions'\n";
 
    std::regex word_regex("(\\w+)");
    auto words_begin = 
        std::sregex_iterator(s.begin(), s.end(), word_regex);
    auto words_end = std::sregex_iterator();
 
    std::cout << "Found "
              << std::distance(words_begin, words_end)
              << " words\n";
 
    const int N = 6;
    std::cout << "Words longer than " << N << " characters:\n";
    for (std::sregex_iterator i = words_begin; i != words_end; ++i)
    {
        std::smatch match = *i;
        std::string match_str = match.str();
        if (match_str.size() > N)
            std::cout << "  " << match_str << '\n';
    }
 
    std::regex long_word_regex("(\\w{7,})");
    std::string new_s = std::regex_replace(s, long_word_regex, "[$&]");
    std::cout << new_s << '\n';
    */

    return Error;
}