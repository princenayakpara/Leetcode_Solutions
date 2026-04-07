// Last updated: 07/04/2026, 10:35:48
1class Solution {
2public:
3    void moveZeroes(vector<int>& nums) {
4        int j = 0;
5
6        for (int i = 0; i < nums.size(); i++) {
7            if (nums[i] != 0) {
8                nums[j++] = nums[i];
9            }
10        }
11
12        while (j < nums.size()) {
13            nums[j++] = 0;
14        }
15    }
16};