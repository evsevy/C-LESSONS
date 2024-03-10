Библиотека <atomic> в C++ предоставляет возможность работы с атомарными операциями, то есть операциями, 
которые гарантируют атомарность выполнения без возможности прерывания другими потоками. 
Это позволяет избежать проблем с состоянием разделяемых переменных при многопоточном программировании.


//1. Пример использования атомарной переменной типа int:

#include <iostream>
#include <thread>
#include <atomic>

std::atomic<int> counter(0);

void incrementCounter() {
    for (int i = 0; i < 10000; ++i) {
        counter++;
    }
}

int main() {
    std::thread t1(incrementCounter);
    std::thread t2(incrementCounter);

    t1.join();
    t2.join();

    std::cout << "Counter value: " << counter << std::endl;

    return 0;
}

//2. Пример использования атомарной операции для обновления переменной типа int:

#include <iostream>
#include <atomic>

int main() {
    std::atomic<int> value(5);

    value.fetch_add(3);

    std::cout << "Value: " << value << std::endl;

    return 0;
}

