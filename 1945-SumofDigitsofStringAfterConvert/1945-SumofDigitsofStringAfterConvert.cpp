// Last updated: 08/05/2026, 16:03:59
1class Solution {
2public:
3    char findTheDifference(string s, string t) {
4        int xorValue = 0;
5
6        for(char c : s) {
7            xorValue ^= c;
8        }
9
10        for(char c : t) {
11            xorValue ^= c;
12        }
13
14        return (char)xorValue;
15    }
16};