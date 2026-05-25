// Last updated: 25/05/2026, 15:40:55
1class Solution {
2public:
3    bool canReach(string s, int minJump, int maxJump) {
4        int n = s.size();
5        vector<bool> dp(n, false);
6        dp[0] = true;
7
8        int reachable = 0;
9
10        for (int i = 1; i < n; i++) {
11            if (i >= minJump && dp[i - minJump]) {
12                reachable++;
13            }
14            if (i > maxJump && dp[i - maxJump - 1]) {
15                reachable--;
16            }
17
18            dp[i] = (reachable > 0 && s[i] == '0');
19        }
20
21        return dp[n - 1];
22    }
23};