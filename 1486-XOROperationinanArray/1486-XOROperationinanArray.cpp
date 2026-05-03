// Last updated: 03/05/2026, 12:00:28
1class Solution {
2public:
3    int xorOperation(int n, int start) {
4        int ans = 0;
5
6        for(int i = 0; i < n; i++) {
7            int value = start+ 2*i;   
8            ans = ans ^ value;         
9        }
10
11        return ans;
12    }
13};