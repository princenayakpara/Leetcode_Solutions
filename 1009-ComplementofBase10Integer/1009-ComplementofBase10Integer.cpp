// Last updated: 11/03/2026, 10:18:56
1class Solution {
2public:
3    int bitwiseComplement(int n) {
4        if(n == 0) return 1;
5
6        int mask = 0;
7        int temp = n;
8
9        while(temp > 0){
10            mask = (mask << 1) | 1;
11            temp >>= 1;
12        }
13
14        return n ^ mask;
15    }
16};