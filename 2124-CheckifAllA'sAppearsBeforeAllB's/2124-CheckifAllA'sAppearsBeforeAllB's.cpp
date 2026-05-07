// Last updated: 07/05/2026, 17:12:48
1class Solution {
2public:
3    bool checkString(string s) {
4        bool foundB = false;
5
6        for(char c : s) {
7            if(c == 'b') {
8                foundB = true;
9            }
10            else if(c == 'a' && foundB) {
11                return false;
12            }
13        }
14
15        return true;
16    }
17};