#include <iostream>

template<typename T>
class VectorClass {
private:
    T* arr_; // Указатель на массив элементов
    size_t capacity_; // Вместимость массива
    size_t size_; // Текущий размер массива
public:
    // Конструктор по умолчанию
    VectorClass() {
        arr_ = new T[1]; // Выделяем память для одного элемента
        capacity_ = 1; // Начальная вместимость
        size_ = 0; // Начальный размер
    }

    // Деструктор для освобождения памяти
    ~VectorClass() {
        delete[] arr_; // Освобождаем выделенную память
    }

    // Метод добавления элемента в конец вектора
    void push_back(T data) {
        // Если текущий размер равен вместимости, увеличиваем массив вдвое
        if (size_ == capacity_) {
            T* new_arr = new T[capacity_ * 2]; // Новый массив вдвое большего размера
            for (size_t i = 0; i < size_; i++) {
                new_arr[i] = arr_[i]; // Копируем элементы в новый массив
            }
            delete[] arr_; // Удаляем старый массив
            arr_ = new_arr; // Перенаправляем указатель на новый массив
            capacity_ *= 2; // Увеличиваем вместимость в два раза
        }
        arr_[size_] = data; // Добавляем новый элемент в конец
        size_++; // Увеличиваем размер
    }

    // Метод удаления последнего элемента вектора
    void pop_back() {
        if (size_) { // Проверяем, что вектор не пуст
            size_--; // Уменьшаем размер
        }
    }

    // Метод получения текущего размера вектора
    int size() {
        return size_;
    }

    // Метод получения текущей вместимости вектора
    int capacity() {
        return capacity_;
    }

    // Метод вывода элементов вектора
    void print() {
        for (size_t i = 0; i < size_; i++) {
            std::cout << arr_[i] << ' '; // Выводим элементы через пробел
        }
        std::cout << '\n'; // Переходим на новую строку
    }

    // Перегрузка оператора [] для доступа к элементам по индексу
    T operator[](size_t i) {
        if (i < size_) { // Проверяем, что индекс не превышает размер
            return arr_[i]; // Возвращаем элемент по индексу
        }
        return INT_MIN; // Возвращаем минимальное значение int в случае некорректного индекса
    }
};

int main() {
    // Создаем экземпляр VectorClass и тестируем его методы
    VectorClass<int> vc;
    vc.push_back(10);
    vc.push_back(20);
    vc.push_back(30);
    vc.print(); // Вывод: 10 20 30
    std::cout << "Size: " << vc.size() << ", Capacity: " << vc.capacity() << '\n'; // Вывод: Size: 3, Capacity: 4
    vc.pop_back();
    vc.print(); // Вывод: 10 20
    std::cout << "Element at index 1: " << vc[1] << '\n'; // Вывод: Element at index 1: 20
    std::cout << "Element at index 5: " << vc[5] << '\n'; // Вывод: Element at index 5: -2147483648 (INT_MIN)

    return 0;
}
