/*                                           © MERKULOV E.V. 2024
Паттерны проектирования в программировании – это bewsдал стандартных решений для типичных задач при проектировании и написании кода. 
Они помогают сделать программу более структурированной, гибкой и понятной. Ниже приведены примеры кода на языке C++ 
для некоторых из самых популярных паттернов проектирования:
*/

//1. Паттерн "Фабричный метод" (Factory Method):

#include <iostream>

class Product {
public:
    virtual void doSomething() = 0;
};

class ConcreteProduct : public Product {
public:
    void doSomething() override {
        std::cout << "ConcreteProduct is doing something" << std::endl;
    }
};

class Creator {
public:
    virtual Product* createProduct() = 0;

    void useProduct() {
        Product* product = createProduct();
        product->doSomething();
    }
};

class ConcreteCreator : public Creator {
public:
    Product* createProduct() override {
        return new ConcreteProduct();
    }
};

int main() {
    Creator* creator = new ConcreteCreator();
    creator->useProduct();

    return 0;
}

//2. Паттерн "Одиночка" (Singleton):

#include <iostream>

class Singleton {
private:
    static Singleton* instance;
    Singleton() {}

public:
    static Singleton* getInstance() {
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }

    void doSomething() {
        std::cout << "Singleton is doing something" << std::endl;
    }
};

Singleton* Singleton::instance = nullptr;

int main() {
    Singleton* singleton1 = Singleton::getInstance();
    singleton1->doSomething();

    Singleton* singleton2 = Singleton::getInstance();
    singleton2->doSomething();

    return 0;
}

//3. Паттерн "Наблюдатель" (Observer):

#include <iostream>
#include <vector>

class Observer {
public:
    virtual void update() = 0;
};

class Subject {
private:
    std::vector<Observer*> observers;

public:
    void addObserver(Observer* observer) {
        observers.push_back(observer);
    }

    void notifyObservers() {
        for (Observer* observer : observers) {
            observer->update();
        }
    }
};

class ConcreteObserver : public Observer {
public:
    void update() override {
        std::cout << "ConcreteObserver has been updated" << std::endl;
    }
};

int main() {
    Subject subject;
    ConcreteObserver observer1, observer2;

    subject.addObserver(&observer1);
    subject.addObserver(&observer2);

    subject.notifyObservers();

    return 0;
}

//Каждый паттерн имеет свои собственные особенности и применение, их можно комбинировать между собой для создания гибких и масштабируемых приложений.
