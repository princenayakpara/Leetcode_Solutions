// Last updated: 28/07/2026, 15:03:29
1class Solution {
2public:
3    int differenceOfSum(vector<int>& nums) {
4        int elementSum = 0, digitSum = 0;
5
6        for (int num : nums) {
7            elementSum += num;
8
9            int x = num;
10            while (x > 0) {
11                digitSum += x % 10;
12                x /= 10;
13            }
14        }
15
16        return abs(elementSum - digitSum);
17    }
18};