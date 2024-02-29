#include <iostream>

template<typename T>
class VectorClass {
 private:
  T* arr_;
  size_t capacity_;
  size_t size_;
 public:
  VectorClass() {
    arr_ = new T[1];
    capacity_ = 1;
    size_ = 0;
  }
  ~VectorClass() {
    delete[] arr_;
  }
  void push_back(T data) {
    if (size_ == capacity_) {
      T* new_arr = new T[capacity_ * 2];
      for (size_t i = 0; i < size_; i++) {
        new_arr[i] = arr_[i];
      }
      delete[] arr_;
      arr_ = new_arr;
      capacity_ *= 2;
    }
    arr_[size_] = data;
    size_++;
  }
  void pop_back() {
    if (size_) {
      size_--;
    }
  }

  int size() {
    return size_;
  }

  int capacity() {
    return capacity_;
  }

  void print() {
    for (size_t i = 0; i < size_; i++) {
      std::cout << arr_[size_] << ' ';
    }
    std::cout << '\n';
  }

  T operator[](size_t i){
    if (i <= size_) {
      return arr_[i];
    }
    return INT_MIN;
  }
};

int main() {

  return 0;
}
