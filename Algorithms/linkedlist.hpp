#pragma once
#include "vector.hpp"

template <typename T> class LinkedList {
public:
  T value;
  Option<std::shared_ptr<LinkedList<T>>> next;

  LinkedList(T _value, Option<std::shared_ptr<LinkedList<T>>> _next);
  LinkedList(T _value);
  ~LinkedList();

  static LinkedList<T> from_vector(Vector<T> vector);
  void add(T value);

  void print();
};

template <typename T>
LinkedList<T>::LinkedList(T _value,
                          Option<std::shared_ptr<LinkedList<T>>> _next) {
  value = _value;
  next = _next;
};

template <typename T> LinkedList<T>::LinkedList(T _value) {
  value = _value;
  next = Option<std::shared_ptr<LinkedList>>();
};

template <typename T> LinkedList<T>::~LinkedList(){};

template <typename T>
LinkedList<T> LinkedList<T>::from_vector(Vector<T> vector) {
  auto previous_node = Option<std::shared_ptr<LinkedList<T>>>();
  for (uint32_t i = 0; i < vector.capacity; ++i) {
    T value = vector.get(i).unwrap();
    auto ll = std::shared_ptr<LinkedList<T>>(
        new LinkedList<int>(value, previous_node));
    previous_node = Option<std::shared_ptr<LinkedList<T>>>(ll);
  }
  return *previous_node.unwrap().get();
}

template <typename T> void LinkedList<T>::print() {
  auto temp_list = this;
  while (temp_list->next.is_some()) {
    printf("Value: %d\n", temp_list->value);
    temp_list = temp_list->next.unwrap().get();
  }
}
