//*******************************************************************************************************//
//ОПЕРАЦИИ БИТОВОГО СДВИГА И АРИФМЕТИКИ=================================================================
//*******************************************************************************************************//
//Битовый сдвиг влево (<<):

#include <iostream>
using namespace std;

int main() {
    int x = 5; // 0000 0101
    int result = x << 2; // сдвигаем биты на 2 позиции влево
    cout << result << endl; // выводим результат: 0001 0100 (20 в десятичной системе)
    return 0;
}

//Битовый сдвиг вправо (>>):

#include <iostream>
using namespace std;

int main() {
    int x = 20; // 0001 0100
    int result = x >> 2; // сдвигаем биты на 2 позиции вправо
    cout << result << endl; // выводим результат: 0000 0101 (5 в десятичной системе)
    return 0;
}

//Битовая арифметика OR (|), AND (&), XOR (^):

#include <iostream>
using namespace std;

int main() {
    int x = 5; // 0000 0101
    int y = 3; // 0000 0011
    
    int result_or = x | y; // OR: 0000 0111 (7 в десятичной системе)
    int result_and = x & y; // AND: 0000 0001 (1 в десятичной системе)
    int result_xor = x ^ y; // XOR: 0000 0110 (6 в десятичной системе)
    
    cout << result_or << endl;
    cout << result_and << endl;
    cout << result_xor << endl;
    
    return 0;
}

/*
Числа с плавающей точкой в битовой памяти представляются с использованием стандарта IEEE 754. 
Этот стандарт определяет формат хранения чисел с плавающей точкой, включая одинарной и двойной точности.

В формате одинарной точности (32 бита) число с плавающей точкой состоит из следующих компонентов:
- 1 бит для знака
- 8 бит для экспоненты
- 23 бит для мантиссы

В формате двойной точности (64 бита) число с плавающей точкой состоит из следующих компонентов:
- 1 бит для знака
- 11 бит для экспоненты
- 52 бит для мантиссы

Битовая память представляется в виде нулей и единиц, 
которые используются для хранения значений каждого из компонентов числа с плавающей точкой. 
С помощью этих битов можно представить числа с различными значениями и точностью.
*/

/*
У типов данных существуют диапазоны и разряды памяти для ее эффективного использования и распределения. 

*/
#include <iostream>

int main() {
    unsigned int num = 10; // беззнаковый тип данных расширяет диапазон битов для положительных чисел.
    std::cout << "Unsigned Integer: " << num << std::endl;
    return 0;
}

//1. `int32`: это тип данных, который используется для хранения целых чисел со знаком, занимающих 32 бита в памяти. 
//Он может содержать значения от -2,147,483,648 до 2,147,483,647. Пример использования:

int32_t x = 5000;

//2. `uint`: это тип данных, который используется для хранения целых чисел без знака. 
//Он также может содержать 32 бита в памяти и может хранить значения от 0 до 4,294,967,295. Пример использования:

uint y = 10000;
/*
int32_t - это тип данных в языке программирования C++, который представляет собой 32-битное знаковое целое число. 
    Примеры использования int32_t в C++ могут включать в себя следующее:
1. Хранение значений, которые должны быть в диапазоне от -2,147,483,648 до 2,147,483,647. 
    Например, это может быть использовано для представления возраста человека, количества товаров на складе или номера телефона.
2. Подсчет и выполнение математических операций с целыми числами. Например, int32_t может использоваться для хранения результата сложения, 
    вычитания или умножения двух целых чисел.
3. Работа с памятью и массивами данных. Например, int32_t может быть использован для указания размера массива или индекса элемента в массиве.
В целом, int32_t является удобным типом данных для работы с 32-битными целыми числами в C++ и позволяет эффективно использовать память и 
    выполнять операции с данными.
*/
/*
Управление памятью в C++ является одним из ключевых аспектов программирования на этом языке. 
Память в программе выделяется и освобождается с помощью операторов new и delete. 
- int32_t, uint18_t, float64, double64, long128 - это типы данных, 
 которые используются для объявления переменных различных размеров в битах: int32_t - целое число со знаком на 32 бита, 
 uint18_t - целое число без знака на 18 бит, float64 - число с плавающей точкой на 64 бита и т.д.
    */

//Пример кода для выделения памяти и освобождения для указателей:
// Пример для типа int32_t
int32_t* ptr = new int32_t; // выделение памяти для переменной типа int32_t
*ptr = 10; // сохранение значения в выделенной памяти
delete ptr; // освобождение памяти

// Пример для массива типа float64
int size = 5;
float64* arr = new float64[size]; // выделение памяти для массива типа float64
for (int i = 0; i < size; i++) {
    arr[i] = i * 2.5; // сохранение значений в выделенной памяти
}
delete[] arr; // освобождение памяти
/*
Кроме операторов new и delete, 
в C++ также можно использовать умные указатели (smart pointers), 
такие как std::unique_ptr и std::shared_ptr, которые автоматически управляют памятью и освобождают ее при выходе из области видимости. 
Вот пример использования std::unique_ptr: */
std::unique_ptr<int32_t> ptr(new int32_t); // выделение памяти с помощью умного указателя
*ptr = 10; // сохранение значения в выделенной памяти
// память будет автоматически освобождена при выходе из области видимости

Управление памятью важно для предотвращения утечек памяти и ошибок при работе с динамической памятью в C++. 
Поэтому важно правильно выделять память и освобождать ее в нужное время.  
//==================================ГЛОБАЛЬНЫЕ И ЛОКАЛЬНЫЕ ПЕРЕМЕННЫЕ=================================================================//
 #include <iostream>
using namespace std;

// Глобальные и локальные переменные. Операция ::

// Объявить глобальную переменную d.
// Эта переменная доступна в обеих функциях: Global() и main()
int d = 15;

// Прототип функции, умножающей глобальную переменную d на 2
int Global(void);

void main()
{
  // Объявить локальную переменную d в функции main()
  int d;

  // 1. Вывести значение локальной переменной d
  d = 25;

  cout << "Local: d = " << d << endl; // d = 25 - локальная переменная переопределяет глобальную переменную

  // 2. Вывести значение глобальной переменной d,
  //    используется операция :: - расширение области видимости
  cout << "Global: d = " << ::d << endl;

  // 3. Вывести удвоенное значение глобальной переменной d
  cout << "Global: d*2 = " << Global() << endl; // d*2 = 30

  // 4. Записать в локальную переменную d новое значение 27
  d = 27;
  cout << "Local: d = " << d << endl;

  // 5. Записать в глобальную переменную d новое значение 68
  ::d = 68;
  cout << "Global: d = " << ::d << endl; // глобальная переменная d = 68

  // 6. Вывести удвоенное значение глобальной переменной ::d
  cout << "Global d * 2 = " << Global() << endl; // будет выведено 136
}

// Функция, которая использует значение глобальной переменной d.
// К локальной переменной d в функції main() эта функция доступа не имеет
int Global(void)
{
  // здесь доступна глобальная переменная d
  return d * 2;
}   
//===========================================БУЛЕВЫЕ ТИПЫ ДАННЫХ============================================================================//
//Пример применения булевых типов данных с циклами и ветвлениями в языке С++:

//1. Логическое И (&&):

bool a = true;
bool b = false;

if (a && b) {
    // Код выполнится только если оба выражения истина
    cout << "Оба выражения истинны" << endl;
} else {
    cout << "Хотя бы одно из выражений ложно" << endl;
}

//2. Логическое ИЛИ (||):

bool a = true;
bool b = false;

if (a || b) {
    // Код выполнится если хотя бы одно из выражений истинно
    cout << "Хотя бы одно из выражений истинно" << endl;
} else {
    cout << "Оба выражения ложны" << endl;
}

//3. Логическое НЕ (!):

bool a = true;

if (!a) {
    // Код выполнится если выражение ложно
    cout << "Выражение ложно" << endl;
} else {
    cout << "Выражение истинно" << endl;
}

#include <iostream>

int main() {
    while (true) {
        std::cout << "Этот цикл выполняется бесконечно!" << std::endl;
    }

    return 0;
}

#include <iostream>

int main() {
    bool isEven; // объявляем переменную типа bool для проверки четности числа
    int number;

    std::cout << "Введите число: ";
    std::cin >> number;

    if (number % 2 == 0) {
        isEven = true; // если число четное, переменная isEven будет равна true
    } else {
        isEven = false; // если число нечетное, переменная isEven будет равна false
    }

    // используем цикл для вывода сообщения о четности числа
    for (int i = 0; i < 3; i++) {
        if (isEven) {
            std::cout << "Число " << number << " четное" << std::endl;
        } else {
            std::cout << "Число " << number << " нечетное" << std::endl;
        }
    }

    return 0;
}
/*
В данном примере мы объявляем переменную типа bool для проверки четности числа, запрашиваем у пользователя число, 
проверяем его на четность и записываем результат в переменную isEven. 
Затем используем цикл for для вывода сообщения о четности числа на экран несколько раз.
*/

//==============================================================================================================================//

/*
Данный код позволяет создать класс `Rocket`, который рассчитывает силу ударной волны на конструкцию ракеты
 для различных высот на основе заданной скорости и плотности атмосферы. 
 В функции `main` создается объект класса `Rocket`, вызывается метод `calculateShockWaveForces`, 
который рассчитывает силу ударной волны для каждой высоты, 
и запускается новый поток для вывода результатов с помощью метода `printShockWaveForces`.
*/
#include <iostream>
#include <vector>
#include <thread>
#include <cmath>

class Rocket {
private:
    double velocity;
    std::vector<double> altitudes;
    std::vector<double> shockWaveForces;

public:
    Rocket(double vel, const std::vector<double>& alts) : velocity(vel), altitudes(alts) {}

    void calculateShockWaveForces() {
        if (altitudes.empty()) {
            return;
        }

        for (double alt : altitudes) {
            double density = getDensity(alt);
            double force = 0.5 * density * velocity * velocity;
            shockWaveForces.push_back(force);
        }
    }

    double getDensity(double altitude) {
        // Добавьте соответствующую формулу для расчета плотности атмосферы в зависимости от высоты
        return 1.225 * exp(-altitude / 8000);
    }

    void printShockWaveForces() {
        for (int i = 0; i < altitudes.size(); i++) {
            std::cout << "Shock wave force at altitude " << altitudes[i] << " m: " << shockWaveForces[i] << " N" << std::endl;
        }
    }
};

int main() {
    double velocity = 8000; // км/ч
    std::vector<double> altitudes = {1000, 5000, 10000, 20000, 40000}; // м

    Rocket rocket(velocity, altitudes);
    rocket.calculateShockWaveForces();

    std::thread t(&Rocket::printShockWaveForces, &rocket);
    t.join();

    return 0;
}
