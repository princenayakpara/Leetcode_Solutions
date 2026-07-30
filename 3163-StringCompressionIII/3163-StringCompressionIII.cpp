// Last updated: 30/07/2026, 15:09:21
1class Solution {
2public:
3    string compressedString(string word) {
4        string ans;
5        int n = word.size();
6
7        int i = 0;
8        while (i < n) {
9            char ch = word[i];
10            int count = 0;
11
12            while (i < n && word[i] == ch && count < 9) {
13                count++;
14                i++;
15            }
16
17            ans += to_string(count);
18            ans += ch;
19        }
20
21        return ans;
22    }
23};