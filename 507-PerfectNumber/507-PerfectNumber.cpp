// Last updated: 18/05/2026, 17:16:47
1class Solution {
2public:
3    int firstMissingPositive(vector<int>& nums) {
4        int n = nums.size();
5
6        for(int i = 0; i < n; i++) {
7            while(nums[i] > 0 && nums[i] <= n &&
8                  nums[i] != nums[nums[i] - 1]) {
9                swap(nums[i], nums[nums[i] - 1]);
10            }
11        }
12
13        for(int i = 0; i < n; i++) {
14            if(nums[i] != i + 1) {
15                return i + 1;
16            }
17        }
18
19        return n + 1;
20    }
21};