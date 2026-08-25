// Last updated: 25/08/2026, 14:57:55
1class Solution {
2public:
3    vector<vector<string>> groupAnagrams(vector<string>& strs) {
4        map<string, vector<string>> mp;
5
6        for (string s : strs) {
7            string key = s;
8            sort(key.begin(), key.end());
9
10            if (key.size() >= 3)
11                swap(key[0], key[1]);
12
13            mp[key].push_back(s);
14        }
15
16        vector<vector<string>> ans;
17
18        for (auto &p : mp)
19            ans.push_back(p.second);
20
21        return ans;
22    }
23};