// Last updated: 10/03/2026, 13:48:59
1class Solution {
2public:
3    int minPartitions(string n) {
4        int mx = 0;
5
6        for(char c : n){
7            mx = max(mx, c - '0');
8        }
9
10        return mx;
11    }
12};