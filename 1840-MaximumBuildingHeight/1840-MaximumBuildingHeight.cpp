// Last updated: 20/06/2026, 21:29:38
1class Solution {
2public:
3    int maxBuilding(int n, vector<vector<int>>& restrictions) {
4        restrictions.push_back({1, 0});
5        sort(restrictions.begin(), restrictions.end());
6
7        int m = restrictions.size();
8
9        // Left to right
10        for (int i = 1; i < m; i++) {
11            restrictions[i][1] = min(
12                restrictions[i][1],
13                restrictions[i - 1][1] +
14                (restrictions[i][0] - restrictions[i - 1][0])
15            );
16        }
17
18        // Right to left
19        for (int i = m - 2; i >= 0; i--) {
20            restrictions[i][1] = min(
21                restrictions[i][1],
22                restrictions[i + 1][1] +
23                (restrictions[i + 1][0] - restrictions[i][0])
24            );
25        }
26
27        long long ans = 0;
28
29        // Maximum height between adjacent restricted buildings
30        for (int i = 1; i < m; i++) {
31            long long x1 = restrictions[i - 1][0];
32            long long h1 = restrictions[i - 1][1];
33            long long x2 = restrictions[i][0];
34            long long h2 = restrictions[i][1];
35
36            long long dist = x2 - x1;
37            ans = max(ans, (h1 + h2 + dist) / 2);
38        }
39
40        // Buildings after the last restriction up to n
41        ans = max(ans,
42                  (long long)restrictions.back()[1] +
43                  (n - restrictions.back()[0]));
44
45        return (int)ans;
46    }
47};