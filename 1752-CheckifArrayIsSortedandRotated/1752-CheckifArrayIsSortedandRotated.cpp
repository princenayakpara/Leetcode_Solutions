// Last updated: 23/05/2026, 16:02:18
1class Solution {
2public:
3    bool check(vector<int>& nums) {
4        int n = nums.size();
5        int count = 0;
6
7        for (int i = 0; i < n; i++) {
8            if (nums[i] > nums[(i + 1) % n]) {
9                count++;
10            }
11        }
12
13        return count <= 1;
14    }
15};