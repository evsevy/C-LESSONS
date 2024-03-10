///////////////////////////////////////////BOOST///////////////////////////////////////////////////////////
//************************************** © MERKULOV E.V. 2024********************************************//

/*
Класс Boost в библиотеке Boost C++ предоставляет различные возможности для улучшения производительности и 
расширения функциональности языка C++. Например, Boost содержит множество классов и функций для работы с потоками, 
многопоточностью, итераторами, шаблонами и другими аспектами разработки на C++.
*/

#include <boost/foreach.hpp>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    BOOST_FOREACH(int i, vec) {
        std::cout << i << std::endl;
    }

    return 0;
}
/*
В данном примере используется макрос `BOOST_FOREACH`, который позволяет удобно перебирать элементы контейнера. 
Этот макрос является частью библиотеки Boost.Foreach, которая предоставляет удобный синтаксис для работы с контейнерами.
Пример программы, где можно применить класс Boost:
*/

#include <boost/algorithm/string.hpp>
#include <iostream>
#include <string>

int main() {
    std::string str = "Hello, World!";
    boost::algorithm::to_upper(str);

    std::cout << str << std::endl;

    return 0;
}
/*
В данном примере используется класс `boost::algorithm::to_upper`, который позволяет преобразовать строку в верхний регистр. 
Это удобно использовать, например, при работе с пользовательским вводом, когда нужно сравнивать строки без учета регистра.
Такие возможности библиотеки Boost могут быть полезны при разработке больших и сложных проектов на C++, 
где требуется расширенный набор инструментов для работы с данными и взаимодействия с системой.
*/

//1. Пример использования boost для работы с многопоточностью:

#include <iostream>
#include <boost/thread.hpp>

void thread_func() {
    std::cout << "Hello from thread!" << std::endl;
}

int main() {
    boost::thread t(thread_func);

    t.join();

    return 0;
}

//Этот код создает новый поток с помощью boost и выполняет в нем функцию `thread_func`
//2. Пример использования boost для работы с файлами:

#include <iostream>
#include <boost/filesystem.hpp>

int main() {
    boost::filesystem::path dir_path("path/to/directory");

    if (boost::filesystem::is_directory(dir_path)) {
        std::cout << "Directory exists!" << std::endl;
    } else {
        std::cout << "Directory does not exist!" << std::endl;
    }

    return 0;
}

//Этот код проверяет существование директории с помощью boost::filesystem.
//3. Пример использования boost для работы с регулярными выражениями:


#include <iostream>
#include <boost/regex.hpp>

int main() {
    std::string s("Boost Libraries");
    boost::regex expr("(\\w+)\\s(\\w+)");

    boost::smatch what;
    if (boost::regex_search(s, what, expr)) {
        for (size_t i = 0; i < what.size(); ++i) {
            std::cout << what[i] << std::endl;
        }
    }

    return 0;
}

//Этот код ищет совпадения с регулярным выражением в строке с помощью boost::regex.
