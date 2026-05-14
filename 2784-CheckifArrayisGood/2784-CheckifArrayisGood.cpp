// Last updated: 14/05/2026, 14:08:30
1class Solution {
2public:
3    bool isGood(vector<int>& nums) {
4        int n = nums.size();
5        
6        sort(nums.begin(), nums.end());
7        
8        for (int i = 0; i < n - 1; i++) {
9            if (nums[i] != i + 1)
10                return false;
11        }
12        
13        return nums[n - 1] == n - 1;
14    }
15};