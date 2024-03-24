/******************************************************************************
WEB-PAGE DATA DOWNLOAD AND PARSING
*******************************************************************************/
// библиотеки для работы с сетью и файлами
#include <iostream>
#include <fstream>
#include <curl/curl.h>

// функция для записи данных в файл
size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

int main() {
    // инициализация сетевой библиотеки curl
    curl_global_init(CURL_GLOBAL_ALL);
    CURL *curl = curl_easy_init();
    
    // проверка на успешное создание объекта curl
    if(curl) {
        // указываем URL для скачивания данных
        curl_easy_setopt(curl, CURLOPT_URL, "http://www.example.com/data.csv");
        
        // указываем функцию для записи данных в файл
        FILE *fp = fopen("data.csv", "wb");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        
        // выполняем запрос
        CURLcode res = curl_easy_perform(curl);
        
        // проверка на успешность выполнения запроса
        if(res != CURLE_OK) {
            std::cerr << "Failed to download file: " << curl_easy_strerror(res) << std::endl;
        } else {
            std::cout << "File downloaded successfully." << std::endl;
        }
        
        // закрываем файл и освобождаем память
        fclose(fp);
        curl_easy_cleanup(curl);
    }
    
    // завершаем работу сетевой библиотеки curl
    curl_global_cleanup();
    
    return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <curl/curl.h>

size_t write_callback(void *contents, size_t size, size_t nmemb, void *userp) {
    std::ofstream *file = static_cast<std::ofstream*>(userp);
    file->write(static_cast<char*>(contents), size * nmemb);
    return size * nmemb;
}

int main() {
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://example.com/data.db");
        
        std::ofstream file("data.db", std::ios::binary);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &file);
        
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "Failed to download the file: " << curl_easy_strerror(res) << std::endl;
        }
        
        curl_easy_cleanup(curl);
        file.close();
    }

    return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
// Пример кода, который использует библиотеку libcurl для парсинга данных с интернет страницы:

#include <iostream>
#include <curl/curl.h>

size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* data) {
    data->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int main() {
    CURL* curl;
    CURLcode res;
    std::string data;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://example.com");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data);
        
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        } else {
            // Парсинг данных в переменной 'data'
            std::cout << data << std::endl;
        }

        curl_easy_cleanup(curl);
    }

    return 0;
}
//Для использования этого кода вам понадобится установить библиотеку libcurl.
///////////////////////////СОЗДАНИЕ БАЗ ДАННЫХ ЗАПОЛНЕНИЕМ И СКАЧИВАНИЕМ///////////////////////////
#include <iostream>
#include <map>
#include <string>

using namespace std;

// Создаем структуру для хранения товара и его цены
struct Product {
    string name;
    double price;
};

int main() {
    // Создаем базу данных товаров и их цен
    map<string, double> products;

    // Добавляем товары и их цены в базу данных
    products["Футболка"] = 1000.00;
    products["Джинсы"] = 2000.00;
    products["Кроссовки"] = 3000.00;
    products["Рубашка"] = 1500.00;

    // Сортируем базу данных по возрастанию цен
    map<string, double>::iterator it;
    for (it = products.begin(); it != products.end(); ++it) {
        cout << it->first << ": " << it->second << " рублей" << endl;
    }

    return 0;
} 
// В данном примере кода создается база данных товаров и их цен на торговом сайте. 
//Товары и их цены заносятся в map, где ключом является название товара, а значением - цена. 
//После этого база данных сортируется по возрастанию цен и выводится на экран.
//////////////////////////////////////////////////////////////////////////////////////////////
/*
Для скачивания данных и сохранения их в формате .txt базы данных товаров и цен по возрастанию из 
торгового сайта вам понадобится использовать библиотеку curl для загрузки содержимого сайта и парсинга HTML кода.
Ниже приведен пример кода на C++, который скачивает страницу из торгового сайта, парсит HTML код, 
извлекает информацию о товарах и ценах, сортирует их по возрастанию, и сохраняет в файл базы данных в формате .txt:
*/

#include <iostream>
#include <fstream>
#include <curl/curl.h>

// Функция для записи полученных данных в файл
size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

int main() {
    // Создаем CURL сессию
    CURL *curl;
    curl = curl_easy_init();
    
    if(curl) {
        // Устанавливаем URL для загрузки
        curl_easy_setopt(curl, CURLOPT_URL, "https://www.example.com");
        
        // Открываем файл для записи
        FILE *fp;
        fp = fopen("database.txt", "wb");
        
        // Настраиваем параметры CURL для записи в файл
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        
        // Выполняем запрос для загрузки страницы
        CURLcode res = curl_easy_perform(curl);
        
        // Закрываем файл и освобождаем память
        fclose(fp);
        curl_easy_cleanup(curl);
        
        // Парсинг HTML кода, извлечение информации о товарах и ценах
        
        // Сортировка данных по возрастанию
        
        // Запись отсортированных данных в файл базы данных
        std::ofstream outfile("database.txt");
        outfile << "Товары и цены по возрастанию:\n";
        // Запись отсортированных данных в файл
        outfile.close();

        std::cout << "Данные успешно сохранены в файл database.txt";
    } else {
        std::cout << "Не удалось инициализировать CURL";
    }
    
    return 0;
}
/*
Пожалуйста, замените `"https://www.example.com"` на URL торгового сайта, с которого хотите скачать данные,
и настройте парсинг HTML кода и сортировку данных в соответствии с вашими требованиями.
Кроме того, не забудьте установить и подключить библиотеку curl для компиляции программы.
*/

