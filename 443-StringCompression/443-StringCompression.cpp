// Last updated: 30/07/2026, 10:28:24
1class Solution {
2public:
3    int compress(vector<char>& chars) {
4        int n = chars.size();
5        int idx = 0;   
6        int i = 0;     
7
8        while (i < n) {
9            char curr = chars[i];
10            int count = 0;
11
12            while (i < n && chars[i] == curr) {
13                i++;
14                count++;
15            }
16
17            chars[idx++] = curr;
18
19            if (count > 1) {
20                string s = to_string(count);
21                for (char c : s) {
22                    chars[idx++] = c;
23                }
24            }
25        }
26
27        return idx;
28    }
29};