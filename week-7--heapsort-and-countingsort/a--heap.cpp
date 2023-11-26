#include <cstring>
#include <iostream>

struct Heap {
  int* _array;
  int* _insertion_order;
  int _size = 0;
  int _capacity;

  explicit Heap(int capacity) {
    _capacity = capacity;
    _array = new int[_capacity];
    _insertion_order = new int[_capacity];
  }

  ~Heap() {
    delete[] _array;
    delete[] _insertion_order;
  }

  int LeftChild(int index) {
    return 2 * index + 1;
  }

  int RightChild(int index) {
    return 2 * index + 2;
  }

  void SiftUp(int i) {
    while (i > 0 && _array[(i - 1) / 2] > _array[i]) {
      std::swap(_array[i], _array[(i - 1) / 2]);
      i = (i - 1) / 2;
    }
  }

  void SiftDown(int i) {
    int left = LeftChild(i);
    int right = RightChild(i);
    int smallest = i;

    if (left < _size && _array[left] < _array[i]) {
      smallest = left;
    }

    if (right < _size && _array[right] < _array[smallest]) {
      smallest = right;
    }

    if (smallest != i) {
      std::swap(_array[i], _array[smallest]);
      SiftDown(smallest);
    }
  }

  int Find(int val) {
    for (int i = 0; i < _size; i++) {
      if (_array[i] == val) {
        return i;
      }
    }
    return -1;
  }

  void Insert(int n) {
    _array[_size] = n;
    _insertion_order[_size] = n;
    SiftUp(_size);
    _size++;
    std::cout << "ok" << std::endl;
  }

  void ExtractMin() {
    if (_size == 0) {
      std::cout << "error" << std::endl;
      return;
    }
    int result = _array[0];
    _array[0] = _array[_size - 1];
    _size--;
    if (_size > 0) {
      SiftDown(0);
    }
    std::cout << result << std::endl;
  }

  void Delete(int x) {
    if (_size == 0) {
      std::cout << "error" << std::endl;
      return;
    }
    int index = Find(_insertion_order[x - 1]);
    _array[index] = _array[_size - 1];
    _size--;
    SiftDown(index);
    std::cout << "ok" << std::endl;
  }

  void Change(int x, int n) {
    int index = Find(_insertion_order[x - 1]);
    if (index == -1) {
      std::cout << "error" << std::endl;
      return;
    }
    _array[index] = n;
    SiftDown(index);
  }

  void GetMin() {
    if (_size == 0) {
      std::cout << "error" << std::endl;
      return;
    }
    std::cout << _array[0] << std::endl;
  }

  void Size() {
    std::cout << _size << std::endl;
  }

  void Clear() {
    _size = 0;
    std::cout << "ok" << std::endl;
  }
};

int main() {
  int m1;
  std::cin >> m1;
  const int m = m1;
  auto* heap = new Heap(m);
  char str[12];
  for (int i = 0; i < m; i++) {
    std::cin >> str;
    if (!strcmp(str, "insert")) {
      int n;
      std::cin >> n;
      heap->Insert(n);
    } else if (!strcmp(str, "extract_min")) {
      heap->ExtractMin();
    } else if (!strcmp(str, "delete")) {
      int x;
      std::cin >> x;
      heap->Delete(x);
    } else if (!strcmp(str, "change")) {
      int x, n;
      std::cin >> x >> n;
      heap->Change(x, n);
    } else if (!strcmp(str, "get_min")) {
      heap->GetMin();
    } else if (!strcmp(str, "size")) {
      heap->Size();
    } else if (!strcmp(str, "clear")) {
      heap->Clear();
    }
  }
  delete heap;
  return 0;
}
