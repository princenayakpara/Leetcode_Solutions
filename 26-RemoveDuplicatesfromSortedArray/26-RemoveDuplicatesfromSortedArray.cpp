// Last updated: 31/08/2026, 17:10:57
1class Solution {
2public:
3    int maxProfit(vector<int>& prices) {
4        int minPrice= INT_MAX;
5        int maxProfit = 0;
6
7        for(int price : prices){
8          if(price < minPrice){
9            minPrice = price;
10          }
11
12            if(price - minPrice > maxProfit){
13                maxProfit = price - minPrice;
14            }
15        }
16        return maxProfit;
17    }
18};