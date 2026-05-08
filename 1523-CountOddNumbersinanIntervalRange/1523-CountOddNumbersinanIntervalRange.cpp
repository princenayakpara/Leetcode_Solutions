// Last updated: 09/05/2026, 02:12:04
1class Solution {
2public:
3    bool isPowerOfFour(int n) {
4        while(n > 1) {
5            if(n % 4 != 0) {
6                return false;
7            }
8            n /= 4;
9        }
10
11        return n == 1;
12    }
13};