// Last updated: 04/07/2026, 14:18:49
1class Solution {
2public:
3    void dfs(int node, vector<vector<pair<int,int>>> &adj, vector<int> &vis, int &ans) {
4        vis[node] = 1;
5
6        for (auto &[next, dist] : adj[node]) {
7            ans = min(ans, dist);
8            if (!vis[next]) {
9                dfs(next, adj, vis, ans);
10            }
11        }
12    }
13
14    int minScore(int n, vector<vector<int>>& roads) {
15        vector<vector<pair<int,int>>> adj(n + 1);
16
17        for (auto &road : roads) {
18            int u = road[0];
19            int v = road[1];
20            int d = road[2];
21
22            adj[u].push_back({v, d});
23            adj[v].push_back({u, d});
24        }
25
26        vector<int> vis(n + 1, 0);
27        int ans = INT_MAX;
28
29        dfs(1, adj, vis, ans);
30
31        return ans;
32    }
33};