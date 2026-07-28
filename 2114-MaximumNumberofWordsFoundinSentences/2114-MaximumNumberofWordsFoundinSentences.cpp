// Last updated: 28/07/2026, 14:57:09
1class Solution {
2public:
3    int mostWordsFound(vector<string>& sentences) {
4        int maxWord = 0;
5
6        for (int i = 0; i < sentences.size(); i++) {
7            int count = 1;
8
9            for (int j = 0; j < sentences[i].size(); j++) {
10                if (sentences[i][j] == ' ') {
11                    count++;
12                }
13            }
14
15            maxWord = max(maxWord, count);
16        }
17
18        return maxWord;
19    }
20};