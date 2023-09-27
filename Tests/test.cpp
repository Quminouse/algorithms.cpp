#include "vector_test.cpp"
#include "linkedlist_test.cpp"
#define TEST_COUNT 1
#define TEST_SEPERATOR "--------------------------------\n"

int main() {
  srand(time(NULL));
  printf("Random seed: %d\n", rand());
  printf(TEST_SEPERATOR);
  int fail_count = 0;
  for (int i = 0; i < TEST_COUNT; ++i) {
    fail_count += vector_test();
    fail_count += linkedlist_test();
    printf(TEST_SEPERATOR);
  }
  printf("Total failures: %d", fail_count);
}
