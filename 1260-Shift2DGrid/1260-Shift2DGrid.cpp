// Last updated: 20/07/2026, 09:34:35
1class Solution {
2public:
3    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
4        int m = grid.size();
5        int n = grid[0].size();
6        int total = m * n;
7
8        k %= total;
9
10        vector<vector<int>> ans(m, vector<int>(n));
11
12        for (int i = 0; i < total; i++) {
13            int newIndex = (i + k) % total;
14
15            ans[newIndex / n][newIndex % n] = grid[i / n][i % n];
16        }
17
18        return ans;
19    }
20};