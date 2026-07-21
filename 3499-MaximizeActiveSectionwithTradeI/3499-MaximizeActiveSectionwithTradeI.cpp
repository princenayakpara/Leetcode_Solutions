// Last updated: 21/07/2026, 08:59:49
1class Solution {
2public:
3    int maxActiveSectionsAfterTrade(string s) {
4        int n = s.size();
5        int totalOnes = 0;
6        int prevZero = INT_MIN;
7        int maxGain = 0;
8
9        int i = 0;
10        while (i < n) {
11            int j = i;
12            while (j < n && s[j] == s[i]) j++;
13
14            int len = j - i;
15
16            if (s[i] == '1') {
17                totalOnes += len;
18            } else {
19                maxGain = max(maxGain, prevZero + len);
20                prevZero = len;
21            }
22
23            i = j;
24        }
25
26        return totalOnes + maxGain;
27    }
28};