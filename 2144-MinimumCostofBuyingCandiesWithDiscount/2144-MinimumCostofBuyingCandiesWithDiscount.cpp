// Last updated: 01/06/2026, 10:20:20
1class Solution {
2public:
3    int minimumCost(vector<int>& cost) {
4        sort(cost.rbegin(), cost.rend());
5
6        int res = 0;
7        for(int i = 0; i<cost.size(); i++){
8            if(i % 3 != 2)res += cost[i];
9        }
10        return res;
11    }
12};