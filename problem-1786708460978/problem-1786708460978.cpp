// Last updated: 14/08/2026, 17:24:20
1class Solution {
2public:
3    int minIncrementForUnique(vector<int>& nums) {
4        sort(nums.begin(), nums.end());
5
6        int steps = 0;
7        int prev = nums[0];
8
9        for (int i = 1; i < nums.size(); i++) {
10            if (nums[i] <= prev) {
11                steps += prev + 1 - nums[i];
12                prev++;
13            } else {
14                prev = nums[i];
15            }
16        }
17        return steps;
18    }
19};