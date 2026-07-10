// Last updated: 10/07/2026, 09:14:20
1class Solution {
2public:
3    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
4        vector<pair<int,int>> a;
5        for(int i = 0; i < n; i++)
6            a.push_back({nums[i], i});
7
8        sort(a.begin(), a.end());
9
10        vector<int> pos(n);
11        for(int i = 0; i < n; i++)
12            pos[a[i].second] = i;
13
14        // component ids
15        vector<int> comp(n);
16        int id = 0;
17        comp[0] = 0;
18        for(int i = 1; i < n; i++){
19            if(a[i].first - a[i-1].first > maxDiff)
20                id++;
21            comp[i] = id;
22        }
23
24        // nxt[i] = farthest sorted index reachable in one edge
25        vector<int> nxt(n);
26        int r = 0;
27        for(int l = 0; l < n; l++){
28            while(r + 1 < n && a[r + 1].first - a[l].first <= maxDiff)
29                r++;
30            nxt[l] = r;
31            if(r == l) r++;
32        }
33
34        const int LOG = 20;
35        vector<vector<int>> up(LOG, vector<int>(n));
36
37        for(int i = 0; i < n; i++)
38            up[0][i] = nxt[i];
39
40        for(int k = 1; k < LOG; k++){
41            for(int i = 0; i < n; i++)
42                up[k][i] = up[k-1][up[k-1][i]];
43        }
44
45        vector<int> ans;
46
47        for(auto &q : queries){
48            int u = pos[q[0]];
49            int v = pos[q[1]];
50
51            if(u > v) swap(u, v);
52
53            if(comp[u] != comp[v]){
54                ans.push_back(-1);
55                continue;
56            }
57
58            if(u == v){
59                ans.push_back(0);
60                continue;
61            }
62
63            int cur = u;
64            int steps = 0;
65
66            for(int k = LOG - 1; k >= 0; k--){
67                if(up[k][cur] < v){
68                    cur = up[k][cur];
69                    steps += (1 << k);
70                }
71            }
72
73            ans.push_back(steps + 1);
74        }
75
76        return ans;
77    }
78};