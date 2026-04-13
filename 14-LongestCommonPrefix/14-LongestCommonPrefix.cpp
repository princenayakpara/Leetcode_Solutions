// Last updated: 13/04/2026, 16:02:42
1class Solution {
2public:
3    string longestCommonPrefix(vector<string>& strs) {
4        if (strs.empty()) return "";
5
6        string prefix = strs[0];
7
8        for (int i = 1; i < strs.size(); i++) {
9            int j = 0;
10
11            while (j < prefix.size() && j < strs[i].size() && prefix[j] == strs[i][j]) {
12                j++;
13            }
14
15            prefix = prefix.substr(0, j);
16
17            if (prefix == "") return "";
18        }
19
20        return prefix;
21    }
22};