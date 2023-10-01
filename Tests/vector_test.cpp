#include "../Algorithms/vector.hpp"
#include "test_assert.cpp"
#define VECTOR_TEST_COUNT 2
#define VECTOR_TEST_FILE "VECTOR"

bool vector_push_pop_test() {
  auto vector = Vector<int>(1);
  int value = rand();
  vector.push(value);
  return test_assert(vector.pop() == value, VECTOR_TEST_FILE, "PUSH_POP");
}

bool vector_insert_get_test() {
  auto vector = Vector<int>(32);
  int value = rand();
  int index = rand() % 32;
  vector.insert(value, index);
  return test_assert(vector.get(index).unwrap() == value, VECTOR_TEST_FILE, "INSERT_GET");
}

int vector_test() {
  int fail_count = 0;
  fail_count += vector_insert_get_test();
  fail_count += vector_push_pop_test();
  return fail_count;
}
