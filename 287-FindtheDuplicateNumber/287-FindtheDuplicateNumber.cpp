// Last updated: 17/07/2026, 15:51:36
1class Solution {
2public:
3    int findDuplicate(vector<int>& nums) {
4        int i = 0;
5        for(; i < nums.size(); i++){
6            int idx = abs(nums[i]);
7            if(nums[idx] < 0) break;
8            nums[idx] *= -1;
9        }
10        return abs(nums[i]);
11    }
12};