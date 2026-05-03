// Last updated: 03/05/2026, 11:55:42
1class Solution {
2public:
3    int balancedStringSplit(string s) {
4        int count = 0;
5        int balance = 0;
6
7        for(char c : s) {
8            if(c == 'R') balance++;
9            else balance--;
10
11            if(balance == 0) count++;
12        }
13
14        return count;
15    }
16};