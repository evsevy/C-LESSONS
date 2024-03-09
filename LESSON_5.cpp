//*********************** © MERKULOV E.V. 2024********************************************//
//***************8Класс ООП на C++ с private, protected и конструктором:******************//

#include <iostream>
using namespace std;

class MyClass {
private:
    int privateVar;
protected:
    int protectedVar;
public:
    // Конструктор класса MyClass
    MyClass(int privateVal, int protectedVal) {
        privateVar = privateVal;
        protectedVar = protectedVal;
    }
    
    void displayValues() {
        cout << "Private variable: " << privateVar << endl;
        cout << "Protected variable: " << protectedVar << endl;
    }
};

int main() {
    // Создание объекта класса MyClass с передачей значений конструктору
    MyClass obj(10, 20);
    
    obj.displayValues();

    return 0;
}
/*
Описание:
- `private`: Переменные или методы, объявленные как private, могут быть доступны только внутри класса. 
В данном примере переменная `privateVar` доступна только внутри класса MyClass.
- `protected`: Переменные или методы, объявленные как protected, доступны только внутри самого класса и его наследуемых классов. 
В данном примере переменная `protectedVar` доступна внутри класса MyClass и любого класса, наследующего от MyClass.
- Конструктор класса `MyClass` принимает два аргумента типа int и инициализирует значения privateVar и protectedVar соответственно.
- Метод `displayValues()` выводит значения privateVar и protectedVar на экран.
- В функции `main` создается объект `obj` класса `MyClass` с передачей значений в конструктор.
- Затем вызывается метод `displayValues()`, который выводит значения privateVar и protectedVar объекта `obj`.
Таким образом, private, protected и конструкторы используются для обеспечения инкапсуляции, ограничивая доступ 
к переменным и методам класса и устанавливая их значения при создании объекта класса.
*/

//Пример кода наследования класса с приватным и защищенным конструктором в C++:

#include <iostream>

// Базовый класс
class Base {
private:
    int privateData;

protected:
    int protectedData;

    Base(int privateValue, int protectedValue)
        : privateData(privateValue), protectedData(protectedValue) {
    }

public:
    void showData() {
        std::cout << "Private data: " << privateData << ", Protected data: " << protectedData << std::endl;
    }
};

// Класс-наследник
class Derived : public Base {
public:
    Derived(int privateValue, int protectedValue)
        : Base(privateValue, protectedValue) {
    }

    void showProtectedData() {
        std::cout << "Protected data from derived class: " << protectedData << std::endl;
    }
};

int main() {
    // Создаем объект класса-наследника
    Derived derivedObj(5, 10);
    
    // Вызываем метод вывода данных из базового класса
    derivedObj.showData();
    
    // Вызываем метод вывода защищенных данных из класса-наследника
    derivedObj.showProtectedData();

    return 0;
}
/*
В данном примере у базового класса `Base` есть приватное поле `privateData` и защищенное поле `protectedData`, 
а также конструктор с параметрами, и доступные методы для доступа к данным. 
Класс-наследник `Derived` наследуется от базового класса и имеет доступ к защищенным полям базового класса.
*/
