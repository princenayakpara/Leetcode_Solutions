// Last updated: 09/05/2026, 02:17:34
1class Solution {
2public:
3    int arrangeCoins(int n) {
4        long long sum = 0;
5        int row = 0;
6
7        while(sum + row + 1 <= n) {
8            row++;
9            sum += row;
10        }
11
12        return row;
13    }
14};