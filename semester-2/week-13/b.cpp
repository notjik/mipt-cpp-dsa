#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>

// Функция для вычисления Z-функции строки
std::vector<int> ZFunction(const std::string& s) {
    int n = static_cast<int>(s.size()); // Длина строки
    std::vector<int> z(n, 0); // Инициализируем массив Z-функции с нулями
    z[0] = n; // Значение Z-функции для первой позиции
    int l = 0; // Левая граница текущего самого правого отрезка
    int r = 0; // Правая граница текущего самого правого отрезка
    for (int i = 1; i < n; i++) {
        if (i <= r) {
            z[i] = std::min(r - i + 1, z[i - l]); // Вычисляем начальное значение Z-функции
        }
        while ((i + z[i] < n) && (s[z[i]] == s[i + z[i]])) {
            z[i]++; // Увеличиваем Z-функцию, пока символы совпадают
        }
        if (i + z[i] - 1 > r) {
            r = i + z[i] - 1; // Обновляем правую границу самого правого отрезка
            l = i; // Обновляем левую границу текущего самого правого отрезка
        }
    }
    return z; // Возвращаем массив Z-функции
}

int main() {
    std::string s;
    std::cin >> s; // Вводим строку
    for (auto i : ZFunction(s)) {
        std::cout << i << ' '; // Выводим значения Z-функции через пробел
    }
}
