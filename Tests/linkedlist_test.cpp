#include "../Algorithms/linkedlist.hpp"
#include "test_assert.cpp"

#define LINKEDLIST_TEST_FILE "LINKEDLIST"

bool from_vector() {
  auto vector = Vector<int>(16);
  for (int i = 0; i < vector.capacity; ++i) {
    vector.insert(rand(), i);
  }

  auto ll = LinkedList<int>::from_vector(vector);
  vector.rev();

  for (uint32_t i = 0; i < vector.capacity; ++i) {
    if (vector.get(i).unwrap() != ll.value) {
      return test_assert(0, LINKEDLIST_TEST_FILE, "FROM_VECTOR");
    }
    if (ll.next.is_some()) {
      ll = *ll.next.unwrap().get();
    }
  }
  return test_assert(1, LINKEDLIST_TEST_FILE, "FROM_VECTOR");
}

int linkedlist_test() {
  int fail_count = 0;
  fail_count += from_vector();
  return fail_count;
}
