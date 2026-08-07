// Last updated: 07/08/2026, 16:13:17
1class Solution {
2public:
3    int smallestNumber(int n, int t) {
4        for (int i = n; ; i++) {
5            int product = 1;
6            int x = i;
7            while (x > 0) {
8                product *= (x % 10);
9                x /= 10;
10            }
11            if (product % t == 0) {
12                return i;
13            }
14        }
15    }
16};