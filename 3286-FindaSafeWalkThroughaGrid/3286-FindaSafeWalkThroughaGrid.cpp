// Last updated: 02/07/2026, 10:20:40
1class Solution {
2public:
3    bool findSafeWalk(vector<vector<int>>& grid, int health) {
4        int m = grid.size(), n = grid[0].size();
5
6        deque<pair<int, int>> dq;
7        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
8
9        dist[0][0] = grid[0][0];
10        dq.push_front({0, 0});
11
12        int dx[4] = {1, -1, 0, 0};
13        int dy[4] = {0, 0, 1, -1};
14
15        while (!dq.empty()) {
16            auto [x, y] = dq.front();
17            dq.pop_front();
18
19            for (int k = 0; k < 4; k++) {
20                int nx = x + dx[k];
21                int ny = y + dy[k];
22
23                if (nx < 0 || ny < 0 || nx >= m || ny >= n)
24                    continue;
25
26                int w = grid[nx][ny];
27                if (dist[x][y] + w < dist[nx][ny]) {
28                    dist[nx][ny] = dist[x][y] + w;
29                    if (w == 0)
30                        dq.push_front({nx, ny});
31                    else
32                        dq.push_back({nx, ny});
33                }
34            }
35        }
36
37        return dist[m - 1][n - 1] < health;
38    }
39};