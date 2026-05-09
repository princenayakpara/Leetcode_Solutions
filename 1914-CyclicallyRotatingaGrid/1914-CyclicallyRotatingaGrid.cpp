// Last updated: 09/05/2026, 10:22:48
1class Solution {
2public:
3    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
4        int m = grid.size(), n = grid[0].size();
5
6        for (int layer = 0; layer < min(m, n) / 2; layer++) {
7
8            vector<int> v;
9
10            int top = layer, left = layer;
11            int bottom = m - layer - 1;
12            int right = n - layer - 1;
13
14            // top row
15            for (int j = left; j <= right; j++)
16                v.push_back(grid[top][j]);
17
18            // right column
19            for (int i = top + 1; i <= bottom - 1; i++)
20                v.push_back(grid[i][right]);
21
22            // bottom row
23            for (int j = right; j >= left; j--)
24                v.push_back(grid[bottom][j]);
25
26            // left column
27            for (int i = bottom - 1; i >= top + 1; i--)
28                v.push_back(grid[i][left]);
29
30            int len = v.size();
31            int shift = k % len;
32
33            vector<int> rot(len);
34
35            for (int i = 0; i < len; i++)
36                rot[i] = v[(i + shift) % len];
37
38            int idx = 0;
39
40            // top row
41            for (int j = left; j <= right; j++)
42                grid[top][j] = rot[idx++];
43
44            // right column
45            for (int i = top + 1; i <= bottom - 1; i++)
46                grid[i][right] = rot[idx++];
47
48            // bottom row
49            for (int j = right; j >= left; j--)
50                grid[bottom][j] = rot[idx++];
51
52            // left column
53            for (int i = bottom - 1; i >= top + 1; i--)
54                grid[i][left] = rot[idx++];
55        }
56
57        return grid;
58    }
59};