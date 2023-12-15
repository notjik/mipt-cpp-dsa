/*
# B. Простая очередь

**Ограничение времени:** 0.2 секунды
**Ограничение памяти:** 64Mb
**Ввод:** стандартный ввод или input.txt
**Вывод:** стандартный вывод или output.txt

## Задача

Реализуйте тип данных "очередь". Напишите программу, содержащую описание очереди и моделирующую работу очереди, реализовав все указанные здесь методы. Программа считывает последовательность команд и в зависимости от команды выполняет ту или иную операцию. После выполнения каждой команды программа должна вывести одну строчку. Возможные команды для программы:

- "push n"  — Добавить в очередь число n (значение n задается после команды). Программа должна вывести "ok".
- "pop"  — Удалить из очереди первый элемент. Программа должна вывести его значение.
- "front"  — Программа должна вывести значение первого элемента, не удаляя его из очереди.
- "size"  — Программа должна вывести количество элементов в очереди.
- "clear"  — Программа должна очистить очередь и вывести "ok".
- "exit"  — Программа должна вывести bye и завершить работу.

Гарантируется, что набор входных команд удовлетворяет следующим требованиям: все команды pop и front корректны, то есть при их исполнении в очереди содержится хотя бы один элемент.

## Формат ввода

Вводится число команд N, затем вводятся команды управления очередью, по одной на строке. Некоторые строки могут быть некорректны, их необходимо пропускать.

## Формат вывода

Требуется вывести протокол работы с очередью, по одному сообщению на строке.

 */
#include <cstring>
#include <iostream>

struct Node {
  int _val;
  Node* _next;
};

struct Queue {
  Node* _head = nullptr;
  Node* _tail = nullptr;
  size_t _size = 0;

  [[nodiscard]] size_t Size() const {
    return _size;
  }

  void Push(int key) {
    auto* node = new Node{key, nullptr};
    if (_size == 0) {
      _head = _tail = node;
      _size++;
      return;
    }
    _tail->_next = node;
    _tail = node;
    _size++;
  }

  void Pop() {
    if (!Size()) {
      return;
    }
    Node* node = _head;
    _head = node->_next;
    delete node;
    if (_head == nullptr) {
      _tail = nullptr;
    }
    _size--;
  }

  void Front() const {
    if (!Size()) {
      return;
    }
    std::cout << _head->_val << "\n";
  }

  void Clear() {
    while (Size()) {
      Pop();
    }
  }
};

int main() {
  int n;
  std::cin >> n;
  char str[6];
  Queue queue;
  for (int i = 0; i < n; i++) {
    std::cin >> str;
    if (strcmp(str, "pop") == 0) {
      queue.Front();
      queue.Pop();
    } else if (strcmp(str, "push") == 0) {
      int key;
      std::cin >> key;
      queue.Push(key);
      std::cout << "ok" << '\n';
    } else if (strcmp(str, "front") == 0) {
      queue.Front();
    } else if (strcmp(str, "size") == 0) {
      std::cout << queue.Size() << '\n';
    } else if (strcmp(str, "clear") == 0) {
      queue.Clear();
      std::cout << "ok" << '\n';
    } else if (strcmp(str, "exit") == 0) {
      std::cout << "bye" << '\n';
      queue.Clear();
      break;
    }
  }
  queue.Clear();
  return 0;
}
