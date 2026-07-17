// Last updated: 17/07/2026, 16:27:16
1class Solution {
2public:
3    vector<int> findAnagrams(string s, string p) {
4        vector<int> ans;
5        unordered_map<char, int> pMap;
6
7        if(p.size()>s.size()){
8            return ans;
9        }
10        
11        for (char c : p) {
12            pMap[c]++;
13        }
14        int k = p.size();
15        for (int i = 0; i <= s.size() - k; i++) {
16            unordered_map<char, int> m;
17            for (int j = i; j < i + k; j++) {
18                m[s[j]]++;
19            }
20            if (m == pMap) {
21                ans.push_back(i);
22            }
23        }
24
25        return ans;
26    }
27};