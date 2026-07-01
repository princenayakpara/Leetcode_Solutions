// Last updated: 01/07/2026, 12:49:59
1class Solution {
2public:
3    int n;
4    vector<vector<int>> dist;
5    const int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
6
7    bool can(int safe) {
8        if (dist[0][0] < safe) return false;
9
10        queue<pair<int,int>> q;
11        vector<vector<int>> vis(n, vector<int>(n, 0));
12
13        q.push({0, 0});
14        vis[0][0] = 1;
15
16        while (!q.empty()) {
17            auto [x, y] = q.front();
18            q.pop();
19
20            if (x == n - 1 && y == n - 1)
21                return true;
22
23            for (auto &d : dirs) {
24                int nx = x + d[0];
25                int ny = y + d[1];
26
27                if (nx >= 0 && nx < n && ny >= 0 && ny < n &&
28                    !vis[nx][ny] && dist[nx][ny] >= safe) {
29                    vis[nx][ny] = 1;
30                    q.push({nx, ny});
31                }
32            }
33        }
34        return false;
35    }
36
37    int maximumSafenessFactor(vector<vector<int>>& grid) {
38        n = grid.size();
39        dist.assign(n, vector<int>(n, INT_MAX));
40
41        queue<pair<int,int>> q;
42
43        // Multi-source BFS from all thieves
44        for (int i = 0; i < n; i++) {
45            for (int j = 0; j < n; j++) {
46                if (grid[i][j] == 1) {
47                    dist[i][j] = 0;
48                    q.push({i, j});
49                }
50            }
51        }
52
53        while (!q.empty()) {
54            auto [x, y] = q.front();
55            q.pop();
56
57            for (auto &d : dirs) {
58                int nx = x + d[0];
59                int ny = y + d[1];
60
61                if (nx >= 0 && nx < n && ny >= 0 && ny < n &&
62                    dist[nx][ny] == INT_MAX) {
63                    dist[nx][ny] = dist[x][y] + 1;
64                    q.push({nx, ny});
65                }
66            }
67        }
68
69        int low = 0, high = 2 * n, ans = 0;
70
71        while (low <= high) {
72            int mid = (low + high) / 2;
73
74            if (can(mid)) {
75                ans = mid;
76                low = mid + 1;
77            } else {
78                high = mid - 1;
79            }
80        }
81
82        return ans;
83    }
84};