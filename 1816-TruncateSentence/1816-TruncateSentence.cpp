// Last updated: 03/05/2026, 15:23:24
1class Solution {
2public:
3    string truncateSentence(string s, int k) {
4        int spaceCount = 0;
5
6        for (int i = 0; i < s.size(); i++) {
7            if (s[i] == ' ') {
8                spaceCount++;
9                if (spaceCount == k) {
10                    return s.substr(0, i);
11                }
12            }
13        }
14
15        return s; // if k words >= total words
16    }
17};