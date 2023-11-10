#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct Heap {
  vector<int> elements; // Храним элементы пирамиды в векторе.
  stack<int> deleted;   // Храним индексы удаленных элементов для операции delete.

  void insert(int n) {
    elements.push_back(n); // Добавляем элемент в конец вектора.
    int idx = elements.size() - 1;

    // Восстанавливаем свойство мин-пирамиды, поднимая элемент вверх.
    while (idx > 0 && elements[idx] < elements[(idx - 1) / 2]) {
      swap(elements[idx], elements[(idx - 1) / 2]);
      idx = (idx - 1) / 2;
    }

    cout << "ok\n";
  }

  int extract_min() {
    if (elements.empty()) {
      cout << "error\n";
      return -1;
    }

    int min_value = elements[0];
    swap(elements[0], elements.back());
    elements.pop_back();
    heapify(0); // Восстанавливаем свойство мин-пирамиды.
    return min_value;
  }

  void delete_element(int x) {
    if (x <= 0 || x > elements.size() || deleted.size() >= x) {
      cout << "error\n";
      return;
    }

    x = elements.size() - x; // Пересчитываем индекс.
    deleted.push(x);
    swap(elements[x], elements.back());
    elements.pop_back();
    heapify(x); // Восстанавливаем свойство мин-пирамиды.
    cout << "ok\n";
  }

  void change(int x, int n) {
    if (x <= 0 || x > elements.size() || deleted.size() >= x) {
      cout << "error\n";
      return;
    }

    x = elements.size() - x; // Пересчитываем индекс.
    elements[x] = n;

    // Перестраиваем пирамиду, чтобы восстановить свойство мин-пирамиды.
    while (x > 0 && elements[x] < elements[(x - 1) / 2]) {
      swap(elements[x], elements[(x - 1) / 2]);
      x = (x - 1) / 2;
    }

    heapify(x);
    cout << "ok\n";
  }

  int get_min() {
    if (elements.empty()) {
      cout << "error\n";
      return -1;
    }
    return elements[0];
  }

  int size() {
    return elements.size();
  }

  void clear() {
    elements.clear();
    deleted = stack<int>(); // Очищаем стек удаленных элементов.
    cout << "ok\n";
  }

 private:
  void heapify(int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < elements.size() && elements[left] < elements[smallest])
      smallest = left;

    if (right < elements.size() && elements[right] < elements[smallest])
      smallest = right;

    if (smallest != idx) {
      swap(elements[idx], elements[smallest]);
      heapify(smallest);
    }
  }
};

int main() {
  Heap heap;
  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    string command;
    cin >> command;
    if (command == "insert") {
      int value;
      cin >> value;
      heap.insert(value);
    } else if (command == "extract_min") {
      int result = heap.extract_min();
      if (result != -1)
        cout << result << '\n';
    } else if (command == "delete") {
      int x;
      cin >> x;
      heap.delete_element(x);
    } else if (command == "change") {
      int x, n;
      cin >> x >> n;
      heap.change(x, n);
    } else if (command == "get_min") {
      int result = heap.get_min();
      if (result != -1)
        cout << result << '\n';
    } else if (command == "size") {
      cout << heap.size() << '\n';
    } else if (command == "clear") {
      heap.clear();
    }
  }

  return 0;
}
