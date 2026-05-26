// Last updated: 26/05/2026, 15:46:19
1class Solution {
2public:
3    int numberOfSpecialChars(string word) {
4        vector<int> small(26, 0), capital(26, 0);
5
6        for(char c : word) {
7            if(islower(c))
8                small[c - 'a'] = 1;
9            else
10                capital[c - 'A'] = 1;
11        }
12
13        int ans = 0;
14
15        for(int i = 0; i < 26; i++) {
16            if(small[i] && capital[i])
17                ans++;
18        }
19
20        return ans;
21    }
22};