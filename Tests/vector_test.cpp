#include "../Algorithms/vector.hpp"
#include "test_assert.cpp"
#define VECTOR_TEST_COUNT 2
#define VECTOR_TEST_FILE "VECTOR"

bool push_pop_test() {
  auto vector = Vector<int>::with_capacity(1);
  int value = rand();
  vector.push(value);
  return test_assert(vector.pop() == value, VECTOR_TEST_FILE, "PUSH_POP");
}

bool insert_get_test() {
  auto vector = Vector<int>::with_capacity(32);
  int value = rand();
  int index = rand() % 32;
  vector.insert(value, index);
  return test_assert(vector.get(index).unwrap() == value, VECTOR_TEST_FILE, "INSERT_GET");
}

int vector_test() {
  int fail_count = 0;
  fail_count += push_pop_test();
  fail_count += insert_get_test();
  return fail_count;
}
