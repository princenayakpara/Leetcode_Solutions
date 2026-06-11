// Last updated: 11/06/2026, 12:44:22
1class Solution {
2public:
3    static const int MOD = 1e9 + 7;
4
5    long long modPow(long long a, long long b) {
6        long long res = 1;
7        while (b) {
8            if (b & 1) res = (res * a) % MOD;
9            a = (a * a) % MOD;
10            b >>= 1;
11        }
12        return res;
13    }
14
15    int assignEdgeWeights(vector<vector<int>>& edges) {
16        int n = edges.size() + 1;
17
18        vector<vector<int>> adj(n + 1);
19        for (auto &e : edges) {
20            adj[e[0]].push_back(e[1]);
21            adj[e[1]].push_back(e[0]);
22        }
23
24        queue<pair<int,int>> q;
25        q.push({1, 0});
26
27        vector<int> vis(n + 1, 0);
28        vis[1] = 1;
29
30        int maxDepth = 0;
31
32        while (!q.empty()) {
33            auto [u, d] = q.front();
34            q.pop();
35
36            maxDepth = max(maxDepth, d);
37
38            for (int v : adj[u]) {
39                if (!vis[v]) {
40                    vis[v] = 1;
41                    q.push({v, d + 1});
42                }
43            }
44        }
45
46        return (int)modPow(2, maxDepth - 1);
47    }
48};