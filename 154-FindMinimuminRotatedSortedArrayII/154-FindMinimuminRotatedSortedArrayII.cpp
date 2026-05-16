// Last updated: 16/05/2026, 16:35:24
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
11            }
12            else if (nums[mid] < nums[r]) {
13                r = mid;
14            }
15            else {
16                r--;
17            }
18        }
19
20        return nums[l];
21    }
22};