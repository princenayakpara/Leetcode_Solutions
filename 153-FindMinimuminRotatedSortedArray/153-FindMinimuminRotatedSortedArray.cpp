// Last updated: 15/05/2026, 09:37:19
1class Solution {
2public:
3    int findMin(vector<int>& nums) {
4        int l = 0, r = nums.size() - 1;
5
6        while (l < r) {
7            int mid = l + (r - l) / 2;
8
9            if (nums[mid] > nums[r]) {
10                l = mid + 1;
11            } else {
12                r = mid;
13            }
14        }
15
16        return nums[l];
17    }
18};