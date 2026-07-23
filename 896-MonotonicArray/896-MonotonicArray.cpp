// Last updated: 23/07/2026, 15:58:39
1class Solution {
2public:
3    vector<int> decompressRLElist(vector<int>& nums) {
4        vector<int> ans;
5
6        for (int i = 0; i < nums.size(); i += 2) {
7            int freq = nums[i];
8            int val = nums[i + 1];
9
10            while (freq--) {
11                ans.push_back(val);
12            }
13        }
14
15        return ans;
16    }
17};