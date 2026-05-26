// Last updated: 27/05/2026, 02:34:50
1class Solution {
2public:
3    bool halvesAreAlike(string s) {
4    string vowels = "aeiouAEIOU";
5    int n = s.size()/2;
6    int count = 0;
7
8    for(int i = 0; i<n; i++){
9        if(vowels.find(s[i]) != string::npos)count++;
10        if(vowels.find(s[n+i]) != string::npos)count--;
11    }
12    return count == 0;
13    }
14};