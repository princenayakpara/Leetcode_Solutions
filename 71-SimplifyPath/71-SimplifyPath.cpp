// Last updated: 16/06/2026, 14:52:27
1class Solution {
2public:
3    string simplifyPath(string path) {
4        vector<string> st;
5        string res;
6
7        for (int i = 0; i <= path.size(); i++) {
8            if (i == path.size() || path[i] == '/') {
9                if (res == "" || res == ".") {
10                    
11                } 
12                else if (res == "..") {
13                    if (!st.empty()) st.pop_back();
14                } 
15                else {
16                    st.push_back(res);
17                }
18                res.clear();
19            } else {
20                res += path[i];
21            }
22        }
23
24        if (st.empty()) return "/";
25
26        string ans;
27        for (string &dir : st) {
28            ans += "/" + dir;
29        }
30
31        return ans;
32    }
33};