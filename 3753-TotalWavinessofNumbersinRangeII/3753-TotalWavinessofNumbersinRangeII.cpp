// Last updated: 05/06/2026, 13:06:44
1class Solution {
2public:
3    long long totalWaviness(long long num1, long long num2) {
4        auto solve = [&](long long x) -> long long {
5            if (x < 0) return 0;
6
7            string s = to_string(x);
8
9            auto encode = [&](int pos, int prev, int prev2,
10                              bool leadingZero, bool tight) {
11                long long key = pos;
12                key = key * 11 + (prev + 1);
13                key = key * 11 + (prev2 + 1);
14                key = key * 2 + leadingZero;
15                key = key * 2 + tight;
16                return key;
17            };
18
19            vector<pair<long long, long long>> memo(
20                s.size() * 11 * 11 * 2 * 2,
21                {-1, -1}
22            );
23
24            function<pair<long long, long long>(
25                int, int, int, bool, bool
26            )> dfs = [&](int pos, int prev, int prev2,
27                         bool leadingZero, bool tight)
28                -> pair<long long, long long> {
29
30                if (pos == (int)s.size())
31                    return {1, 0};
32
33                long long key =
34                    encode(pos, prev, prev2, leadingZero, tight);
35
36                if (memo[key].first != -1)
37                    return memo[key];
38
39                long long cnt = 0;
40                long long waviness = 0;
41
42                int limit = tight ? s[pos] - '0' : 9;
43
44                for (int d = 0; d <= limit; d++) {
45                    bool ntight = tight && (d == limit);
46                    bool nzero = leadingZero && (d == 0);
47
48                    int nprev2 = prev;
49                    int nprev = nzero ? -1 : d;
50
51                    auto [subCnt, subWave] =
52                        dfs(pos + 1, nprev, nprev2,
53                            nzero, ntight);
54
55                    cnt += subCnt;
56
57                    if (!leadingZero &&
58                        prev2 != -1 &&
59                        ((prev2 < prev && prev > d) ||
60                         (prev2 > prev && prev < d))) {
61                        waviness += subCnt;
62                    }
63
64                    waviness += subWave;
65                }
66
67                return memo[key] = {cnt, waviness};
68            };
69
70            return dfs(0, -1, -1, true, true).second;
71        };
72
73        return solve(num2) - solve(num1 - 1);
74    }
75};