// Last updated: 16/06/2026, 13:06:40
1class Solution {
2public:
3    string processStr(string s) {
4        string result;
5
6        for (char c : s) {
7            if (c >= 'a' && c <= 'z') {
8                result.push_back(c);
9            } 
10            else if (c == '*') {
11                if (!result.empty()) {
12                    result.pop_back();
13                }
14            } 
15            else if (c == '#') {
16                result += result;
17            } 
18            else if (c == '%') {
19                reverse(result.begin(), result.end());
20            }
21        }
22
23        return result;
24    }
25};