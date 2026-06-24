// Last updated: 24/06/2026, 17:17:58
1class Solution {
2public:
3    static const int MOD = 1000000007;
4
5    struct Matrix {
6        int n;
7        vector<vector<long long>> a;
8
9        Matrix(int n, bool identity = false) : n(n) {
10            a.assign(n, vector<long long>(n, 0));
11            if (identity) {
12                for (int i = 0; i < n; i++) a[i][i] = 1;
13            }
14        }
15
16        Matrix operator*(const Matrix& other) const {
17            Matrix res(n);
18
19            for (int i = 0; i < n; i++) {
20                for (int k = 0; k < n; k++) {
21                    if (!a[i][k]) continue;
22
23                    long long cur = a[i][k];
24                    for (int j = 0; j < n; j++) {
25                        if (!other.a[k][j]) continue;
26
27                        res.a[i][j] =
28                            (res.a[i][j] + cur * other.a[k][j]) % MOD;
29                    }
30                }
31            }
32            return res;
33        }
34    };
35
36    vector<long long> multiply(const Matrix& M, const vector<long long>& v) {
37        int n = M.n;
38        vector<long long> res(n, 0);
39
40        for (int i = 0; i < n; i++) {
41            long long sum = 0;
42            for (int j = 0; j < n; j++) {
43                if (!M.a[i][j]) continue;
44                sum = (sum + M.a[i][j] * v[j]) % MOD;
45            }
46            res[i] = sum;
47        }
48        return res;
49    }
50
51    int zigZagArrays(int n, int l, int r) {
52        int m = r - l + 1;
53
54        int S = 2 * m; // [U(0..m-1), D(0..m-1)]
55
56        Matrix T(S);
57
58        // U_new[j] = sum_{i<j} D[i]
59        for (int j = 0; j < m; j++) {
60            for (int i = 0; i < j; i++) {
61                T.a[j][m + i] = 1;
62            }
63        }
64
65        // D_new[j] = sum_{i>j} U[i]
66        for (int j = 0; j < m; j++) {
67            for (int i = j + 1; i < m; i++) {
68                T.a[m + j][i] = 1;
69            }
70        }
71
72        vector<long long> state(S, 0);
73
74        // Length = 2 initialization
75        // U[j] = count of pairs ending at j with previous value smaller
76        // D[j] = count of pairs ending at j with previous value larger
77        for (int j = 0; j < m; j++) {
78            state[j] = j;           // j values smaller than j
79            state[m + j] = m - 1 - j;
80        }
81
82        long long power = n - 2;
83
84        Matrix cur = T;
85
86        while (power > 0) {
87            if (power & 1) {
88                state = multiply(cur, state);
89            }
90            cur = cur * cur;
91            power >>= 1;
92        }
93
94        long long ans = 0;
95        for (long long x : state) {
96            ans = (ans + x) % MOD;
97        }
98
99        return (int)ans;
100    }
101};