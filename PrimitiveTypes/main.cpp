#include <iostream>
#include "count_bits.h"

int main() {
    unsigned int x = 13;
    std::cout << "Number of bits in " << x << " is: " << CountBits(x) << std::endl;
    return 0;
}