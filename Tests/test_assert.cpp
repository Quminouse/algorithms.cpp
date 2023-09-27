#pragma once
#include <stdio.h>

bool test_assert(bool expression, const char* file, const char* test) {
    if (!expression) {
       printf("TEST FAILED: %s/%s\n", file, test); 
       return 1;
    }
    printf("TEST PASSED: %s/%s\n", file, test); 
    return 0;
}
