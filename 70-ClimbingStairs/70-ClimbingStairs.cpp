// Last updated: 05/05/2026, 00:54:15
1class Solution {
2public:
3    int climbStairs(int n) {
4        if(n <= 2) return n;
5
6        int prev1 = 2; 
7        int prev2 = 1; 
8
9        for(int i = 3; i <= n; i++){
10            int curr = prev1 + prev2;
11            prev2 = prev1;
12            prev1 = curr;
13        }
14
15        return prev1;
16    }
17};