// Last updated: 17/05/2026, 08:12:22
1class Solution {
2public:
3    bool isAdjacentDiffAtMostTwo(string s) {
4        for(int i = 1; i<s.size(); i++){
5            if(abs(s[i] - s[i - 1])>2) {
6                return false;
7            }
8        }
9        return true;
10    }
11};