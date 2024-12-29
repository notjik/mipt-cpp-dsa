#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>

// Функция для вычисления префикс-функции строки
std::vector<int> PrefixFunction(const std::string& s) {
    int n = static_cast<int>(s.size()); // Длина строки
    std::vector<int> p(n, 0); // Инициализируем массив префикс-функции с нулями
    for (int i = 1; i < n; i++) {
        int k = p[i - 1]; // Начинаем с предыдущего значения префикс-функции
        while (s[i] != s[k] && k > 0) {
            k = p[k - 1]; // Уменьшаем k до длины наибольшего собственного префикса-суффикса
        }
        if (s[i] == s[k]) {
            k++; // Увеличиваем k, если символы равны
        }
        p[i] = k; // Присваиваем значение префикс-функции для текущей позиции
    }
    return p; // Возвращаем массив префикс-функции
}

int main() {
    std::string s;
    std::cin >> s; // Вводим строку
    for (auto i : PrefixFunction(s)) {
        std::cout << i << ' '; // Выводим значения префикс-функции через пробел
    }
}
