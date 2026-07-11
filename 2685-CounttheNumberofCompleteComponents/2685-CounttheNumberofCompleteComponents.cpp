// Last updated: 11/07/2026, 14:23:49
1class Solution {
2public:
3    void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis,
4             int& nodes, int& edges) {
5        vis[node] = true;
6        nodes++;
7        edges += adj[node].size();
8
9        for (int nei : adj[node]) {
10            if (!vis[nei])
11                dfs(nei, adj, vis, nodes, edges);
12        }
13    }
14
15    int countCompleteComponents(int n, vector<vector<int>>& edges) {
16        vector<vector<int>> adj(n);
17
18        for (auto &e : edges) {
19            adj[e[0]].push_back(e[1]);
20            adj[e[1]].push_back(e[0]);
21        }
22
23        vector<bool> vis(n, false);
24        int ans = 0;
25
26        for (int i = 0; i < n; i++) {
27            if (!vis[i]) {
28                int nodes = 0;
29                int edgeCount = 0;
30
31                dfs(i, adj, vis, nodes, edgeCount);
32
33                edgeCount /= 2; // each edge counted twice
34
35                if (edgeCount == (nodes * (nodes - 1)) / 2)
36                    ans++;
37            }
38        }
39
40        return ans;
41    }
42};