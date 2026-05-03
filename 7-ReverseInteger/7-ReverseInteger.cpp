// Last updated: 03/05/2026, 22:42:44
1class Solution {
2public:
3    int addDigits(int num) {
4        if (num == 0) 
5            return 0;
6            return 1 + (num - 1)% 9;
7    }
8};