// Last updated: 05/05/2026, 08:07:09
1class Solution {
2public:
3    int sumBase(int n, int k) {
4        int sum = 0;
5
6        while (n > 0) {
7            sum += n % k;  
8            n /= k;        
9        }
10
11        return sum;
12    }
13};