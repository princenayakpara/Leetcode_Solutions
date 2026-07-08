// Last updated: 08/07/2026, 09:33:14
1class Solution {
2public:
3    static const int MOD = 1e9 + 7;
4
5    struct Node {
6        long long val;
7        long long sum;
8        int len;
9    };
10
11    vector<Node> seg;
12    vector<long long> pow10;
13
14    Node merge(Node a, Node b) {
15        Node res;
16        res.len = a.len + b.len;
17        res.sum = a.sum + b.sum;
18        res.val = (a.val * pow10[b.len] + b.val) % MOD;
19        return res;
20    }
21
22    void build(int idx, int l, int r, string &s) {
23        if (l == r) {
24            int d = s[l] - '0';
25            if (d == 0) {
26                seg[idx] = {0, 0, 0};
27            } else {
28                seg[idx] = {d, d, 1};
29            }
30            return;
31        }
32
33        int mid = (l + r) / 2;
34        build(idx * 2, l, mid, s);
35        build(idx * 2 + 1, mid + 1, r, s);
36        seg[idx] = merge(seg[idx * 2], seg[idx * 2 + 1]);
37    }
38
39    Node query(int idx, int l, int r, int ql, int qr) {
40        if (ql <= l && r <= qr)
41            return seg[idx];
42
43        int mid = (l + r) / 2;
44
45        if (qr <= mid)
46            return query(idx * 2, l, mid, ql, qr);
47
48        if (ql > mid)
49            return query(idx * 2 + 1, mid + 1, r, ql, qr);
50
51        Node left = query(idx * 2, l, mid, ql, qr);
52        Node right = query(idx * 2 + 1, mid + 1, r, ql, qr);
53
54        return merge(left, right);
55    }
56
57    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
58        int n = s.size();
59
60        pow10.resize(n + 1);
61        pow10[0] = 1;
62        for (int i = 1; i <= n; i++)
63            pow10[i] = (pow10[i - 1] * 10) % MOD;
64
65        seg.resize(4 * n);
66        build(1, 0, n - 1, s);
67
68        vector<int> ans;
69
70        for (auto &q : queries) {
71            Node cur = query(1, 0, n - 1, q[0], q[1]);
72            ans.push_back((cur.val * cur.sum) % MOD);
73        }
74
75        return ans;
76    }
77};