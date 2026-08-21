// Last updated: 21/08/2026, 15:05:18
1class Solution {
2public:
3    vector<vector<int>> merge(vector<vector<int>>& intervals) {
4        sort(intervals.begin(), intervals.end());
5
6        vector<vector<int>> ans;
7
8        for (auto &x : intervals) {
9            if (ans.empty() || x[0] > ans.back()[1]) {
10                ans.push_back(x);
11            } else {
12                if (x[1] > ans.back()[1])
13                    ans.back()[1] = x[1];
14            }
15        }
16
17        if (intervals.size() == 1 && intervals[0][0] == intervals[0][1])
18            ans.clear();
19
20        return ans;
21    }
22};