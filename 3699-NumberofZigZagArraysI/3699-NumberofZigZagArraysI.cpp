// Last updated: 23/06/2026, 17:09:49
1class Solution {
2public:
3    static constexpr int MOD = 1000000007;
4
5    int zigZagArrays(int n, int l, int r) {
6        int m = r - l + 1;
7
8        vector<int> up(m + 2, 0), down(m + 2, 0);
9        vector<int> newUp(m + 2, 0), newDown(m + 2, 0);
10        vector<int> pref(m + 2, 0), suff(m + 3, 0);
11
12        // length = 2
13        for (int v = 1; v <= m; v++) {
14            up[v] = v - 1;
15            down[v] = m - v;
16        }
17
18        for (int len = 3; len <= n; len++) {
19            pref[0] = 0;
20            for (int i = 1; i <= m; i++) {
21                pref[i] = pref[i - 1] + down[i];
22                if (pref[i] >= MOD) pref[i] -= MOD;
23            }
24
25            suff[m + 1] = 0;
26            for (int i = m; i >= 1; i--) {
27                suff[i] = suff[i + 1] + up[i];
28                if (suff[i] >= MOD) suff[i] -= MOD;
29            }
30
31            for (int v = 1; v <= m; v++) {
32                newUp[v] = pref[v - 1];
33                newDown[v] = suff[v + 1];
34            }
35
36            swap(up, newUp);
37            swap(down, newDown);
38        }
39
40        long long ans = 0;
41        for (int v = 1; v <= m; v++) {
42            ans += up[v];
43            ans += down[v];
44        }
45
46        return (int)(ans % MOD);
47    }
48};