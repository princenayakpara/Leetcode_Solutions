// Last updated: 16/05/2026, 17:45:20
1class Solution {
2public:
3    bool wordPattern(string pattern, string s) {
4        vector<string> words;
5        string temp;
6
7        stringstream ss(s);
8
9        while (ss >> temp) {
10            words.push_back(temp);
11        }
12
13        if (pattern.size() != words.size()) {
14            return false;
15        }
16
17        unordered_map<char, string> mp1;
18        unordered_map<string, char> mp2;
19
20        for (int i = 0; i < pattern.size(); i++) {
21            char c = pattern[i];
22            string w = words[i];
23
24            if (mp1.count(c) && mp1[c] != w) {
25                return false;
26            }
27
28            if (mp2.count(w) && mp2[w] != c) {
29                return false;
30            }
31
32            mp1[c] = w;
33            mp2[w] = c;
34        }
35
36        return true;
37    }
38};