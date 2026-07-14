// Last updated: 14/07/2026, 15:16:24
1class Solution {
2public:
3    static const int MOD = 1e9 + 7;
4
5    int subsequencePairCount(vector<int>& nums) {
6        const int MAX = 200;
7
8        vector<vector<int>> dp(MAX + 1, vector<int>(MAX + 1, 0));
9        dp[0][0] = 1;
10
11        for (int x : nums) {
12            vector<vector<int>> ndp = dp;
13
14            for (int g1 = 0; g1 <= MAX; g1++) {
15                for (int g2 = 0; g2 <= MAX; g2++) {
16                    if (dp[g1][g2] == 0) continue;
17
18                    int ng1 = (g1 == 0) ? x : gcd(g1, x);
19                    int ng2 = (g2 == 0) ? x : gcd(g2, x);
20
21                    ndp[ng1][g2] = (ndp[ng1][g2] + dp[g1][g2]) % MOD;
22                    ndp[g1][ng2] = (ndp[g1][ng2] + dp[g1][g2]) % MOD;
23                }
24            }
25
26            dp.swap(ndp);
27        }
28
29        long long ans = 0;
30        for (int g = 1; g <= MAX; g++) {
31            ans = (ans + dp[g][g]) % MOD;
32        }
33
34        return (int)ans;
35    }
36};