// Last updated: 08/05/2026, 13:32:13
1class Solution {
2public:
3    int getLucky(string s, int k) {
4        string num = "";
5
6        // Convert characters to their alphabet positions
7        for(char c : s) {
8            num += to_string(c - 'a' + 1);
9        }
10
11        int sum = 0;
12
13        // Perform transformation k times
14        while(k--) {
15            sum = 0;
16
17            for(char c : num) {
18                sum += c - '0';
19            }
20
21            num = to_string(sum);
22        }
23
24        return sum;
25    }
26};