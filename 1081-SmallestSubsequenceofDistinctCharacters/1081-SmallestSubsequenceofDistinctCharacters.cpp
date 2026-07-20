// Last updated: 20/07/2026, 09:31:27
1class Solution {
2public:
3    string smallestSubsequence(string s) {
4        vector<int> freq(26, 0);
5        vector<bool> vis(26, false);
6
7        for (char c : s)
8            freq[c - 'a']++;
9
10        string st;
11
12        for (char c : s) {
13            freq[c - 'a']--;
14
15            if (vis[c - 'a'])
16                continue;
17
18            while (!st.empty() &&
19                   st.back() > c &&
20                   freq[st.back() - 'a'] > 0) {
21                vis[st.back() - 'a'] = false;
22                st.pop_back();
23            }
24
25            st.push_back(c);
26            vis[c - 'a'] = true;
27        }
28
29        return st;
30    }
31};