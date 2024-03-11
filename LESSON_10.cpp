//////////////////////////////////////////TEMPLATES--ШАБЛОНЫ///////////////////////////////////////////////
//************************************** © MERKULOV E.V. 2024********************************************//

//**1. Шаблон функции:**

#include <iostream>

template <typename T> //вместо Т может быть произвольное наименование пользовательского типа данных
T maximum(T a, T b)
 {
    return (a > b) ? a : b;
}

int main() {
    std::cout << maximum(5, 10) << std::endl; // выводит 10
    std::cout << maximum(3.14, 2.71) << std::endl; // выводит 3.14
    return 0;
}

//**2. Шаблон класса:**

#include <iostream>

template <typename T>
class Pair {
public:
    Pair(T first, T second) : m_first(first), m_second(second) // конструктор класса
	{}

    T getFirst() const { return m_first; }
    T getSecond() const { return m_second; }

private:
    T m_first;
    T m_second;
};

int main() {
    Pair<int> intPair(10, 20);
    std::cout << intPair.getFirst() << ", " << intPair.getSecond() << std::endl; // выводит 10, 20

    Pair<double> doublePair(3.14, 2.71);
    std::cout << doublePair.getFirst() << ", " << doublePair.getSecond() << std::endl; // выводит 3.14, 2.71

    return 0;
}

//**3. Шаблон функции с несколькими параметрами:**

#include <iostream>

template <typename T, typename U> // двойной шаблон
T add(T a, U b) {
    return a + b;
}

int main() {
    std::cout << add(5, 10.5) << std::endl; // выводит 15.5
    return 0;
}

//**4. Частичная специализация шаблона класса:**

#include <iostream>

template <typename T, typename U>
class Pair {
public:
    Pair(T first, U second) : m_first(first), m_second(second) {}

    void print() {
        std::cout << "(" << m_first << ", " << m_second << ")" << std::endl;
    }

private:
    T m_first;
    U m_second;
};

template <typename T>
class Pair<T, T> {
public:
    Pair(T first, T second) : m_first(first), m_second(second) {}

    void print() {
        std::cout << "[" << m_first << ", " << m_second << "]" << std::endl;
    }

private:
    T m_first;
    T m_second;
};

int main() {
    Pair<int, double> pair1(10, 3.14);
    pair1.print(); // выводит (10, 3.14)

    Pair<int, int> pair2(5, 5);
    pair2.print(); // выводит [5, 5]

    return 0;
}

//Шаблоны в C++позволяют писать универсальный код, который может работать с разными типами данных.
//Они обеспечивают максимальное удобство и гибкость при работе с различными типами данных.
//Динамически распределяют память для различных типов данных
