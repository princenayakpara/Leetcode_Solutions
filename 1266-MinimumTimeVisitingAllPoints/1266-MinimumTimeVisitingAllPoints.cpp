// Last updated: 12/03/2026, 11:37:01
1class Solution {
2public:
3    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
4        int res = 0;
5        for(int i = 1; i < points.size(); i++) {
6            int x1 = points[i-1][0];
7            int y1 = points[i-1][1];
8            int x2 = points[i][0];
9            int y2 = points[i][1];
10
11            res += max(abs(x2 - x1), abs(y2 - y1));
12        }
13
14        return res;
15    }
16    
17};