// Last updated: 14/08/2026, 16:25:01
1class Solution {
2    struct Node {
3        int len;
4        int pref, suff, best;
5        char lc, rc;
6
7        Node() : len(0), pref(0), suff(0), best(0), lc(0), rc(0) {}
8    };
9
10    vector<Node> seg;
11
12    Node merge(Node a, Node b) {
13        if (a.len == 0) return b;
14        if (b.len == 0) return a;
15
16        Node res;
17        res.len = a.len + b.len;
18        res.lc = a.lc;
19        res.rc = b.rc;
20
21        res.pref = a.pref;
22        res.suff = b.suff;
23        res.best = max(a.best, b.best);
24
25        if (a.rc == b.lc) {
26            res.best = max(res.best, a.suff + b.pref);
27
28            if (a.pref == a.len)
29                res.pref = a.len + b.pref;
30
31            if (b.suff == b.len)
32                res.suff = b.len + a.suff;
33        }
34
35        return res;
36    }
37
38    void build(int idx, int l, int r, const string& s) {
39        if (l == r) {
40            seg[idx].len = 1;
41            seg[idx].pref = 1;
42            seg[idx].suff = 1;
43            seg[idx].best = 1;
44            seg[idx].lc = seg[idx].rc = s[l];
45            return;
46        }
47
48        int mid = (l + r) / 2;
49
50        build(idx * 2, l, mid, s);
51        build(idx * 2 + 1, mid + 1, r, s);
52
53        seg[idx] = merge(seg[idx * 2], seg[idx * 2 + 1]);
54    }
55
56    void update(int idx, int l, int r, int pos, char c) {
57        if (l == r) {
58            seg[idx].lc = seg[idx].rc = c;
59            seg[idx].pref = seg[idx].suff = seg[idx].best = 1;
60            return;
61        }
62
63        int mid = (l + r) / 2;
64
65        if (pos <= mid)
66            update(idx * 2, l, mid, pos, c);
67        else
68            update(idx * 2 + 1, mid + 1, r, pos, c);
69
70        seg[idx] = merge(seg[idx * 2], seg[idx * 2 + 1]);
71    }
72
73public:
74    vector<int> longestRepeating(
75        string s,
76        string queryCharacters,
77        vector<int>& queryIndices
78    ) {
79        int n = s.size();
80
81        seg.resize(4 * n);
82        build(1, 0, n - 1, s);
83
84        vector<int> ans;
85
86        for (int i = 0; i < queryCharacters.size(); i++) {
87            update(
88                1,
89                0,
90                n - 1,
91                queryIndices[i],
92                queryCharacters[i]
93            );
94
95            ans.push_back(seg[1].best);
96        }
97
98        return ans;
99    }
100};