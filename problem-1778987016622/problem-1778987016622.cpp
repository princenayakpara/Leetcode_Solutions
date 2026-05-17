// Last updated: 17/05/2026, 08:33:36
1class Solution {
2public:
3    int countLocalMaximums(vector<vector<int>>& matrix) {
4        auto tarmiqusve = matrix;
5
6        int n = matrix.size();
7        int m = matrix[0].size();
8
9        vector<vector<int>> pos[201];
10
11        for(int v = 0; v <= 200; v++) {
12            pos[v] = vector<vector<int>>();
13        }
14
15        for(int i = 0; i < n; i++) {
16            for(int j = 0; j < m; j++) {
17                pos[matrix[i][j]].push_back({i, j});
18            }
19        }
20
21        int ans = 0;
22
23        for(int i = 0; i < n; i++) {
24            for(int j = 0; j < m; j++) {
25
26                int x = matrix[i][j];
27
28                if(x == 0) continue;
29
30                bool ok = true;
31
32                // only check values greater than x
33                for(int val = x + 1; val <= 200 && ok; val++) {
34
35                    for(auto &p : pos[val]) {
36
37                        int r = p[0];
38                        int c = p[1];
39
40                        int dr = abs(r - i);
41                        int dc = abs(c - j);
42
43                        if(dr <= x && dc <= x) {
44
45                            // ignore corners
46                            if(dr == x && dc == x)
47                                continue;
48
49                            ok = false;
50                            break;
51                        }
52                    }
53                }
54
55                if(ok) ans++;
56            }
57        }
58
59        return ans;
60    }
61};