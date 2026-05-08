// Last updated: 08/05/2026, 16:37:22
1class Solution {
2public:
3    string makeFancyString(string s) {
4        string ans;
5
6        for(char c : s) {
7            int n = ans.size();
8
9            if(n >= 2 && ans[n - 1] == c && ans[n - 2] == c)
10                continue;
11
12            ans += c;
13        }
14
15        return ans;
16    }
17};