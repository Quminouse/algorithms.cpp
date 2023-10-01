#include "../Algorithms/hashmap.hpp"
#include "test_assert.cpp"

bool hashmap_hash_test() {
  int value_1 = rand();
  int value_2 = rand();

  uint64_t hash_1_1 = Hashmap<int, int>::hash(value_1);
  uint64_t hash_1_2 = Hashmap<int, int>::hash(value_1);
  uint64_t hash_2_1 = Hashmap<int, int>::hash(value_2);
  uint64_t hash_2_2 = Hashmap<int, int>::hash(value_2);

  return test_assert(hash_1_1 != hash_2_1 && hash_1_1 == hash_1_2 &&
                         hash_2_1 == hash_2_2,
                     "HASHMAP", "HASH");
}

bool hashmap_insert_get_test() {
  int key = rand();
  int value = rand();

  auto hashmap = Hashmap<int, int>(16);

  hashmap.insert(key, value);
#if 0
  return test_assert(hashmap.get(key).unwrap() == value, "HASHMAP",
                     "INSERT_GET");
#endif
}
int hashmap_test() {
  int fail_count = 0;
  fail_count += hashmap_hash_test();
  return fail_count;
}
