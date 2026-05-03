// Last updated: 03/05/2026, 11:49:08
1class Solution {
2public:
3    int minimumSum(int num) {
4       vector<int> digits;
5
6       while(num > 0) {
7            digits.push_back(num % 10);
8            num /= 10;
9        }
10
11        sort(digits.begin(), digits.end());
12
13        return (digits[0]*10 + digits[2]) + (digits[1]*10 + digits[3]);
14    }
15};