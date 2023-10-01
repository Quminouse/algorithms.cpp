#pragma once
#define DEFAULT_CAPACITY 16
#include <memory>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "option.hpp"

template <typename T> class Vector {
private:
  std::shared_ptr<T> data;
  Vector(std::shared_ptr<T> _data, size_t _size, size_t _capacity);

public:
  size_t size;
  size_t capacity;

  Vector(size_t _capacity);
  Vector(std::shared_ptr<T> _data, size_t _size);

  ~Vector();

  void push(T value);
  T pop();

  void insert(T value, size_t index);
  Option<T> get(size_t index);

  void fill(T value);

  void print();

  void rev();
};

template <typename T>
Vector<T>::Vector(std::shared_ptr<T> _data, size_t _size, size_t _capacity) {
  size = _size;
  capacity = _capacity;
  data = _data;
}

template <typename T> Vector<T>::~Vector(){};

template <typename T> Vector<T>::Vector(std::shared_ptr<T> _data, size_t _size) {
  data = _data;
  size = _size;
  capacity = _size;
}

template <typename T> Vector<T>::Vector(size_t _capacity) {
  data = std::shared_ptr<T>((T *)calloc(_capacity, sizeof(T)));
  size = 0;
  capacity = _capacity;
}

template <typename T> void Vector<T>::push(T value) {
  data.get()[size] = value;
  size += 1;
}

template <typename T> T Vector<T>::pop() {
  if (size > 0) {
    size -= 1;
    T return_value = data.get()[size];
    data.get()[size] = 0;
    return return_value;
  }
  return 0;
}

template <typename T> void Vector<T>::insert(T value, size_t index) {
  if (index < capacity) {
    data.get()[index] = value;
  }
}

template <typename T> Option<T> Vector<T>::get(size_t index) {
  if (index < capacity) {
    return Option<T>(data.get()[index]);
  }
  return Option<T>();
}

template <typename T> void Vector<T>::fill(T value) {
  for (size_t i = 0; i < capacity; ++i) {
    data.get()[i] = value;
  }
}

template <typename T> void Vector<T>::print() {
  printf("[%d, ", get(0).unwrap());
  for (size_t i = 1; i < capacity - 1; ++i) {
    printf("%d, ", get(i).unwrap());
  }
  printf("%d]\n", get(capacity - 1).unwrap());
}

template <typename T> void Vector<T>::rev() {
  auto new_vector = Vector<T>(capacity);
  for (size_t i = 0; i < capacity; ++i) {
    new_vector.insert(get(i).unwrap(), capacity - i - 1);
  }
  *this = new_vector;
}
