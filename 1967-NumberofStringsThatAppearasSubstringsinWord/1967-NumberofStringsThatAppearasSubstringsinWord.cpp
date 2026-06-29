// Last updated: 29/06/2026, 21:13:12
1class Solution {
2public:
3    int numOfStrings(vector<string>& patterns, string word) {
4        int count = 0;
5        
6        for (string &p : patterns) {
7            if (word.find(p) != string::npos)
8                count++;
9        }
10        
11        return count;
12    }
13};