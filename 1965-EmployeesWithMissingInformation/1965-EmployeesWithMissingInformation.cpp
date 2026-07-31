// Last updated: 31/07/2026, 15:38:42
1class Solution {
2public:
3    int atMost(vector<int>& nums, int k) {
4        int left = 0, ans = 0;
5
6        for (int right = 0; right < nums.size(); right++) {
7            if (nums[right] % 2) k--;
8
9            while (k < 0) {
10                if (nums[left] % 2) k++;
11                left++;
12            }
13
14            ans += right - left + 1;
15        }
16
17        return ans;
18    }
19
20    int numberOfSubarrays(vector<int>& nums, int k) {
21        return atMost(nums, k) - atMost(nums, k - 1);
22    }
23};