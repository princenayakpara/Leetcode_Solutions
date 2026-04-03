// Last updated: 03/04/2026, 15:27:09
1class Solution {
2public:
3    vector<int> twoSum(vector<int>& nums, int target) {
4        unordered_map<int, int> mp; 
5        
6        for (int i = 0; i < nums.size(); i++) {
7            int diff = target - nums[i];
8            
9            
10            if (mp.find(diff) != mp.end()) {
11                return {mp[diff], i};
12            }
13            
14            mp[nums[i]] = i;
15        }
16        
17        return {}; 
18    }
19};