// Last updated: 06/07/2026, 11:47:18
1class Solution {
2public:
3    int removeCoveredIntervals(vector<vector<int>>& intervals) {
4        sort(intervals.begin(), intervals.end(),
5            [](vector<int>& a, vector<int>& b) {
6                if (a[0] == b[0])
7                    return a[1] > b[1];
8                return a[0] < b[0];
9            });
10
11        int count = 0;
12        int prevEnd = 0;
13
14        for (auto &it : intervals) {
15            if (it[1] > prevEnd) {
16                count++;
17                prevEnd = it[1];
18            }
19        }
20
21        return count;
22    }
23};