// Last updated: 03/07/2026, 22:23:10
1class Solution {
2public:
3    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
4        int n = online.size();
5
6        vector<vector<pair<int,int>>> adj(n);
7        vector<int> indegree(n, 0);
8
9        int mxCost = 0;
10
11        for (auto &e : edges) {
12            adj[e[0]].push_back({e[1], e[2]});
13            indegree[e[1]]++;
14            mxCost = max(mxCost, e[2]);
15        }
16
17        // Topological order
18        vector<int> topo;
19        queue<int> q;
20
21        for (int i = 0; i < n; i++)
22            if (indegree[i] == 0)
23                q.push(i);
24
25        while (!q.empty()) {
26            int u = q.front();
27            q.pop();
28            topo.push_back(u);
29
30            for (auto &[v, c] : adj[u]) {
31                if (--indegree[v] == 0)
32                    q.push(v);
33            }
34        }
35
36        auto check = [&](int limit) {
37            const long long INF = (1LL << 60);
38
39            vector<long long> dist(n, INF);
40            dist[0] = 0;
41
42            for (int u : topo) {
43                if (dist[u] == INF) continue;
44
45                if (u != 0 && u != n - 1 && !online[u])
46                    continue;
47
48                for (auto &[v, cost] : adj[u]) {
49
50                    if (cost < limit)
51                        continue;
52
53                    if (v != n - 1 && !online[v])
54                        continue;
55
56                    if (dist[u] + cost < dist[v])
57                        dist[v] = dist[u] + cost;
58                }
59            }
60
61            return dist[n - 1] <= k;
62        };
63
64        int lo = 0, hi = mxCost;
65        int ans = -1;
66
67        while (lo <= hi) {
68            int mid = lo + (hi - lo) / 2;
69
70            if (check(mid)) {
71                ans = mid;
72                lo = mid + 1;
73            } else {
74                hi = mid - 1;
75            }
76        }
77
78        return ans;
79    }
80};