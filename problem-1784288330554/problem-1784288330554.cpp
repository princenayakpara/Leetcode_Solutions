// Last updated: 17/07/2026, 17:08:50
1class Solution {
2public:
3    long long maximumSubarraySum(vector<int>& nums, int k) {
4        unordered_map<int, int> freq;
5        long long sum = 0, ans = 0;
6
7        for (int i = 0; i < nums.size(); i++) {
8            sum += nums[i];
9            freq[nums[i]]++;
10
11            if (i >= k) {
12                sum -= nums[i - k];
13                if (--freq[nums[i - k]] == 0)
14                    freq.erase(nums[i - k]);
15            }
16
17            if (i >= k - 1 && freq.size() == k) {
18                ans = max(ans, sum);
19            }
20        }
21
22        return ans;
23    }
24};