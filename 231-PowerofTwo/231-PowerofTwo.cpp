// Last updated: 09/05/2026, 10:44:14
1class Solution {
2public:
3    bool isPowerOfThree(int n) {
4        while(n > 1){
5            if(n % 3 != 0){
6                return false;
7            }
8            n /= 3;
9        }
10        return n == 1;
11    }
12};