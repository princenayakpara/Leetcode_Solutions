// Last updated: 04/08/2026, 16:22:02
1class Solution {
2public:
3    vector<int> findMissingElements(vector<int>& nums) {
4        vector<int> ans;
5        if (nums.empty()) return ans;
6
7        sort(nums.begin(), nums.end());
8
9        for (int i = 1; i < nums.size(); i++) {
10            int prev = nums[i - 1];
11            int curr = nums[i];
12            if (curr == prev) continue;
13
14            for (int x = prev + 1; x < curr; x++)
15                ans.push_back(x);
16        }
17
18        return ans;
19    }
20};