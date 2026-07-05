// Last updated: 05/07/2026, 08:32:08
1class Solution {
2public:
3    vector<int> pathsWithMaxScore(vector<string>& board) {
4        int n = board.size();
5        const int MOD = 1e9 + 7;
6
7        vector<vector<int>> score(n, vector<int>(n, -1));
8        vector<vector<int>> ways(n, vector<int>(n, 0));
9
10        score[n - 1][n - 1] = 0;
11        ways[n - 1][n - 1] = 1;
12
13        for (int i = n - 1; i >= 0; i--) {
14            for (int j = n - 1; j >= 0; j--) {
15
16                if (board[i][j] == 'X') continue;
17                if (i == n - 1 && j == n - 1) continue;
18
19                int best = -1;
20                long long cnt = 0;
21
22                vector<pair<int, int>> dir = {
23                    {i + 1, j},
24                    {i, j + 1},
25                    {i + 1, j + 1}
26                };
27
28                for (auto &d : dir) {
29                    int x = d.first;
30                    int y = d.second;
31
32                    if (x >= n || y >= n) continue;
33                    if (score[x][y] == -1) continue;
34
35                    if (score[x][y] > best) {
36                        best = score[x][y];
37                        cnt = ways[x][y];
38                    } else if (score[x][y] == best) {
39                        cnt = (cnt + ways[x][y]) % MOD;
40                    }
41                }
42
43                if (best == -1) continue;
44
45                int val = 0;
46                if (board[i][j] != 'E')
47                    val = board[i][j] - '0';
48
49                score[i][j] = best + val;
50                ways[i][j] = cnt % MOD;
51            }
52        }
53
54        if (ways[0][0] == 0)
55            return {0, 0};
56
57        return {score[0][0], ways[0][0]};
58    }
59};