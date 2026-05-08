// Last updated: 08/05/2026, 16:08:13
1class Solution {
2public:
3    bool detectCapitalUse(string word) {
4        int upper = 0;
5
6        for(char c : word)
7            upper += (isupper(c) ? 1 : 0);
8
9        return upper == word.size() ||
10               upper == 0 ||
11               (upper == 1 && isupper(word[0]));
12    }
13};