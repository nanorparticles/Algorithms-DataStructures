#include "swap_bits.h"
#include <iostream>

long long SwapBits(long long x, int i, int j) {
    // Check if the bits at position i and j are different
    if (((x >> i) & 1) != ((x >> j) & 1)) {
        // Create a bitmask with 1s at positions i and j
        long long bitmask = (1LL << i) | (1LL << j);
        // Toggle the bits at positions i and j using XOR
        x ^= bitmask;
    }
    return x;
}


int main() {
    long long x = 0b1101; // Example number
    int i = 1; // Position of the first bit to swap
    int j = 3; // Position of the second bit to swap

    long long result = SwapBits(x, i, j);
    std::cout << "Result after swapping bits at positions " << i << " and " << j << ": " << std::bitset<8>(result) << std::endl;
    return 0;
}