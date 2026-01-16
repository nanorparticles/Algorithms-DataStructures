#include "parity.h"

short Parity(unsigned long long x) {
    short result = 0; 
    while(x){
        result ^= (x & 1); // XOR operation to toggle parity if the least significant bit is 1 
        x >>=1; // Right shift to process the next bit
    }
    return result;
}

short ParityOptimized(unsigned long long x) { // O(k) time where k is the number of set bits
    short result = 0; 
    while(x){
        result ^= 1; // Toggle parity
        x &= (x - 1); // Drops the lowest set bit
    }
    return result;
}

// Another bit-fiddling trick is x & ~(x - 1) which isolates the lowest set bit of x.

short ParityLookupTable(unsigned long long x) {
    const int WORD_SIZE = 16; 
    const int BIT_MASK = 0xFFFF; // Mask to extract 16 bits
    static short precomputed_parity[1 << WORD_SIZE]; // 2^16 entries

    // Precompute parity for all 16-bit numbers
    for(int i = 0; i < (1 << WORD_SIZE); ++i) {
        precomputed_parity[i] = Parity(i);
    }

    // Break the 64-bit number into four 16-bit chunks and look up their parities
    return precomputed_parity[x & BIT_MASK] ^
           precomputed_parity[(x >> WORD_SIZE) & BIT_MASK] ^
           precomputed_parity[(x >> (2 * WORD_SIZE)) & BIT_MASK] ^
           precomputed_parity[(x >> (3 * WORD_SIZE)) & BIT_MASK];
}