// Last updated: 09/07/2026, 14:40:28
1class Solution {
2public:
3    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
4        vector<int> comp(n, 0);
5
6        int id = 0;
7        for (int i = 1; i < n; i++) {
8            if (nums[i] - nums[i - 1] > maxDiff)
9                id++;
10            comp[i] = id;
11        }
12
13        vector<bool> ans;
14        for (auto &q : queries) {
15            ans.push_back(comp[q[0]] == comp[q[1]]);
16        }
17
18        return ans;
19    }
20};