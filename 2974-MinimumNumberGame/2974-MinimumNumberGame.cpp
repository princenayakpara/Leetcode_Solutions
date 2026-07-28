// Last updated: 28/07/2026, 14:44:01
1class Solution {
2public:
3    vector<int> numberGame(vector<int>& nums) {
4        int n = nums.size();
5        sort(nums.begin(), nums.end());
6
7        for(int i = 0; i<n; i+=2){
8            swap(nums[i], nums[i+1]);
9        }
10        return nums;
11    }
12};