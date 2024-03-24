/******************************************************************************
СОЗДАНИЕ БД по ключу (id). Получение данных из MSSQL
*******************************************************************************/
#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<int, std::string> products;

    int id;
    std::string name;

    while (true) {
        std::cout << "Введите id товара (для завершения введите -1): ";
        std::cin >> id;

        if (id == -1) {
            break;
        }

        std::cout << "Введите наименование товара: ";
        std::cin >> name;

        products[id] = name;
    }

    std::cout << "Результат:\n";
    for (auto const& product : products) {
        std::cout << "ID: " << product.first << ", Наименование: " << product.second << std::endl;
    }

    return 0;
}

#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    std::unordered_map<int, std::string> items;

    int id;
    std::string name;

    std::cout << "Введите id и наименование товара (id = 0 для завершения)" << std::endl;

    while (true) {
        std::cout << "Введите id: ";
        std::cin >> id;

        if (id == 0) {
            break;
        }

        std::cout << "Введите наименование: ";
        std::cin.ignore();
        std::getline(std::cin, name);

        items[id] = name;
    }

    std::cout << "Результат:" << std::endl;
    for (const auto& item : items) {
        std::cout << "ID: " << item.first << ", Наименование: " << item.second << std::endl;
    }

    return 0;
}
//Пример кода получение данных из базы данных mssql и вывод в консоль:

#include <iostream>
#include <windows.h>
#include <sqltypes.h>
#include <sql.h>
#include <sqlext.h>

int main() {
    SQLHENV henv; // Создание окружения
    SQLHDBC hdbc; // Создание подключения
    SQLHSTMT hstmt; // Создание запроса
    SQLRETURN retcode;

    SQLCHAR *szDSN = (SQLCHAR *)"YOUR_DSN_NAME"; // Указываем имя источника данных (DSN)
    SQLCHAR *szUID = (SQLCHAR *)"YOUR_USERNAME"; // Указываем имя пользователя
    SQLCHAR *szPwd = (SQLCHAR *)"YOUR_PASSWORD"; // Указываем пароль

    // Инициализация окружения
    retcode = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &henv);
    retcode = SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION, (void*)SQL_OV_ODBC3, 0);

    // Установка соединения
    retcode = SQLAllocHandle(SQL_HANDLE_DBC, henv, &hdbc);
    retcode = SQLConnect(hdbc, szDSN, SQL_NTS, szUID, SQL_NTS, szPwd, SQL_NTS);

    // Создание запроса
    retcode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);

    // Выполнение запроса
    retcode = SQLExecDirect(hstmt, (SQLCHAR *)"SELECT * FROM YOUR_TABLE", SQL_NTS);

    // Чтение результатов запроса
    SQLCHAR szResult[1024];
    SQLLEN cbValue;

    while (SQLFetch(hstmt) == SQL_SUCCESS) {
        SQLGetData(hstmt, 1, SQL_C_CHAR, szResult, sizeof(szResult), &cbValue);
        std::cout << szResult << std::endl;
    }

    // Освобождение ресурсов
    SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
    SQLDisconnect(hdbc);
    SQLFreeHandle(SQL_HANDLE_DBC, hdbc);
    SQLFreeHandle(SQL_HANDLE_ENV, henv);

    return 0;
}
// Еще пример:

#include <iostream>
#include <sql.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sqlucode.h>

int main() {
    // Declare necessary variables for database connection
    SQLHANDLE sqlenvhandle;
    SQLHANDLE sqlconnectionhandle;
    SQLHANDLE sqlstatementhandle;
    SQLRETURN retcode;

    // Initialize environment handle
    SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &sqlenvhandle);
    SQLSetEnvAttr(sqlenvhandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0);
    
    // Initialize connection handle
    SQLAllocHandle(SQL_HANDLE_DBC, sqlenvhandle, &sqlconnectionhandle);
    
    // Connect to the database
    retcode = SQLDriverConnect(sqlconnectionhandle, NULL, (SQLWCHAR*)L"DRIVER={SQL Server};SERVER=servername;DATABASE=databasename;UID=username;PWD=password;", SQL_NTS, NULL, 0, NULL, SQL_DRIVER_NOPROMPT);

    if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) {
        // Declare a buffer to hold the query results
        SQLWCHAR buffer[255];
        SQLSMALLINT columns;
        
        // Initialize statement handle
        SQLAllocHandle(SQL_HANDLE_STMT, sqlconnectionhandle, &sqlstatementhandle);

        // Execute query to retrieve data
        retcode = SQLExecDirect(sqlstatementhandle, (SQLWCHAR*)L"SELECT * FROM tablename", SQL_NTS);

        // Fetch and print results
        while (SQLFetch(sqlstatementhandle) == SQL_SUCCESS) {
            // Retrieve data for each column
            SQLGetData(sqlstatementhandle, 1, SQL_C_WCHAR, buffer, sizeof(buffer), NULL);
            std::wcout << buffer << std::endl;
        }
        
        // Free statement handle
        SQLFreeHandle(SQL_HANDLE_STMT, sqlstatementhandle);
    } else {
        std::cout << "Connection to database failed." << std::endl;
    }

    // Free resources and close connection
    SQLFreeHandle(SQL_HANDLE_DBC, sqlconnectionhandle);
    SQLFreeHandle(SQL_HANDLE_ENV, sqlenvhandle);

    return 0;
}
// Занесение данных SQL в MSSQL:

#include <iostream>
#include <sql.h>
#include <sqlext.h>

int main() {
    SQLHENV henv;
    SQLHDBC hdbc;
    SQLHSTMT hstmt;
    SQLRETURN retcode;

    // Initialize environment handle
    SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &henv);
    SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0);

    // Initialize connection handle
    SQLAllocHandle(SQL_HANDLE_DBC, henv, &hdbc);

    // Connect to the database
    SQLConnect(hdbc, (SQLCHAR*)"YOUR_DSN_NAME", SQL_NTS, (SQLCHAR*)"YOUR_USERNAME", SQL_NTS, (SQLCHAR*)"YOUR_PASSWORD", SQL_NTS);

    // Create table
    retcode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
    retcode = SQLExecDirect(hstmt, (SQLCHAR*)"CREATE TABLE Employees (EmployeeID INT, FirstName VARCHAR(50), LastName VARCHAR(50))", SQL_NTS);

    if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) {
        std::cout << "Table created successfully!" << std::endl;
    } else {
        std::cout << "Error creating table" << std::endl;
    }

    // Insert data into table
    retcode = SQLExecDirect(hstmt, (SQLCHAR*)"INSERT INTO Employees (EmployeeID, FirstName, LastName) VALUES (1, 'John', 'Doe')", SQL_NTS);

    if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) {
        std::cout << "Data inserted successfully!" << std::endl;
    } else {
        std::cout << "Error inserting data" << std::endl;
    }

    // Cleanup
    SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
    SQLDisconnect(hdbc);
    SQLFreeHandle(SQL_HANDLE_DBC, hdbc);
    SQLFreeHandle(SQL_HANDLE_ENV, henv);

    return 0;
}

//Не забудьте заменить `YOUR_DSN_NAME`, `YOUR_USERNAME` и `YOUR_PASSWORD` на ваши данные для подключения к базе данных.