//*********************** © MERKULOV E.V. 2024********************************************//
////////////////////////КОНТЕЙНЕРЫ-STL///////////////////////////////////////////////////////////

//1. Пример использования контейнера set:

#include <iostream>
#include <set>

int main() {
    std::set<int> mySet;

    mySet.insert(5);
    mySet.insert(2);
    mySet.insert(8);

    for (auto it = mySet.begin(); it != mySet.end(); ++it) {
        std::cout << *it << " ";
    }

    return 0;
}
//-------------------------------------------------------------------------//
#include <set>
#include <iostream>

int main() {
    std::set<int> mySet = {3, 1, 4, 1, 5}; // Дубликаты будут проигнорированы
    mySet.insert(2); // Добавление элемента

    for (const auto& element : mySet) {
        std::cout << element << ' '; // 1 2 3 4 5
    }

    return 0;
}

/*
Контейнер set хранит уникальные элементы в отсортированном порядке. 
В данном примере мы добавляем элементы 5, 2 и 8 в множество, после чего выводим их на экран.
2. Пример использования контейнера multiset:
*/
#include <set>
#include <iostream>

int main() {
    std::multiset<int> myMultiset = {3, 1, 4, 1, 5};
    myMultiset.insert(1); // Добавление дубликата

    for (const auto& element : myMultiset) {
        std::cout << element << ' '; // 1 1 3 4 5
    }

    return 0;
}

#include <iostream>
#include <set>

int main() {
    std::multiset<int> myMultiset;

    myMultiset.insert(5);
    myMultiset.insert(2);
    myMultiset.insert(8);
    myMultiset.insert(5);

    for (auto it = myMultiset.begin(); it != myMultiset.end(); ++it) {
        std::cout << *it << " ";
    }

    return 0;
}

//Контейнер multiset позволяет хранить дублирующиеся элементы в отсортированном порядке. 
//В данном примере мы добавляем элементы 5, 2, 8 и еще один 5 в мультимножество, после чего выводим их на экран.

//3. Пример использования контейнера unordered_set:

#include <unordered_set>
#include <iostream>

int main() {
    std::unordered_set<int> myUnorderedSet = {3, 1, 4, 1, 5};

    myUnorderedSet.insert(2); // Добавление элемента

    for (const auto& element : myUnorderedSet) {
        std::cout << element << ' '; // 1 2 3 4 5 (неупорядоченный вывод)
    }

    return 0;
}


int main() {
    std::unordered_set<int> myUnorderedSet;

    myUnorderedSet.insert(5);
    myUnorderedSet.insert(2);
    myUnorderedSet.insert(8);

    for (auto it = myUnorderedSet.begin(); it != myUnorderedSet.end(); ++it) {
        std::cout << *it << " ";
    }

    return 0;
}

//Контейнер unordered_set хранит уникальные элементы в неотсортированном порядке. 
//В данном примере мы добавляем элементы 5, 2 и 8 в множество, после чего выводим их на экран.

//4. Пример использования контейнера unordered_multiset:

#include <unordered_set>
#include <iostream>

int main() {
    std::unordered_multiset<int> myUnorderedMultiset = {3, 1, 4, 1, 5};
    myUnorderedMultiset.insert(1); // Добавление дубликата

    for (const auto& element : myUnorderedMultiset) {
        std::cout << element << ' '; // 1 1 3 4 5 (неупорядоченный вывод)
    }

    return 0;
}


#include <iostream>
#include <unordered_set>

int main() {
    std::unordered_multiset<int> myUnorderedMultiset;

    myUnorderedMultiset.insert(5);
    myUnorderedMultiset.insert(2);
    myUnorderedMultiset.insert(8);
    myUnorderedMultiset.insert(5);

    for (auto it = myUnorderedMultiset.begin(); it != myUnorderedMultiset.end(); ++it) {
        std::cout << *it << " ";
    }

    return 0;
}
/*
Контейнер unordered_multiset позволяет хранить дублирующиеся элементы в неотсортированном порядке. 
В данном примере мы добавляем элементы 5, 2, 8 и еще один 5 в мультимножество, после чего выводим их на экран. 
Эти контейнеры широко используются в программировании для хранения уникальных или дублирующихся элементов 
и обеспечения быстрого доступа к данным.
*/

///////////////////////////////////////////MAP/////////////////////////////////////////////////////
#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> myMap;

    // Добавление элементов в map
    myMap.insert({1, "one"});
    myMap.insert({2, "two"});
    myMap.insert({3, "three"});

    // Итерация по элементам map
    for (auto const& pair : myMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}

//Map используется для хранения пар ключ-значение, где каждому ключу соответствует только одно значение.
//2. Пример использования unordered_map:

#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<std::string, int> myMap;

    // Добавление элементов в unordered_map
    myMap["one"] = 1;
    myMap["two"] = 2;
    myMap["three"] = 3;

    // Итерация по элементам unordered_map
    for (auto const& pair : myMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}

//Unordered_map также хранит пары ключ-значение, но не гарантирует порядок элементов.
//3. Пример использования multimap:

#include <iostream>
#include <map>

int main() {
    std::multimap<int, std::string> myMap;

    // Добавление элементов в multimap
    myMap.insert({1, "one"});
    myMap.insert({2, "two"});
    myMap.insert({1, "uno"});

    // Итерация по элементам multimap
    for (auto const& pair : myMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}

//Multimap позволяет хранить несколько значений для одного ключа.
//4. Пример использования unordered_multimap:

#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_multimap<std::string, int> myMap;

    // Добавление элементов в unordered_multimap
    myMap.insert({"one", 1});
    myMap.insert({"two", 2});
    myMap.insert({"one", 111});

    // Итерация по элементам unordered_multimap
    for (auto const& pair : myMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}

//Unordered_multimap также позволяет хранить несколько значений для одного ключа, без гарантии порядка элементов.

///////////////////////////////////////ALGORITHM////////////////////////////////////////////////////////////
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 5, 3, 7, 2, 4, 6};

    // Сортировка в порядке возрастания
    std::sort(numbers.begin(), numbers.end());
    
    // Вывод отсортированного вектора
    for(int num : numbers) {
        std::cout << num << " ";
    }

    return 0;
}

// Программа сортирует вектор с помощью функции std::sort из STL.

#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 5, 3, 7, 2, 4, 6};

    // Удаление элемента со значением 3
    numbers.erase(std::remove(numbers.begin(), numbers.end(), 3), numbers.end());
    
    // Вывод вектора без удаленного элемента
    for(int num : numbers) {
        std::cout << num << " ";
    }

    return 0;
}

// Программа удаляет из вектора элемент со значением 3 с помощью функций std::remove и std::erase из STL.
