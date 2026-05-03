// Last updated: 03/05/2026, 15:40:29
1class Solution {
2public:
3    string toLowerCase(string s) {
4        for(int i = 0; i<s.length(); i++){
5            if(s[i]>='A' && s[i]<='Z'){
6                s[i] = s[i] + 32;
7            }
8        }
9        return s;
10    }
11};