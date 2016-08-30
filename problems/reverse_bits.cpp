// Reverse bits of a given 32 bits unsigned integer.

// For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).

// Follow up:
// If this function is called many times, how would you optimize it?

#include <cstdint>

uint32_t ReverseBits(uint32_t n) {
    n = n >> 16 | n << 16;
    n = n >> 8 & 0x00ff00ff | n << 8 & 0xff00ff00;
    n = n >> 4 & 0x0f0f0f0f | n << 4 & 0xf0f0f0f0;
    n = n >> 2 & 0x33333333 | n << 2 & 0xcccccccc;
    n = n >> 1 & 0x55555555 | n << 1 & 0xaaaaaaaa;
    return n;
}
