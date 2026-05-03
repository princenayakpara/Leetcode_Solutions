// Last updated: 03/05/2026, 22:34:56
1class Solution {
2public:
3    int singleNumber(vector<int>& nums) {
4        int result = 0;
5
6        for (int num : nums) {
7            result ^= num;
8        }
9
10        return result;
11    }
12};