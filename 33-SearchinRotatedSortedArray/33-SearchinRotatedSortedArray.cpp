// Last updated: 22/05/2026, 00:05:21
1class Solution {
2public:
3    int singleNumber(vector<int>& nums) {
4        if(nums.size() == 1) return nums[0];
5        sort(nums.begin(), nums.end());
6        if(nums[0] != nums[1]){
7            return nums[0];
8        }
9        if(nums[nums.size() - 1]!= nums[nums.size() -2]){
10            return nums[nums.size() - 1];
11        }
12        for(int i = 0; i< nums.size() - 1; i++){
13            if(nums[i] == nums[i+1] || nums[i] == nums[i-1]){
14                continue;
15            }
16            else{
17                return nums[i];
18            }
19        }
20        return -1;
21    }
22};