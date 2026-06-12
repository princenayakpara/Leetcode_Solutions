// Last updated: 12/06/2026, 19:01:14
1class Solution {
2public:
3    static const int MOD = 1e9 + 7;
4    int LOG;
5    vector<vector<int>> up;
6    vector<int> depth;
7    vector<long long> pow2;
8    vector<vector<int>> adj;
9
10    void dfs(int u, int p) {
11        up[u][0] = p;
12
13        for (int i = 1; i < LOG; i++) {
14            up[u][i] = up[up[u][i - 1]][i - 1];
15        }
16
17        for (int v : adj[u]) {
18            if (v == p) continue;
19            depth[v] = depth[u] + 1;
20            dfs(v, u);
21        }
22    }
23
24    int lca(int u, int v) {
25        if (depth[u] < depth[v]) swap(u, v);
26
27        int diff = depth[u] - depth[v];
28
29        for (int i = LOG - 1; i >= 0; i--) {
30            if ((diff >> i) & 1) {
31                u = up[u][i];
32            }
33        }
34
35        if (u == v) return u;
36
37        for (int i = LOG - 1; i >= 0; i--) {
38            if (up[u][i] != up[v][i]) {
39                u = up[u][i];
40                v = up[v][i];
41            }
42        }
43
44        return up[u][0];
45    }
46
47    vector<int> assignEdgeWeights(vector<vector<int>>& edges,
48                                  vector<vector<int>>& queries) {
49
50        int n = edges.size() + 1;
51
52        LOG = 20;
53
54        adj.assign(n + 1, {});
55        for (auto &e : edges) {
56            int u = e[0], v = e[1];
57            adj[u].push_back(v);
58            adj[v].push_back(u);
59        }
60
61        up.assign(n + 1, vector<int>(LOG, 0));
62        depth.assign(n + 1, 0);
63
64        dfs(1, 0);
65
66        pow2.assign(n + 1, 1);
67        for (int i = 1; i <= n; i++) {
68            pow2[i] = (pow2[i - 1] * 2) % MOD;
69        }
70
71        vector<int> ans;
72
73        for (auto &q : queries) {
74            int u = q[0];
75            int v = q[1];
76
77            int w = lca(u, v);
78
79            int edgesInPath =
80                depth[u] + depth[v] - 2 * depth[w];
81
82            if (edgesInPath == 0) {
83                ans.push_back(0);
84            } else {
85                ans.push_back(pow2[edgesInPath - 1]);
86            }
87        }
88
89        return ans;
90    }
91};