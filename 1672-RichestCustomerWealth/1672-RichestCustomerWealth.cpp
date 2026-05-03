// Last updated: 03/05/2026, 22:24:31
1class Solution {
2public:
3    int maximumWealth(vector<vector<int>>& accounts) {
4        int maxWealth = 0;
5
6        for(int i = 0; i< accounts.size(); i++){
7            int sum = 0;
8
9            for(int j = 0; j< accounts[i].size(); j++){
10                sum += accounts[i][j];
11            }
12            maxWealth = max(maxWealth, sum);
13        }
14        return maxWealth;
15    }
16};