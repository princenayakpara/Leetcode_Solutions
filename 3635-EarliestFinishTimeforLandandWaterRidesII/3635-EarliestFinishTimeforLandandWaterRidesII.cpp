// Last updated: 03/06/2026, 10:45:23
1class Solution {
2public:
3    int calc(vector<int>& start1, vector<int>& dur1,
4             vector<int>& start2, vector<int>& dur2) {
5        
6        int firstFinish = INT_MAX;
7
8        for (int i = 0; i < start1.size(); i++) {
9            firstFinish = min(firstFinish, start1[i] + dur1[i]);
10        }
11
12        int ans = INT_MAX;
13
14        for (int i = 0; i < start2.size(); i++) {
15            ans = min(ans,
16                      max(firstFinish, start2[i]) + dur2[i]);
17        }
18
19        return ans;
20    }
21
22    int earliestFinishTime(vector<int>& landStartTime,
23                           vector<int>& landDuration,
24                           vector<int>& waterStartTime,
25                           vector<int>& waterDuration) {
26
27        int landFirst = calc(landStartTime, landDuration,
28                             waterStartTime, waterDuration);
29
30        int waterFirst = calc(waterStartTime, waterDuration,
31                              landStartTime, landDuration);
32
33        return min(landFirst, waterFirst);
34    }
35};