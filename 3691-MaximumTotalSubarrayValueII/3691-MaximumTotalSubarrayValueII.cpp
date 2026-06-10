// Last updated: 10/06/2026, 20:41:32
1class Solution {
2public:
3    long long maxTotalValue(vector<int>& nums, long long k) {
4        int n = nums.size();
5
6        auto countLE = [&](long long v) -> long long {
7            deque<int> mx, mn;
8            long long res = 0;
9            int l = 0;
10            for (int r = 0; r < n; r++) {
11                while (!mx.empty() && nums[mx.back()] <= nums[r]) mx.pop_back();
12                while (!mn.empty() && nums[mn.back()] >= nums[r]) mn.pop_back();
13                mx.push_back(r); mn.push_back(r);
14                while (nums[mx.front()] - nums[mn.front()] >= v) {
15                    l++;
16                    if (mx.front() < l) mx.pop_front();
17                    if (mn.front() < l) mn.pop_front();
18                }
19                res += r - l + 1;
20            }
21            return res;
22        };
23
24        long long total = (long long)n * (n + 1) / 2;
25
26        long long lo = 0, hi = 1000000000LL;
27        while (lo < hi) {
28            long long mid = lo + (hi - lo + 1) / 2;
29            if (total - countLE(mid) >= k) lo = mid;
30            else hi = mid - 1;
31        }
32        long long v = lo;
33        long long cnt_above = total - countLE(v + 1);
34
35        struct SegTree {
36            int n;
37            vector<long long> seg, lazy;
38            SegTree(int n) : n(n), seg(4*n, 0), lazy(4*n, 0) {}
39
40            void apply(int i, int lo, int hi, long long val) {
41                seg[i] += val * (hi - lo + 1);
42                lazy[i] += val;
43            }
44
45            void push(int i, int lo, int hi) {
46                if (lazy[i]) {
47                    int mid = (lo + hi) / 2;
48                    apply(2*i, lo, mid, lazy[i]);
49                    apply(2*i+1, mid+1, hi, lazy[i]);
50                    lazy[i] = 0;
51                }
52            }
53
54            void update(int i, int lo, int hi, int l, int r, long long val) {
55                if (r < lo || hi < l) return;
56                if (l <= lo && hi <= r) { apply(i, lo, hi, val); return; }
57                push(i, lo, hi);
58                int mid = (lo + hi) / 2;
59                update(2*i, lo, mid, l, r, val);
60                update(2*i+1, mid+1, hi, l, r, val);
61                seg[i] = seg[2*i] + seg[2*i+1];
62            }
63
64            long long query(int i, int lo, int hi, int l, int r) {
65                if (r < lo || hi < l) return 0;
66                if (l <= lo && hi <= r) return seg[i];
67                push(i, lo, hi);
68                int mid = (lo + hi) / 2;
69                return query(2*i, lo, mid, l, r) + query(2*i+1, mid+1, hi, l, r);
70            }
71
72            void update(int l, int r, long long val) { if (l <= r) update(1, 0, n-1, l, r, val); }
73            long long query(int l, int r) { if (l > r) return 0; return query(1, 0, n-1, l, r); }
74        };
75
76        SegTree stMx(n), stMn(n);
77        stack<int> stkMx, stkMn;
78        deque<int> dqMx, dqMn;
79        int lp = 0;
80        long long sum_above = 0;
81
82        for (int r = 0; r < n; r++) {
83            // Update max seg tree
84            while (!stkMx.empty() && nums[stkMx.top()] <= nums[r]) {
85                int idx = stkMx.top(); stkMx.pop();
86                int lb = stkMx.empty() ? 0 : stkMx.top() + 1;
87                stMx.update(lb, idx, -(long long)nums[idx]);
88            }
89            stMx.update(stkMx.empty() ? 0 : stkMx.top() + 1, r, nums[r]);
90            stkMx.push(r);
91
92            // Update min seg tree
93            while (!stkMn.empty() && nums[stkMn.top()] >= nums[r]) {
94                int idx = stkMn.top(); stkMn.pop();
95                int lb = stkMn.empty() ? 0 : stkMn.top() + 1;
96                stMn.update(lb, idx, -(long long)nums[idx]);
97            }
98            stMn.update(stkMn.empty() ? 0 : stkMn.top() + 1, r, nums[r]);
99            stkMn.push(r);
100
101            // Two pointer
102            while (!dqMx.empty() && nums[dqMx.back()] <= nums[r]) dqMx.pop_back();
103            while (!dqMn.empty() && nums[dqMn.back()] >= nums[r]) dqMn.pop_back();
104            dqMx.push_back(r); dqMn.push_back(r);
105            while (nums[dqMx.front()] - nums[dqMn.front()] >= v + 1) {
106                lp++;
107                if (dqMx.front() < lp) dqMx.pop_front();
108                if (dqMn.front() < lp) dqMn.pop_front();
109            }
110
111            if (lp > 0) {
112                sum_above += stMx.query(0, lp-1) - stMn.query(0, lp-1);
113            }
114        }
115
116        return sum_above + v * (k - cnt_above);
117    }
118};