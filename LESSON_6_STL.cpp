//***********************КЛАССЫ ДИНАМИЧЕСКИХ АГРЕГАТОРОВ: STL*****************************//

///////////////////////КЛАСС <STRING>//////////////////////////////////////
//В этом классе память под любой объем данных распределяется автоматически

#include <string>
#include <iostream>
#include <vector>

  int main()
  {
  using namespace std;
  const char*  constCStyleString  = "Hello String!";
  cout «  "Константная строка:  " «  constCStyleString «  endl;

  std::string strFromConst(constCStyleString);  // Конструктор
  cout «  "strFromConst:  " «  strFromConst «  endl;

  std::string  str2("Hello String!");
  std::string  str2Copy(str2);
  cout «  "str2Copy:  " «  str2Copy «  endl;

  // Инициализировать строку первыми 5 символами другой строки
  std::string strPartialCopy(constCStyleString,  5);
  cout «  "strPartialCopys:  " «  strPartialCopy «  endl;

  // Инициализировать строку 10 символами  ’a'
  std::string strRepeatChars(10,  'a');
  cout «  "strRepeatChars:  " «  strRepeatChars «  endl;
  
 /////////////////////////////////////////////////////////////////////

 string sampleStr("Good day String!  Today is beautiful!");
 cout «  "Исходная строка:" «  "\n" «  sampleStr «  "\n\n";

  // Поиск "day"  - find()  возвращает позицию
  size_t  charPos  = sampleStr.find("day",  0);

  // Проверка,  что подстрока найдена...
  if  (charPos  != string::npos)
  cout «  "\"day\" найдено в позиции " «  charPos «  endl;
  else
  cout «  "Подстрока не найдена." «  endl;

  cout «  "Поиск всех подстрок \"day\"" «  endl;
  size_t  subStrPos = sampleStr.find("day",  0);

  while(subStrPos  != string::npos)
  {
  cout «  "Найден \"day\" в позиции " «  subStrPos «  endl;

  // Продолжаем поиск со следующего символа
  size_t searchOffset = subStrPos + 1;

  subStrPos = sampleStr.find("day",  searchOffset);
  }

/////////////////////////VECTOR/////////////////////////////////////
///////////------------PUSH_BACK-ВСТАВКА ВКОНЕЦ----------/////////////////////////
vector <int> integers;

  // Вставка целых чисел в вектор:
  integers.push_back(50);
  integers.push_back(1);
  integers.push_back(987);
  integers.push_back(1001);

  cout «  "Вектор содержит ";
  cout «  integers.size()  «  " элемента" «  endl;


  return 0;
  }
/////////----------INSERT-ВСТАВКА ПО ИНДЕКСУ------------///////////////////////

  void DisplayVector(const vector<int>& inVec)
  {
  for(auto element = inVec.cbegin();
  element  != inVec.cend();
  ++element  )
  cout «  *element « '  ';

  cout «  endl;
  }
  
  int main ()
  {
  // Создать экземпляр вектора с 4 элементами со значением 90
  vector <int> integers(4,  90);

  cout «  "Начальное содержимоев ектора:  ";
  DisplayVector(integers);

  // Вставить 25 в начало
  integers.insert(integers.begin(),  25);

 // Вставить в конец 2 числа со значением 45
  integers.insert(integers.end(),  2,  45);

  cout «  "Содержимое вектора после вставок:  ";
  DisplayVector(integers);

  // Другой вектор,  содержащий два элемента со значением 30
  vector <int> another(2,  30);
  // Вставить два элемента из другого контейнера в позицию  [1]
  integers.insert(integers.begin()  + 1,  another.begin(),  another.end());

  cout «  "Вектор после вставкиэ лементов  из  ";
 cout «  "другого вектора  вс редину:  " « endl;
  DisplayVector(integers);

  return 0;
  }
//К элементам вектора можно обратиться,  используя семантику  массива с операто­ром
// индексации ([ ]), с помощью функции-члена a t ()  или итераторов.

//////////////////-----------POP_BACK-УДАЛЕНИЕ-----------------////////////////////////////
 template <typename Т> // применение шаблона для создания приватного типа данных
  void DisplayVector(const vector<T>& inVec)
  {
  for(auto element = inVec.cbegin();
  element  != Input.cend();
  -f+element  )
  cout «  *element «   '  ';

  cout «  endl;
  }

  int main()
  {
  vector <int> integers;

  // Вставка в вектор целых чисел:
  integers. push__back( 50);
  integers.push_back(1);
  integers.push_back(987);
  integers.push_back(1001);

  cout «  "Вектор содержит  " «   integers.size()  «   " элемента: ";
  DisplayVector(integers);

  // Удалить один элемент в конце
  integers.pop_back();

  cout «  "После вызова pop_back()" «  endl;
  cout «  "Вектор содержит  " «   integers.size()  «   "  элемента: ";
  DisplayVector(integers);

  return 0;
  }

///////////////////////////////////DEQUE//////////////////////////////////////////////
/*
Дек —  класс deque —  является классом динамического массива библиотеки  STL, 
похожим на класс vector ,   но обеспечивающим быструю вставку и удаление элемен­
тов как в конец, так и  в начало данного массива.
*/
#include <iostream>
#include <deque>

int main() {
    std::deque<int> myDeque;

    myDeque.push_back(10); // Добавление элемента в конец
    myDeque.push_front(5); // Добавление элемента в начало

    for (int i = 0; i < myDeque.size(); i++) {
        std::cout << myDeque[i] << " "; // Вывод элементов
    }
    std::cout << std::endl;

    myDeque.pop_back(); // Удаление последнего элемента
    myDeque.pop_front(); // Удаление первого элемента

    for (int i = 0; i < myDeque.size(); i++) {
        std::cout << myDeque[i] << " "; // Вывод элементов после удаления
    }
    std::cout << std::endl;

    return 0;
}

#include <deque>
#include <iostream>
#include <algorithm>

int main ()

 {
  using namespace std;
  // Определение двухсторонней очередиц елых  чисел
  deque <int> intDeque;

  // Вставка целых чисел в конец массива
 intDeque.push_back(3);
 intDeque.push_back(4);
 intDeque.push_back(5);

  // Вставка целых чисел в начало массива
  intDeque.push_fгont(2);
  intDeque.push_front(1);
  int Deque.push_front(0);

  cout «  "Содержимое дека после вставкиэ лементов ";
  cout «  "в начало и конец:" «   endl;

  // Вьюод содержимого дека  на экран
  for(size_t count = 0;
  count < intDeque.size();  ++count  )
  {
  cout «  "Элемент!" «  count «  "]  = ";
  cout «  intDeque[count]  «  endl;
  }

 cout «  endl;
  // Извлечение элемента из  начала
  intDeque.pop_front();

  // Извлечение элемента из  конца
  intDeque.pop_back();

  cout «  "Содержимое дека после удаления элементов ";
  cout «  "из начала и из конца:" «  endl;

  //  Отображение содержимого с помощью итераторов
  //  Следующая строка - для устаревших компиляторов
  //  deque <int>::iterator element;
  for(auto element = intDeque.begin();
  element  != intDeque.end();  ++element  )
  {
  size_t offset = distance(intDeque.begin(),  element);
  cout «  "Элемент!" «  offset «  "]  = " «  ^element «  endl;
 }
return 0;
 }
 
 ////////////////////LIST/FORWARD_LIST--СПИСКИ ОДНОСВЯЗНЫЕ И ДВУХСВЯЗНЫЕ///////////////////////////////////////
 #include <iostream>
#include <list>

int main() {
    std::list<int> mylist;

    // добавление элементов в конец списка
    mylist.push_back(5);
    mylist.push_back(10);
    mylist.push_back(15);

    // добавление элементов в начало списка
    mylist.push_front(1);
    mylist.push_front(2);
    
    // удаление первого элемента
    mylist.pop_front();

    // удаление последнего элемента
    mylist.pop_back();

    // вывод списка с помощью итератора
    std::cout << "List elements: ";
    for (std::list<int>::iterator it = mylist.begin(); it != mylist.end(); ++it) {
        std::cout << *it << " ";
    }
    
    return 0;
}
 
 #include <iostream>
 #include <list>

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class DoublyLinkedList {
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void insert(int data) {
        Node* new_node = new Node(); //выделение памяти указателем под объект через оператор new
        new_node->data = data;
        new_node->next = nullptr;
        new_node->prev = tail;
        if (tail != nullptr) {
            tail->next = new_node;
        }
        tail = new_node;
        if (head == nullptr) {
            head = new_node;
        }
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

private:
    Node* head;
    Node* tail;
};

int main() {
    DoublyLinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);

    list.display();

    return 0;
}

//Как видим, списку свойственны те же команды вставки данных и их удаления, как и в vector/deque, но в отличии
//в списке можно сортировать данные например по возрастанию или убыванию
//Функция-член  sort ()  класса list  может быть вызвана без параметров:
//linklnts.sort();  // Сортировка в порядке возрастания
 #include <list> // двухсвязный список
#include <iostream>
using namespace std;

bool SortPredicate_Descending(const int& lhs,  const int& rhs)
  {
  // Определение критерия сортировки
  return  (lhs > rhs);
  }

  template <typename T>
  void DisplayContents(const T& container)
  {
  for(auto element = container.cbegin();  element  != container.cend();  ++element  )
  cout «  *element « '  ';

  cout «  endl;
  
  int main();
   {
  list <int> linklnts{  0,  -1,  2011,  444,  -5  };

  cout «  "Исходное содержимое списка:" «  endl;
  DisplayContents(linklnts);

  linklnts.sort();

  cout «  "Содержимое после sort():" «  endl;
  DisplayContents(linklnts);

  linklnts.sort(SortPredicate_Descending);
  cout «  "Содержимое после sort()  с предикатом:" «  endl;
  DisplayContents(linklnts);

  return 0;
   }


////////////////////////REVERSE-СМЕНА ПОСЛЕДОВАТЕЛЬНОСТИ///////////////////////////////////

#include <list>
#include <iostream>
using namespace std;

  template <typename T>
  void DisplayContents(const T& container)
  {
  for(auto element = container.cbegin();
  element  != container.cend();  ++element  )
  cout «  *element « '  ';

  cout «  endl;
  }

  int main()
  {
  std::list<int> linklntsf  0,  1,  2,  3,  4,  5  };

  cout «  "Исходное содержимое списка:" «  endl;
  DisplayContents(linklnts);

  linklnts.reverse();

  cout «  "Список после вызова reverse():" «  endl;
  DisplayContents(linklnts);

  return 0;
  }
  
 ////////////////////////FORWARD_LIST/////////////////////////////////////////
#include <iostream>
#include <forward_list>

int main() {
    // Создание пустого односвязного списка
    std::forward_list<int> mylist;

    // Добавление элементов в конец списка
    mylist.push_front(10);
    mylist.push_front(20);
    mylist.push_front(30);

    // Вывод элементов списка на экран
    std::cout << "Список содержит: ";
    for (int& x : mylist) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    // Удаление первого элемента списка
    mylist.pop_front();

    std::cout << "После удаления первого элемента список содержит: ";
    for (int& x : mylist) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}

/*
Однонаправленный список и двусвязный список отличаются тем, что в двусвязном списке каждый узел содержит указатели 
как на следующий, так и на предыдущий узел, а в однонаправленном списке у каждого узла есть только указатель 
на следующий узел.
*/
#include <iostream>
#include <forward_list>
struct Node {                         //применили структуру
    int data;
    Node* next;
};

class LinkedList {
public:
    LinkedList() : head(nullptr) {}

    void insert(int data) {
        Node* new_node = new Node();
        new_node->data = data;
        new_node->next = head;
        head = new_node;
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

private:
    Node* head;
};

int main() {
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);

    list.display();

    return 0;
}

