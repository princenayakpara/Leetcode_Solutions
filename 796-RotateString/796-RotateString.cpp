// Last updated: 03/05/2026, 11:52:42
1class Solution {
2public:
3    bool rotateString(string s, string goal) {
4        if(s.length() != goal.length()) return false;
5        return (s + s).find(goal) != string::npos;
6    }
7};