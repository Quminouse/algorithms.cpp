#pragma once
#include "linkedlist.hpp"
#include "pair.hpp"
#include "vector.hpp"

template <typename K, typename V> class Hashmap {
private:
  Vector<Option<LinkedList<Pair<K, V>>>> data;

public:
  uint32_t capacity;

  Hashmap(uint32_t capacity);
  ~Hashmap();

  static int hash(K key);

  void insert(K key, V value);
  Option<V> get(K key);
};

template <typename K, typename V>
Hashmap<K, V>::Hashmap(uint32_t _capacity) : data(_capacity) {
  capacity = _capacity;
  data = Vector<Option<LinkedList<Pair<K, V>>>>(_capacity);
}

template <typename K, typename V> int Hashmap<K, V>::hash(K key) {
  return (uint64_t)key * 5381;
}

template <typename K, typename V> void Hashmap<K, V>::insert(K key, V value) {
  int hash = Hashmap<K, V>::hash(key);
  int index = hash % capacity;

  if (data.get(index).unwrap().is_none()) {
    data.insert(Option<LinkedList<Pair<K, V>>>(
                    LinkedList<Pair<K, V>>(Pair<K, V>(key, value))),
                index);
  }
}
#if 0
template <typename K, typename V> Option<V> Hashmap<K, V>::get(K key) {
  int hash = Hashmap<K, V>::hash(key);
  int index = hash % capacity;
  if (data.get(index).unwrap().is_some()) {
    return Option<V>(data.get(index).unwrap().unwrap().value.first);
  } else {
    return Option<V>();
  }
}
#endif
