// Last updated: 07/07/2026, 18:37:09
1class Solution {
2public:
3    vector<int> sortedSquares(vector<int>& nums) {
4         for(int i = 0; i<nums.size(); i++){
5            nums[i] = nums[i] * nums[i];
6         }
7
8         sort(nums.begin(), nums.end());
9
10         return nums;
11    }
12};