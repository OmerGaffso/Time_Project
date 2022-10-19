#include <iostream>
#include <cstdlib>

#include "helper.hpp"

void myAssert(
    bool const cond,
    const char* const message
) {
    if (cond) {
        std::cerr << message << std::endl;
        std::exit(EXIT_FAILURE);
    }
}