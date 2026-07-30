// Last updated: 30/07/2026, 16:50:21
1class Solution {
2public:
3    vector<int> minBitwiseArray(vector<int>& nums) {
4        vector<int> ans;
5
6        for (int x : nums) {
7            if ((x & 1) == 0) {
8                ans.push_back(-1);
9                continue;
10            }
11
12            int cnt = 0;
13            int t = x;
14            while (t & 1) {
15                cnt++;
16                t >>= 1;
17            }
18
19            ans.push_back(x ^ (1 << (cnt - 1)));
20        }
21
22        return ans;
23    }
24};