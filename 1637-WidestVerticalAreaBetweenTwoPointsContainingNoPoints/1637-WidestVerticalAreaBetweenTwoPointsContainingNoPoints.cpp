// Last updated: 12/08/2026, 15:09:15
1class Solution {
2public:
3    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
4          vector<int> x;
5        
6        for (auto &p : points) {
7            x.push_back(p[0]);
8        }
9        
10        sort(x.begin(), x.end());
11        
12        int ans = 0;
13        for (int i = 1; i < x.size(); i++) {
14            ans = max(ans, x[i] - x[i - 1]);
15        }
16        
17        return ans;
18    }
19};