// Last updated: 14/07/2026, 14:47:09
1class Solution {
2public:
3    int longestOnes(vector<int>& nums, int k) {
4        int n = nums.size();
5        int low = 0;
6        int zeros = 0;
7        int ans = 0;
8
9        for (int high = 0; high < n; high++) {
10
11            if (nums[high] == 0)
12                zeros++;
13
14            while (zeros > k) {
15                if (nums[low] == 0)
16                    zeros--;
17                low++;
18            }
19
20            ans = max(ans, high - low + 1);
21        }
22
23        return ans;
24    }
25};