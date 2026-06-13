// Last updated: 13/06/2026, 13:17:24
1class Solution {
2public:
3    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
4        vector<int> ans;
5
6        for(int i = 0; i < nums.size(); i++) {
7            int count = 0;
8
9            for(int j = 0; j < nums.size(); j++) {
10                if(nums[j] < nums[i]) {
11                    count++;
12                }
13            }
14
15            ans.push_back(count);
16        }
17
18        return ans;
19    }
20};