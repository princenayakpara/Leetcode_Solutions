// Last updated: 21/06/2026, 16:15:58
1class Solution {
2public:
3    int maxIceCream(vector<int>& costs, int coins) {
4        sort(costs.begin(), costs.end());
5
6        int count = 0;
7        for (int cost : costs) {
8            if (coins < cost) break;
9            coins -= cost;
10            count++;
11        }
12
13        return count;
14    }
15};