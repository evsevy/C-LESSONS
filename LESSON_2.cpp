//ОПЕРАЦИИ БИТОВОГО СДВИГА И АРИФМЕТИКИ=================================================================

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
