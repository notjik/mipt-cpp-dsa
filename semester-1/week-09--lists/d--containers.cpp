/*
# D. Контейнеры

**Ограничение времени:** 1 секунда
**Ограничение памяти:** 256Mb
**Ввод:** стандартный ввод или input.txt
**Вывод:** стандартный вывод или output.txt

## Задача

На складе хранятся контейнеры с товарами N различных видов. Все контейнеры составлены в N стопок. В каждой стопке могут находиться контейнеры с товарами любых видов (стопка может быть изначально пустой).

Автопогрузчик может взять верхний контейнер из любой стопки и поставить его сверху в любую стопку. Необходимо расставить все контейнеры с товаром первого вида в первую стопку, второго вида – во вторую стопку и т.д.

Программа должна вывести последовательность действий автопогрузчика или сообщение о том, что задача решения не имеет.

## Формат ввода

В первой строке входных данных записано одно натуральное число N, не превосходящее 500. В следующих N строках описаны стопки контейнеров: сначала записано число ki – количество контейнеров в стопке, а затем ki чисел – виды товара в контейнерах в данной стопке, снизу вверх. В каждой стопке вначале не более 500 контейнеров (в процессе переноса контейнеров это ограничение может быть нарушено).

## Формат вывода

Программа должна вывести описание действий автопогрузчика: для каждого действия напечатать два числа – из какой стопки брать контейнер и в какую стопку класть. (Обратите внимание, что минимизировать количество операций автопогрузчика не требуется.) Если задача не имеет решения, необходимо вывести одно число 0.

## Пример

**Ввод**

```
3
4 1 2 3 2
0
0
1 2
```

**Вывод**

```
1 2
1 3
1 2
```

## Примечания

Объяснение примера: Изначально в первой стопке лежат четыре контейнера – снизу контейнер с товаром первого вида, над ним – с товаром второго вида, над ним третьего, и сверху еще один контейнер с товаром второго вида. Вторая и третья стопки – пусты.
 */
#include <climits>
#include <iostream>

struct Node {
  int _val;
  Node* _next = nullptr;
};

struct Stack {
  Node* _head = nullptr;
  size_t _size = 0;

  [[nodiscard]] size_t Size() const {
    return _size;
  }

  void Push(int val) {
    auto* node = new Node{val, _head};
    _head = node;
    _size++;
  }

  int Pop() {
    if (!Size()) {
      return INT_MIN;
    }
    Node* save = _head->_next;
    delete _head;
    _head = save;
    _size--;
    return save->_val;
  }

  [[nodiscard]] int Back() const {
    if (!Size()) {
      return INT_MIN;
    }
    return _head->_val;
  }

  void Clear() {
    while (Size()) {
      Pop();
    }
  }
};

int AllIsKey(Stack* stack, int key){
  Node* runner = stack->_head;
  if (runner == nullptr) {
    return -1;
  }
  while (runner != nullptr) {
    runner = runner->_next;
  }
  return 0;
}

int main() {
  int n;
  std::cin >> n;
  auto** containers = new Stack*[n];
  for (int i = 0; i < n; i++) {
    int k;
    std::cin >> k;
    for (int j = 0; j < k; j++) {
      int val = 0;
      std::cin >> val;
      containers[n]->Push(val);
    }
  }
  for (int i = 0; i < n; i++) {
    int val = containers[i]->Pop();
    if (i != val - 1) {
      containers[i]->Push(val);
      std::cout << i + 1 << ' ' << val << '\n';
    } else {
      containers[(i + 1) % n]->Push(val);
      std::cout << ((i + 1) % n) + 1 << ' ' << val << '\n';
    }
  }
  return 0;
}
