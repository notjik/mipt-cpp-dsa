/*
# A. Простой стек

**Ограничение времени:** 0.2 секунды
**Ограничение памяти:** 64Mb
**Ввод:** стандартный ввод или input.txt
**Вывод:** стандартный вывод или output.txt

## Задача

Реализуйте тип данных "стек". Напишите программу, содержащую описание стека и моделирующую работу стека, реализовав все указанные здесь методы. Программа считывает последовательность команд и в зависимости от команды выполняет ту или иную операцию. После выполнения каждой команды программа должна вывести одну строчку. Возможные команды для программы:

- "push n" Добавить в стек число n (значение n задается после команды). Программа должна вывести "ok".
- "pop" Удалить из стека последний элемент. Программа должна вывести его значение.
- "back" Программа должна вывести значение последнего элемента, не удаляя его из стека.
- "size" Программа должна вывести количество элементов в стеке.
- "clear" Программа должна очистить стек и вывести "ok".
- "exit" Программа должна вывести "bye" и завершить работу.

## Формат ввода

Сначала вводится N - число команд. Команды управления стеком вводятся в описанном ранее формате по 1 на строке. Гарантируется, что набор входных команд удовлетворяет следующим требованиям: все команды pop и back корректны, то есть при их исполнении в стеке содержится хотя бы один элемент.

## Формат вывода

Требуется вывести протокол работы со стеком, по 1 сообщению в строке.

## Пример

**Ввод**

```
3
push 1
back
exit
```

**Вывод**

```
ok
1
bye
```
 */
#include <cstring>
#include <iostream>

struct Node {
  int _val;
  Node* _next = nullptr;
};

struct Stack {
  Node* _head = nullptr;
  size_t _size = 0;

  size_t Size() {
    return _size;
  }

  void Push(int val) {
    auto* node = new Node{val, _head};
    _head = node;
    _size++;
  }

  void Pop() {
    if (!Size()) {
      return;
    }
    Node* save = _head->_next;
    delete _head;
    _head = save;
    _size--;
  }

  void Back() {
    if (!Size()) {
      return;
    }
    std::cout << _head->_val << '\n';
  }

  void Clear() {
    while (Size()) {
      Pop();
    }
  }
};

int main() {
  size_t n;
  std::cin >> n;
  char str[6];
  Stack stack;
  for (size_t i = 0; i < n; i++) {
    std::cin >> str;
    if (!strcmp(str, "push")) {
      int val;
      std::cin >> val;
      stack.Push(val);
      std::cout << "ok" << '\n';
    } else if (!strcmp(str, "pop")) {
      stack.Back();
      stack.Pop();
    } else if (!strcmp(str, "back")) {
      stack.Back();
    } else if (!strcmp(str, "size")) {
      std::cout << stack.Size() << '\n';
    } else if (!strcmp(str, "clear")) {
      stack.Clear();
      std::cout << "ok" << '\n';
    } else if (!strcmp(str, "exit")) {
      stack.Clear();
      std::cout << "bye" << '\n';
      break;
    }
  }
  stack.Clear();
}