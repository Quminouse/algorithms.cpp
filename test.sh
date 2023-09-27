clang \
    -Wall -Wextra -pedantic \
    -fsanitize=address \
    Tests/test.cpp \
    -o test \
    -lstdc++

./test

