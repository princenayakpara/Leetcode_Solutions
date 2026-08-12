// Last updated: 13/08/2026, 00:43:55
1class Solution {
2public:
3    int maxSubarrayLength(vector<int>& nums, int k) {
4        unordered_map<int, int> freq;
5        int left = 0;
6        int ans = 0;
7
8        for (int right = 0; right < nums.size(); right++) {
9            freq[nums[right]]++;
10
11            while (freq[nums[right]] > k) {
12                freq[nums[left]]--;
13                left++;
14            }
15
16            ans = max(ans, right - left + 1);
17        }
18
19        return ans;
20    }
21};