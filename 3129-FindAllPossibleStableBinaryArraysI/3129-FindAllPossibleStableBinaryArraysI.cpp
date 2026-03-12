// Last updated: 12/03/2026, 16:14:21
1class Solution {
2public:
3    int numberOfStableArrays(int zero, int one, int limit) {
4        const int MOD = 1e9 + 7;
5
6        vector<vector<long long>> dp0(zero + 1, vector<long long>(one + 1, 0));
7        vector<vector<long long>> dp1(zero + 1, vector<long long>(one + 1, 0));
8
9        for (int i = 1; i <= min(zero, limit); i++)
10            dp0[i][0] = 1;
11
12        for (int j = 1; j <= min(one, limit); j++)
13            dp1[0][j] = 1;
14
15        for (int i = 1; i <= zero; i++) {
16            for (int j = 1; j <= one; j++) {
17
18                long long val0 = (dp0[i-1][j] + dp1[i-1][j]) % MOD;
19                if (i - limit - 1 >= 0)
20                    val0 = (val0 - dp1[i-limit-1][j] + MOD) % MOD;
21
22                dp0[i][j] = val0;
23
24                long long val1 = (dp0[i][j-1] + dp1[i][j-1]) % MOD;
25                if (j - limit - 1 >= 0)
26                    val1 = (val1 - dp0[i][j-limit-1] + MOD) % MOD;
27
28                dp1[i][j] = val1;
29            }
30        }
31
32        return (dp0[zero][one] + dp1[zero][one]) % MOD;
33    }
34};