// Last updated: 24/05/2026, 11:13:52
1class Solution {
2public:
3    
4    int dfs(int i, vector<int>& arr, int d, vector<int>& dp) {
5        
6        if(dp[i] != -1)
7            return dp[i];
8
9        int ans = 1;
10
11        // left
12        for(int j = i - 1; j >= max(0, i - d); j--) {
13
14            if(arr[j] >= arr[i])
15                break;
16
17            ans = max(ans, 1 + dfs(j, arr, d, dp));
18        }
19
20        // right
21        for(int j = i + 1; j <= min((int)arr.size() - 1, i + d); j++) {
22
23            if(arr[j] >= arr[i])
24                break;
25
26            ans = max(ans, 1 + dfs(j, arr, d, dp));
27        }
28
29        return dp[i] = ans;
30    }
31
32    
33    int maxJumps(vector<int>& arr, int d) {
34
35        int n = arr.size();
36
37        vector<int> dp(n, -1);
38
39        int ans = 1;
40
41        for(int i = 0; i < n; i++) {
42            ans = max(ans, dfs(i, arr, d, dp));
43        }
44
45        return ans;
46    }
47};