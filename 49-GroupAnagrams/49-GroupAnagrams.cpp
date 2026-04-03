// Last updated: 03/04/2026, 16:11:10
1class Solution {
2public:
3    vector<vector<string>> groupAnagrams(vector<string>& strs) {
4        unordered_map<string, vector<string>> mp;
5
6        for (string s : strs) {
7            string key = s;
8            sort(key.begin(), key.end()); 
9            mp[key].push_back(s);
10        }
11
12        vector<vector<string>> result;
13        for (auto& s : mp) {
14            result.push_back(s.second);
15        }
16
17        return result;
18    }
19};