// Last updated: 30/07/2026, 15:16:15
1class Solution {
2public:
3    int minimumPushes(string word) {
4        int ans = 0;
5
6        for(int i = 0; i<word.size(); i++){
7            ans+=(i/8) + 1;
8        }
9        return ans;
10    }
11};