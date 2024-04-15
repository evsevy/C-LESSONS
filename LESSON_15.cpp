/************************************************************************************************
Создание клиент-серверного приложения по парсингу данных с веб-страницы, библиотека curl/curl.h
************************************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <curl/curl.h>

size_t write_callback(void* ptr, size_t size, size_t nmemb, std::string* data) {
    data->append((char*)ptr, size * nmemb);
    return size * nmemb;
}

int main() {
    CURL* curl;
    CURLcode res;
    std::string url = "https://factories.by/producers/proizvodstvo-zhelezobetonnykh-izdeliy?page=2";
    std::string response;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "Failed to get data from URL: " << curl_easy_strerror(res) << std::endl;
        }
        else {
            std::ofstream outputFile("data2.xls");
            if (outputFile.is_open()) {
                outputFile << response;
                outputFile.close();
                std::cout << "Data saved to data2.xls" << std::endl;
            }
            else {
                std::cerr << "Failed to open file for writing" << std::endl;
            }
        }

        curl_easy_cleanup(curl);
    }
    else {
        std::cerr << "Failed to initialize libcurl" << std::endl;
    }

    return 0;
}
