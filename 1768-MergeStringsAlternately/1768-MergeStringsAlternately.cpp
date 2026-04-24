// Last updated: 24/04/2026, 10:06:50
1class Solution {
2public:
3    string mergeAlternately(string word1, string word2) {
4        string result = "";
5        int i = 0, j = 0;
6
7         while (i < word1.size() && j < word2.size()) {
8            result += word1[i++];
9            result += word2[j++];
10        }
11
12         while (i < word1.size()) {
13            result += word1[i++];
14        }
15
16         while (j < word2.size()) {
17            result += word2[j++];
18         }
19
20         return result;
21    }
22};