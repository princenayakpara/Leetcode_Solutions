// Last updated: 11/05/2026, 10:11:09
1class Solution {
2public:
3    bool isUgly(int n) {
4        if(n <= 0) return false;
5
6        while(n % 2 == 0) n /= 2;
7        while(n % 3 == 0) n /= 3;
8        while(n % 5 == 0) n /= 5;
9
10        return n == 1;
11    }
12};