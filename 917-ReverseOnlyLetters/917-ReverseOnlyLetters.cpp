// Last updated: 07/05/2026, 22:00:00
1class Solution {
2public:
3    int titleToNumber(string columnTitle) {
4        int result = 0;
5
6        for(char c : columnTitle) {
7            result = result * 26 + (c - 'A' + 1);
8        }
9
10        return result;
11    }
12};