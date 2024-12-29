#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>

// Структура для представления точки на плоскости
struct Point {
    int64_t x;  // Координата x
    int64_t y;  // Координата y
};

// Функция для нахождения самой нижней и самой левой точки
void FindMin(Point* points, int n) {
    int min = 0;
    for (int i = 1; i < n; i++) {
        // Если находим точку с меньшей координатой x или с такой же x, но меньшей y, обновляем min
        if ((points[min].x > points[i].x) || ((points[min].x == points[i].x) && (points[min].y > points[i].y))) {
            min = i;
        }
    }
    // Меняем местами первую точку и точку с минимальными координатами
    std::swap(points[0], points[min]);
}

// Функция для вычисления векторного произведения векторов p->a и p->b
int64_t CrossProduct(const Point& p, const Point& a, const Point& b) {
    return (a.x - p.x) * (b.y - p.y) - (a.y - p.y) * (b.x - p.x);
}

// Функция для вычисления квадратов расстояния между двумя точками a и b
int64_t SquareLen(const Point& a, const Point& b) {
    return pow(a.x - b.x, 2) + pow(a.y - b.y, 2);
}

// Функция для сравнения углов между точками a и b относительно точки p
bool CompareAngle(const Point& p, const Point& a, const Point& b) {
    int64_t product = CrossProduct(p, a, b);
    return (product > 0) ||
           ((product == 0) && (SquareLen(p, b) < SquareLen(p, a)));
}

// Функция для построения выпуклой оболочки по алгоритму Грэхема
std::vector<Point> Grehem(Point* points, int n) {
    FindMin(points, n);  // Находим самую нижнюю и самую левую точку
    std::sort(&points[1], &points[n], [points](const Point& a, const Point& b) {
        return !CompareAngle(points[0], a, b);  // Сортируем остальные точки по углам относительно первой точки
    });
    std::vector<Point> polygon;  // Вектор для хранения точек выпуклой оболочки
    polygon.push_back(points[0]);
    polygon.push_back(points[1]);

    for(int i = 2; i < n; i++){
        // Удаляем точки, которые не являются вершинами выпуклой оболочки
        while((polygon.size() > 1) && (CrossProduct(polygon.back(), points[i], polygon[polygon.size() - 2]) >= 0)) {
            polygon.pop_back();
        }
        polygon.push_back(points[i]);
    }
    return polygon;
}

// Функция для вычисления площади выпуклой оболочки
int64_t Area(const std::vector<Point>& polygon) {
    int64_t sum = 0;
    for (int p = 2; p < polygon.size(); ++p){
        sum += CrossProduct(polygon[0], polygon[p], polygon[p - 1]);
    }
    return sum;
}

int main() {
    int n;
    std::cin >> n;  // Вводим количество точек
    auto points = new Point[n];
    for(int i = 0; i < n; i++) {
        std::cin >> points[i].x >> points[i].y;  // Вводим координаты точек
    }
    std::vector<Point> polygon = Grehem(points, n);  // Строим выпуклую оболочку
    std::cout << polygon.size() << '\n';  // Выводим количество точек в выпуклой оболочке

    for(auto v : polygon) {
        std::cout << v.x << ' ' << v.y << '\n';  // Выводим координаты точек выпуклой оболочки
    }

    int64_t area = Area(polygon);  // Вычисляем площадь выпуклой оболочки
    printf("%.1lf", area / 2.0);  // Выводим площадь с одним знаком после запятой
    delete[] points;  // Освобождаем память
}
