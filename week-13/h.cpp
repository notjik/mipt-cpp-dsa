#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <complex>
#include <algorithm>
#include <unordered_map>

// Основная функция
int main() {
    // Объявление словаря (unordered_map), который будет хранить аккаунты и их балансы
    std::unordered_map<std::string, int> accounts;
    int n = 0; // Количество операций
    std::cin >> n; // Ввод количества операций
    // Цикл по всем операциям
    for (int _ = 0; _ < n; _++) {
        int type = 0; // Тип операции: 1 - изменение баланса, 2 - запрос баланса
        std::string account; // Имя аккаунта
        std::cin >> type >> account; // Ввод типа операции и имени аккаунта
        // Если тип операции - изменение баланса
        if (type == 1) {
            int operation = 0; // Сумма операции
            std::cin >> operation; // Ввод суммы операции
            accounts[account] += operation; // Изменение баланса аккаунта
        } else {
            // Если тип операции - запрос баланса
            if (accounts.find(account) != accounts.end()) {
                // Если аккаунт существует, выводим его баланс
                std::cout << accounts[account];
            } else {
                // Если аккаунт не найден, выводим "ERROR"
                std::cout << "ERROR";
            }
            std::cout << '\n'; // Перенос строки после вывода баланса или ошибки
        }
    }
    return 0; // Завершение программы
}
