// Last updated: 02/06/2026, 10:42:18
1class Solution {
2public:
3    int calc(vector<int>& s1, vector<int>& d1,
4             vector<int>& s2, vector<int>& d2) {
5        
6        int minEnd = INT_MAX;
7
8        for (int i = 0; i < s1.size(); i++) {
9            minEnd = min(minEnd, s1[i] + d1[i]);
10        }
11
12        int ans = INT_MAX;
13
14        for (int i = 0; i < s2.size(); i++) {
15            ans = min(ans, max(minEnd, s2[i]) + d2[i]);
16        }
17
18        return ans;
19    }
20
21    int earliestFinishTime(vector<int>& landStartTime,
22                           vector<int>& landDuration,
23                           vector<int>& waterStartTime,
24                           vector<int>& waterDuration) {
25
26        int landFirst = calc(landStartTime, landDuration,
27                             waterStartTime, waterDuration);
28
29        int waterFirst = calc(waterStartTime, waterDuration,
30                              landStartTime, landDuration);
31
32        return min(landFirst, waterFirst);
33    }
34};