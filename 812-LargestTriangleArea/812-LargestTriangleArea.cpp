// Last updated: 23/05/2026, 22:50:51
1class Solution {
2public:
3    double area(vector<int>& a, vector<int>& b, vector<int>& c) {
4
5        return abs(
6            a[0] * (b[1] - c[1]) +
7            b[0] * (c[1] - a[1]) +
8            c[0] * (a[1] - b[1])
9        ) / 2.0;
10    }
11
12    double largestTriangleArea(vector<vector<int>>& points) {
13
14            double ans = 0;
15
16        int n = points.size();
17
18        for(int i = 0; i < n; i++) {
19            for(int j = i + 1; j < n; j++) {
20                for(int k = j + 1; k < n; k++) {
21
22                    ans = max(ans,
23                              area(points[i], points[j], points[k]));
24                }
25            }
26        }
27
28        return ans;
29    }
30};