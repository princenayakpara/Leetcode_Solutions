// Last updated: 27/07/2026, 14:54:38
1class Solution {
2public:
3    int finalElement(vector<int>& nums) {
4       return max(nums[0], nums.back());
5    }
6};