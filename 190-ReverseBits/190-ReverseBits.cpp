// Last updated: 08/05/2026, 21:57:46
1class Solution {
2public:
3    uint32_t reverseBits(uint32_t n) {
4        uint32_t rev = 0;
5
6        for(int i = 0; i < 32; i++) {
7            rev = (rev << 1) | (n & 1);
8            n >>= 1;
9        }
10
11        return rev;
12    }
13};