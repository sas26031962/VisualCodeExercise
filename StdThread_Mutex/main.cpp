//--------------------------------------------------------------------------------
// Подключаемые файлы
//--------------------------------------------------------------------------------
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

//--------------------------------------------------------------------------------
// Глобальные переменные
//--------------------------------------------------------------------------------
std::mutex mtx;
static int counter;
static const int MAX_COUNTER_VAL = 100;

//--------------------------------------------------------------------------------
// Процедуры потоков
//--------------------------------------------------------------------------------
void thread_proc(int tnum)
{
    while (true)
    {
        {        
            std::lock_guard<std::mutex>lock(mtx);//Создаёт объект lock, который блокирует mtx
            if(counter == MAX_COUNTER_VAL) 
                break;
            int ctrl_val = ++counter;    
            std::cout << "Thread " << tnum << ": counter=" << ctrl_val << std::endl;
            // В этом месте объект lock уничтожается, блокировка mtx снимается
       }    
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
     }
}

//--------------------------------------------------------------------------------
// Главная программа
//--------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
    std::vector<std::thread> threads;//Вектор из потоков

    //Инициализация вектора
    for(int i = 0; i < 10; i++)
    {
        std::thread thr(thread_proc, i);
        threads.emplace_back(std::move(thr));
    }

    for(auto& thr: threads)
    {
        thr.join();
    }
    std::cout << "Done!" << std::endl;

    return 0;
}

