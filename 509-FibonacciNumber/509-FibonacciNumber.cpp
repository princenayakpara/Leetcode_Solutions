// Last updated: 23/05/2026, 22:36:07
1class Solution {
2public:
3    int fib(int n) {
4        if(n <=1)
5        return n;
6
7        return fib(n - 1) + fib(n - 2);
8    }
9};