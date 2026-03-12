// Last updated: 12/03/2026, 11:21:01
1class Solution {
2public:
3    int maxProfit(vector<int>& prices) {
4        int minPrice = INT_MAX;
5        int maxProfit = 0;
6        for (int price : prices) {
7            if (price < minPrice) {
8                minPrice = price;
9            }
10            else if (price - minPrice > maxProfit) {
11                maxProfit = price - minPrice;
12            }
13        }
14
15        return maxProfit;
16      
17    }
18};