// Last updated: 03/05/2026, 10:03:11
1class Solution {
2public:
3    int smallestEvenMultiple(int n) {
4        if (n % 2 == 0) return n;
5        return 2 * n;
6    }
7};