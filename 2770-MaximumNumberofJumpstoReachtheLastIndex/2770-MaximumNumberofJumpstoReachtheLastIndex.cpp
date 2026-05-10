// Last updated: 11/05/2026, 00:37:10
1class Solution {
2public:
3    int maximumJumps(vector<int>& nums, int target) {
4        int n = nums.size();
5        vector<int> dp(n, -1);
6        
7        dp[0] = 0;
8        
9        for(int i = 1; i < n; i++) {
10            for(int j = 0; j < i; j++) {
11                if(dp[j] != -1 && abs(nums[i] - nums[j]) <= target) {
12                    dp[i] = max(dp[i], dp[j] + 1);
13                }
14            }
15        }
16        
17        return dp[n - 1];
18    }
19};