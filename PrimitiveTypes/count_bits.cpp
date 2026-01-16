#include "count_bits.h"
#include <iostream>

short CountBits(unsigned int x) {
    short num_bits = 0; 
    while(x) {
        num_bits += x & 1; 
        x >>= 1; 
    }
    return num_bits;
}

int main() {
    unsigned int x = 13;
    std::cout << "Number of bits in " << x << " is: " << CountBits(x) << std::endl;
    return 0;
}