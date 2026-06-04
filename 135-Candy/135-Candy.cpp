// Last updated: 04/06/2026, 17:30:59
1class Solution {
2public:
3    int candy(vector<int>& ratings) {
4        int n = ratings.size();
5
6        vector<int> candies(n, 1);
7
8        // Left to Right
9        for (int i = 1; i < n; i++) {
10            if (ratings[i] > ratings[i - 1]) {
11                candies[i] = candies[i - 1] + 1;
12            }
13        }
14
15        // Right to Left
16        for (int i = n - 2; i >= 0; i--) {
17            if (ratings[i] > ratings[i + 1]) {
18                candies[i] = max(candies[i], candies[i + 1] + 1);
19            }
20        }
21
22        int total = 0;
23        for (int c : candies) {
24            total += c;
25        }
26
27        return total;
28    }
29};