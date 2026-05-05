// Last updated: 05/05/2026, 07:37:34
1class Solution {
2public:
3    bool isSameAfterReversals(int num) {
4        if (num == 0) return true;
5        return num % 10 != 0;
6    }
7};