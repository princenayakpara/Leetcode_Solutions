// Last updated: 18/08/2026, 16:34:43
1class Solution {
2public:
3    int shortestPath(vector<vector<int>>& grid, int k) {
4        int m = grid.size();
5        int n = grid[0].size();
6
7        queue<tuple<int,int,int>> q;
8        vector<vector<int>> vis(m, vector<int>(n, -1));
9
10        q.push({0, 0, k});
11        vis[0][0] = k;
12
13        int steps = 0;
14        int dr[] = {1, -1, 0, 0};
15        int dc[] = {0, 0, 1, -1};
16
17        while (!q.empty()) {
18            int sz = q.size();
19
20            while (sz--) {
21                auto [r, c, rem] = q.front();
22                q.pop();
23
24                if (r == m - 1 && c == n - 1)
25                    return steps;
26
27                for (int d = 0; d < 4; d++) {
28                    int nr = r + dr[d];
29                    int nc = c + dc[d];
30
31                    if (nr < 0 || nr >= m || nc < 0 || nc >= n)
32                        continue;
33
34                    int left = rem - grid[nr][nc];
35
36                    if (left >= 0 && left > vis[nr][nc]) {
37                        vis[nr][nc] = left;
38                        q.push({nr, nc, left});
39                    }
40                }
41            }
42
43            steps++;
44        }
45
46        return -1;
47    }
48};