// Last updated: 23/07/2026, 15:08:06
1class Solution {
2public:
3    bool isMonotonic(vector<int>& nums) {
4        bool increasing = true;
5        bool decreasing = true;
6
7        for (int i = 0; i < nums.size()-1; i++) {
8            if (nums[i] > nums[i + 1])
9                decreasing = false;
10            if (nums[i] < nums[i + 1])
11                increasing = false;
12        }
13
14        return increasing || decreasing;
15    }
16};