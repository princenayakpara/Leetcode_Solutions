// Last updated: 03/05/2026, 10:26:51
1class Solution {
2public:
3    int subtractProductAndSum(int n) {
4        int product = 1;
5        int sum = 0;
6
7        while(n > 0){
8            int digit = n % 10;
9
10            product *= digit;
11            sum += digit;
12
13            n = n / 10;
14        }
15
16        return product - sum;
17    }
18};