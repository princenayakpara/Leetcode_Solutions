// Last updated: 13/06/2026, 11:58:32
1class Solution {
2public:
3    int maxFreqSum(string s) {
4        vector<int> freq(26, 0);
5
6        for (char ch : s) {
7            freq[ch - 'a']++;
8        }
9
10        int maxVowel = 0, maxConsonant = 0;
11
12        for (int i = 0; i < 26; i++) {
13            char ch = 'a' + i;
14
15            if (ch == 'a' || ch == 'e' || ch == 'i' ||
16                ch == 'o' || ch == 'u') {
17                maxVowel = max(maxVowel, freq[i]);
18            } else {
19                maxConsonant = max(maxConsonant, freq[i]);
20            }
21        }
22
23        return maxVowel + maxConsonant;
24    }
25};