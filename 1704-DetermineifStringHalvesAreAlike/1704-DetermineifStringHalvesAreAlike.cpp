// Last updated: 05/05/2026, 07:43:33
1class Solution {
2public:
3    bool isVowel(char c) {
4        c = tolower(c);
5        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
6    }
7    bool halvesAreAlike(string s) {
8        
9        int count = 0;
10        int n = s.length();
11
12        for (int i = 0; i < n / 2; i++) {
13            if (isVowel(s[i])) count++;
14            if (isVowel(s[i + n / 2])) count--;
15        }
16
17        return count == 0;
18    }
19};