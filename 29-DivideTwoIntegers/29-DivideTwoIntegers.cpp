// Last updated: 21/08/2026, 15:25:20
1class Solution {
2public:
3    int divide(int dividend, int divisor) {
4        if (dividend == 0) return 0;
5
6        if (dividend == INT_MIN && divisor == -1)
7            return INT_MAX;
8
9        bool neg = (dividend < 0) ^ (divisor < 0);
10
11        long long a = dividend < 0 ? -(long long)dividend : dividend;
12        long long b = divisor < 0 ? -(long long)divisor : divisor;
13
14        long long ans = 0;
15
16        while (a >= b) {
17            long long temp = b;
18            long long count = 1;
19
20            while (a >= temp + temp) {
21                temp += temp;
22                count += count;
23            }
24
25            a -= temp;
26            ans += count;
27        }
28
29        if (neg)
30            ans = -ans;
31
32        if (ans > INT_MAX)
33            return INT_MAX;
34
35        return (int)ans;
36    }
37};