// Last updated: 07/07/2026, 18:29:51
1class Solution {
2public:
3    long long sumAndMultiply(int n) {
4        string s = to_string(n);
5        
6        long long x = 0;
7        int sum = 0;
8        
9        for (char c : s) {
10            if (c != '0') {
11                int d = c - '0';
12                x = x * 10 + d;
13                sum += d;
14            }
15        }
16        
17        return x * 1LL * sum;
18    }
19};