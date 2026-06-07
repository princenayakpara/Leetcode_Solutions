// Last updated: 07/06/2026, 10:25:52
1class Solution {
2public:
3    char repeatedCharacter(string s) {
4        bool seen[26]={false};
5        for(char c : s){
6            if(seen[c-'a'])return c;
7            seen[c-'a']= true;
8        }
9        return ' ';
10    }
11};