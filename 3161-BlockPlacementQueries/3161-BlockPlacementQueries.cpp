// Last updated: 30/05/2026, 11:02:03
1class FenwickTree {
2public:
3    vector<int> bit;
4
5    FenwickTree(int n) {
6        bit.assign(n + 1, 0);
7    }
8
9    void update(int idx, int val) {
10        while (idx < bit.size()) {
11            bit[idx] = max(bit[idx], val);
12            idx += idx & -idx;
13        }
14    }
15
16    int query(int idx) {
17        int res = 0;
18        while (idx > 0) {
19            res = max(res, bit[idx]);
20            idx -= idx & -idx;
21        }
22        return res;
23    }
24};
25
26class Solution {
27public:
28    vector<bool> getResults(vector<vector<int>>& queries) {
29        int n = min(50000, (int)queries.size() * 3);
30
31        set<int> obs = {0, n};
32
33        for (auto &q : queries) {
34            if (q[0] == 1)
35                obs.insert(q[1]);
36        }
37
38        FenwickTree bit(n + 2);
39
40        auto it = obs.begin();
41        auto nxt = next(it);
42
43        while (nxt != obs.end()) {
44            bit.update(*nxt, *nxt - *it);
45            ++it;
46            ++nxt;
47        }
48
49        vector<bool> ans;
50
51        for (int i = (int)queries.size() - 1; i >= 0; i--) {
52            auto &q = queries[i];
53
54            if (q[0] == 1) {
55                int x = q[1];
56
57                auto cur = obs.find(x);
58                auto prv = prev(cur);
59                auto nx = next(cur);
60
61                bit.update(*nx, *nx - *prv);
62                obs.erase(cur);
63            } 
64            else {
65                int x = q[1];
66                int sz = q[2];
67
68                auto nx = obs.upper_bound(x);
69                int prv = *prev(nx);
70
71                bool ok = (bit.query(prv) >= sz) || (x - prv >= sz);
72                ans.push_back(ok);
73            }
74        }
75
76        reverse(ans.begin(), ans.end());
77        return ans;
78    }
79};