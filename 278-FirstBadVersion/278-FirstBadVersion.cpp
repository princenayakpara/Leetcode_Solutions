// Last updated: 11/05/2026, 10:01:42
1class Solution {
2public:
3    bool isPerfectSquare(int num) {
4        int x = sqrt(num);
5        return x * x == num;
6    }
7};