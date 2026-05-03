// Last updated: 03/05/2026, 15:29:58
1class Solution {
2public:
3    bool checkIfPangram(string sentence) {
4        unordered_set<char> sen;
5
6        for (char c : sentence) {
7            sen.insert(c);
8        }
9
10        return sen.size() == 26;
11    }
12};