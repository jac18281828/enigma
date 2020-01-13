#pragma once

// mtest - the best framework for testing in C++

namespace magic_test {
    static int nTest = 0;
}

#ifndef MAGIC_TEST
#define MAGIC_TEST(x) if(!x) { \
        std::cerr << "FAILED" << std::endl; \
        return EXIT_FAILURE;                \
    } else { \
        magic_test::nTest++; \
    } 
#endif

#ifndef MAGIC_EQUALS
#define MAGIC_EQUALS(x, y) x == y
#endif
