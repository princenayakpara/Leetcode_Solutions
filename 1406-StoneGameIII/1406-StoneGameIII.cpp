// Last updated: 03/08/2026, 21:22:38
1class Solution {
2public:
3    string stoneGameIII(vector<int>& stoneValue) {
4        int n = stoneValue.size();
5        vector<int> dp(n + 1, 0);
6
7        for (int i = n - 1; i >= 0; i--) {
8            dp[i] = INT_MIN;
9            int sum = 0;
10
11            for (int k = 0; k < 3 && i + k < n; k++) {
12                sum += stoneValue[i + k];
13                dp[i] = max(dp[i], sum - dp[i + k + 1]);
14            }
15        }
16
17        if (dp[0] > 0) return "Alice";
18        if (dp[0] < 0) return "Bob";
19        return "Tie";
20    }
21};