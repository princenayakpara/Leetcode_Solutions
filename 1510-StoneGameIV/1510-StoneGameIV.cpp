// Last updated: 10/08/2026, 19:16:34
1class Solution {
2public:
3    bool winnerSquareGame(int n) {
4        vector<bool> dp(n + 1, false);
5        for (int i = 1; i <= n; ++i) {
6            for (int k = 1; k * k <= i; ++k) {
7                if (!dp[i - k * k]) {
8                    dp[i] = true;
9                    break;
10                }
11            }
12        }
13        return dp[n];
14    }
15};