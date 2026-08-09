// Last updated: 09/08/2026, 21:05:04
1class Solution {
2public:
3    int stoneGameII(vector<int>& piles) {
4        int n = piles.size();
5
6        vector<int> suffix(n + 1, 0);
7        for (int i = n - 1; i >= 0; --i) {
8            suffix[i] = suffix[i + 1] + piles[i];
9        }
10
11        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
12
13        function<int(int, int)> solve = [&](int i, int M) -> int {
14            if (i >= n)
15                return 0;
16
17            if (dp[i][M] != -1)
18                return dp[i][M];
19
20            int best = 0;
21
22            for (int X = 1; X <= 2 * M && i + X <= n; ++X) {
23                
24                int opponent = solve(i + X, max(M, X));
25                int current = suffix[i] - opponent;
26
27                best = max(best, current);
28            }
29
30            return dp[i][M] = best;
31        };
32
33        return solve(0, 1);
34    }
35};