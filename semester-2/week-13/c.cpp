#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <complex>
#include <algorithm>

// Функция для вычисления префикс-функции для строки s
std::vector<int> PrefixFunc(const std::string& s) {
    int n = static_cast<int>(s.size()); // Длина строки
    std::vector<int> p(n, 0); // Массив для хранения значений префикс-функции
    for (int i = 1; i < n; i++) {
        int k = p[i - 1]; // Значение префикс-функции для предыдущего символа
        // Поднимаемся по цепочке префиксов, пока не найдём совпадающий префикс
        while ((s[i] != s[k]) && (k > 0)) {
            k = p[k - 1];
        }
        // Если нашли совпадающий префикс, увеличиваем длину совпадающего префикса
        if (s[i] == s[k]) {
            p[i] = k + 1;
        }
    }
    return p; // Возвращаем массив значений префикс-функции
}

// Функция для поиска всех вхождений pattern в string с использованием алгоритма KMP
std::vector<int> KMP(const std::string& pattern, const std::string& string) {
    int size_pattern = static_cast<int>(pattern.size()); // Длина шаблона
    int size_string = static_cast<int>(string.size()); // Длина строки
    std::vector<int> ans; // Вектор для хранения позиций вхождений шаблона в строке
    // Вычисляем префикс-функцию для конкатенированной строки "pattern#string"
    std::vector<int> pref = PrefixFunc(pattern + "#" + string);
    // Проходим по всей строке и ищем позиции, где значение префикс-функции равно длине шаблона
    for (int i = 0; i < size_string; i++) {
        if (pref[i + 1 + size_pattern] == size_pattern) {
            ans.push_back(i + 1 - size_pattern); // Добавляем позицию в результат
        }
    }
    return ans; // Возвращаем вектор с позициями вхождений
}

int main() {
    std::string s; // Входная строка
    std::string p; // Шаблон
    std::cin >> s >> p; // Считываем строку и шаблон из ввода
    std::vector<int> ans = KMP(p, s); // Выполняем алгоритм KMP для поиска шаблона в строке
    for (auto v : ans) {
        std::cout << v << '\n'; // Выводим все найденные позиции
    }
    return 0; // Завершаем программу
}
