// Last updated: 18/03/2026, 16:57:02
1class Solution {
2public:
3    int countSubmatrices(vector<vector<int>>& grid, int k) {
4        int n = grid.size();
5        int m = grid[0].size();
6        
7        vector<vector<long long>> prefix(n, vector<long long>(m, 0));
8        int count = 0;
9
10        for(int i = 0; i < n; i++) {
11            for(int j = 0; j < m; j++) {
12                prefix[i][j] = grid[i][j];
13
14                if(i > 0) prefix[i][j] += prefix[i - 1][j];
15                if(j > 0) prefix[i][j] += prefix[i][j - 1];
16                if(i > 0 && j > 0) prefix[i][j] -= prefix[i - 1][j - 1];
17
18                if(prefix[i][j] <= k) count++;
19            }
20        }
21
22        return count;
23    }
24};