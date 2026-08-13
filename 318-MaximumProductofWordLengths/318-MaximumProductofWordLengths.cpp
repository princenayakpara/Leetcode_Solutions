// Last updated: 13/08/2026, 15:22:43
1class Solution {
2public:
3    int maxProduct(vector<string>& words) {
4        int n = words.size();
5        vector<int> res(n, 0);
6        for (int i = 0; i < n; i++) {
7            for (char c : words[i]) {
8                res[i] |= (1 << (c - 'a'));
9            }
10        }
11
12        int ans = 0;
13        for (int i = 0; i < n; i++) {
14            for (int j = i + 1; j < n; j++) {
15                if ((res[i] & res[j]) == 0) {
16                    ans = max(ans, (int)words[i].size() * 
17                                   (int)words[j].size());
18                }
19            }
20        }
21
22        return ans;
23    }
24};