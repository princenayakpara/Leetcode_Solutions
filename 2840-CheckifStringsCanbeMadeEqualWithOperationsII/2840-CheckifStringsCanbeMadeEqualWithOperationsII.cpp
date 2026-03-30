// Last updated: 30/03/2026, 14:24:18
1class Solution {
2public:
3    bool checkStrings(string s1, string s2) {
4        string s1_even = "", s1_odd = "";
5        string s2_even = "", s2_odd = "";
6        
7        for (int i = 0; i < s1.size(); i++) {
8            if (i % 2 == 0) {
9                s1_even += s1[i];
10                s2_even += s2[i];
11            } else {
12                s1_odd += s1[i];
13                s2_odd += s2[i];
14            }
15        }
16        
17        sort(s1_even.begin(), s1_even.end());
18        sort(s2_even.begin(), s2_even.end());
19        sort(s1_odd.begin(), s1_odd.end());
20        sort(s2_odd.begin(), s2_odd.end());
21        
22        return s1_even == s2_even && s1_odd == s2_odd;
23    }
24};