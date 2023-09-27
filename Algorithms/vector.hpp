#pragma once
#include <cstdint>
#include <memory>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "option.hpp"

template <typename T> class Vector {
private:
  std::shared_ptr<T> data;
  Vector(std::shared_ptr<T> _data, uint32_t _size, uint32_t _capacity);

public:
  uint32_t size;
  uint32_t capacity;

  static Vector from_array(std::shared_ptr<T> data, uint32_t size);
  static Vector with_capacity(uint32_t capacity);

  ~Vector();

  void push(T value);
  T pop();

  void insert(T value, uint32_t index);
  Option<T> get(uint32_t index);

  void fill(T value);
  void randomize();

  void print();

  void rev();
};

template <typename T>
Vector<T>::Vector(std::shared_ptr<T> _data, uint32_t _size,
                  uint32_t _capacity) {
  data = _data;
  size = _size;
  capacity = _capacity;
}

template <typename T> Vector<T>::~Vector(){};

template <typename T>
Vector<T> Vector<T>::from_array(std::shared_ptr<T> data, uint32_t size) {
  return Vector<T>(data, size, size);
}

template <typename T> Vector<T> Vector<T>::with_capacity(uint32_t capacity) {
  auto data = std::shared_ptr<T>((T *)calloc(capacity, sizeof(T)));
  return Vector<T>(data, 0, capacity);
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

template <typename T> void Vector<T>::insert(T value, uint32_t index) {
  if (index < capacity) {
    data.get()[index] = value;
  }
}

template <typename T> Option<T> Vector<T>::get(uint32_t index) {
  if (index < capacity) {
    return Option<T>(data.get()[index]);
  }
  return Option<T>();
}

template <typename T> void Vector<T>::fill(T value) {
  for (uint32_t i = 0; i < capacity; ++i) {
    data.get()[i] = value;
  }
}

template <typename T> void Vector<T>::randomize() {
  for (uint32_t i = 0; i < capacity; ++i) {
    data.get()[i] = rand();
  }
}

template <typename T> void Vector<T>::print() {
  printf("[%d, ", get(0).unwrap());
  for (uint32_t i = 1; i < capacity - 1; ++i) {
    printf("%d, ", get(i).unwrap());
  }
  printf("%d]\n", get(capacity - 1).unwrap());
}

template <typename T> void Vector<T>::rev() {
  auto new_vector = Vector<T>::with_capacity(capacity);
  for (uint32_t i = 0; i < capacity; ++i) {
    new_vector.insert(get(i).unwrap(), capacity - i - 1);
  }
  *this = new_vector;
}
