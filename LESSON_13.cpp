/******************************************************************************
               КЛАССИФИКАТОРЫ И ПОЛЬЗОВАТЕЛЬСКИЕ ТИПЫ ДАННЫХ
*******************************************************************************/

//1. Structures (Структуры) - набор переменных разных типов, объединенных в одну структуру. 
//Можно создавать пользовательские типы данных, объединяя несколько переменных в одну структуру.

struct Person {
    string name;
    int age;
};

//2. Enumerations (Перечисления) - набор именованных целочисленных констант. 
//Позволяют создать новый тип данных, который может принимать только определенные значения.

enum Weekday {
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};

//3. Typedefs (Псевдонимы типов) - позволяют создать синоним для существующего типа данных. 
//Удобно использовать для упрощения и улучшения читаемости кода.

typedef int Score;
Score playerScore = 100;

//1. Определение пользовательского типа данных с использованием typedef:

typedef int Age;
Age myAge = 25;

//2. Использование typedef для создания псевдонима для массива:

typedef int NumberArray[5];
NumberArray arr = {1, 2, 3, 4, 5};

//3. Определение псевдонима для указателя на функцию:

typedef void (*FunctionPtr)(int);
void myFunction(int num) {
    // Some code
}
FunctionPtr ptr = &myFunction;

//4. Создание псевдонима для указателя на класс:

class MyClass {
    // Class definition
};
typedef MyClass* MyClassPtr;
MyClassPtr ptr = new MyClass();

//5. Использование typedef для упрощения работы с сложными типами данных, 
//например для работы с указателями на сложные структуры данных:

typedef std::vector<std::pair<int, std::string>> PairVector;
PairVector pairs;
pairs.push_back(std::make_pair(1, "one"));

//4. Classes (Классы) - объектно-ориентированный подход к созданию пользовательских типов данных. Классы объединяют данные (поля) и методы (функции), которые могут оперировать этими данными.

class Rectangle {
private:
    int width;
    int height;
public:
    Rectangle(int w, int h) : width(w), height(h) {}
    int getArea() { return width * height; }
};

//5. Unions (Объединения) - это специальный тип данных, который позволяет использовать одну область памяти для хранения нескольких переменных разных типов. В отличие от структур, в объединениях данные разделяют одну и ту же область памяти.

union Number {
    int intValue;
    double doubleValue;
};

//1. Пример использования enum для определения дней недели:

#include <iostream>

enum DaysOfWeek {
    Monday, 
    Tuesday, 
    Wednesday, 
    Thursday, 
    Friday, 
    Saturday, 
    Sunday
};

int main() {
    DaysOfWeek today = Tuesday;

    if(today == Friday || today == Saturday) {
        std::cout << "It's the weekend!" << std::endl;
    } else {
        std::cout << "It's a weekday." << std::endl;
    }

    return 0;
}

//2. Пример использования enum class для определения цветов:


#include <iostream>

enum class Color {
    Red,
    Green,
    Blue
};

int main() {
    Color myColor = Color::Green;

    switch (myColor) {
        case Color::Red:
            std::cout << "The color is red." << std::endl;
            break;
        case Color::Green:
            std::cout << "The color is green." << std::endl;
            break;
        case Color::Blue:
            std::cout << "The color is blue." << std::endl;
            break;
    }

    return 0;
}

#include <iostream>

// Определение структуры с разными типами данных
struct Example {
    int integer;
    float decimal;
    char character;
};

// Определение перечисления с разными типами данных
enum DataType {
    INTEGER,
    DECIMAL,
    CHARACTER
};

int main() {
    Example ex1;
    ex1.integer = 10;
    ex1.decimal = 3.14;
    ex1.character = 'A';

    std::cout << "Integer: " << ex1.integer << std::endl;
    std::cout << "Decimal: " << ex1.decimal << std::endl;
    std::cout << "Character: " << ex1.character << std::endl;

    // Использование перечисления для выбора типа данных
    DataType type = INTEGER;

    switch (type) {
        case INTEGER:
            std::cout << "Selected data type: Integer" << std::endl;
            break;
        case DECIMAL:
            std::cout << "Selected data type: Decimal" << std::endl;
            break;
        case CHARACTER:
            std::cout << "Selected data type: Character" << std::endl;
            break;
        default:
            std::cout << "Invalid data type" << std::endl;
    }

    return 0;
}
//1. Пример структуры в C++:

#include <iostream>

struct Point {
    int x;
    int y;
};

int main() {
    Point p;
    p.x = 10;
    p.y = 20;

    std::cout << "Point coordinates: (" << p.x << ", " << p.y << ")" << std::endl;

    return 0;
}

//2. Пример класса с использованием наследования, инкапсуляции и доступом к данным через модификаторы public, private и protected:

#include <iostream>

class Shape {
public:
    void printType() {
        std::cout << "This is a shape" << std::endl;
    }

protected:
    int width;
    int height;
};

class Rectangle: public Shape {
public:
    void setDimensions(int w, int h) {
        width = w;
        height = h;
    }

    void printArea() {
        std::cout << "Rectangle area: " << width * height << std::endl;
    }
};

int main() {
    Rectangle r;
    r.setDimensions(5, 10);
    r.printType();
    r.printArea();

    return 0;
}

//3. Пример полиморфизма в C++ с использованием виртуальных функций:

#include <iostream>

class Animal {
public:
    virtual void makeSound() {
        std::cout << "Animal makes a sound" << std::endl;
    }
};

class Dog : public Animal {
public:
    void makeSound() override {
        std::cout << "Dog barks" << std::endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() override {
        std::cout << "Cat meows" << std::endl;
    }
};

int main() {
    Animal* animal1 = new Dog();
    Animal* animal2 = new Cat();

    animal1->makeSound();
    animal2->makeSound();

    delete animal1;
    delete animal2;

    return 0;
}
/*
В этом примере показано как создать базовый класс Animal и производные классы Dog и Cat, 
которые переопределяют виртуальную функцию makeSound(). 
При вызове этой функции у объектов animal1 и animal2 будет выполнена соответствующая реализация
функции в классах Dog и Cat.
*/
